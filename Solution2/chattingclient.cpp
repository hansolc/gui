#pragma once

#include "chattingclient.h"
#include <typeinfo>

const int ChattingClient::MAXSTRLEN = 255;
SOCKET temp;

ChattingClient::ChattingClient(MainWindow& mainWindow ,const char *ip, int port) {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    this->client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (this->client_socket == INVALID_SOCKET) {
        throw ChatException(1000);
        WSACleanup();
    }

    mainwindow = &mainWindow;
    memset(&this->server_address, 0, sizeof(this->server_address));
    this->server_address.sin_addr.S_un.S_addr = inet_addr(ip);
    this->server_address.sin_port = htons(port);
    this->server_address.sin_family = AF_INET;

    //login-server socket
    temp = this->client_socket;

}

ChattingClient::~ChattingClient() {
    closesocket(this->client_socket);
    delete this->st;
    delete this->rt;
    WSACleanup();
}

ChattingClient& ChattingClient::getChattingClient()
{
    return *this;
}

SOCKET& ChattingClient::getClientSocket()
{
    return this->client_socket;
}

void ChattingClient::RedirectConnection(const char *ip, int port, QString numS515, QString numS516, QString numS517)
{
    std::cout<<"in RedirectConnection"<<std::endl;
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    shutdown(this->client_socket, SD_SEND);
    this->client_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (this->client_socket == INVALID_SOCKET) {
        throw ChatException(1000);
        WSACleanup();
    }

    memset(&this->server_address, 0, sizeof(this->server_address));
    this->server_address.sin_addr.S_un.S_addr = inet_addr(ip);
    this->server_address.sin_port = htons(port);
    this->server_address.sin_family = AF_INET;

    //socket save
    temp = this->client_socket;

    connectServer();

    std::cout<<"before signal"<<std::endl;

    //send SIGNAL to mainWindow
    mainwindow->numChanged(numS515, numS516, numS517);
    mainwindow->changeIndex(1);


}

void ChattingClient::connectServer()
{
    if (connect(this->client_socket, (SOCKADDR*)&this->server_address, sizeof(this->server_address)) == SOCKET_ERROR) {
        std::cout<<"connectServer() error occur"<<std::endl;
        throw ChatException(1001);
    }
}

void ChattingClient::sendMessage(std::string message)
{
    this->st = new SendThread(this->client_socket, getChattingClient(), message);
    //st->RedirectSocket(this->client_socket);
    st->start();
    st->join();
}

DWORD ChattingClient::run(void)
{
    connectServer();
    this->rt = new RecvThread(this->client_socket, getChattingClient());
    rt->start();
    rt->join();
    return st->getExitCode();
}

void ChattingClient::regisSuccess()
{
    mainwindow->regisSignal();
}

void ChattingClient::printMessage(QString msg)
{
    std::cout<<"in printMessage"<<std::endl;
    mainwindow->showMessage(msg);
}

void ChattingClient::printMessage516(QString msg)
{
    mainwindow->showMessage516(msg);
}

void ChattingClient::printMessage517(QString msg)
{
    mainwindow->showMessage517(msg);
}

int SendRecvInterface::recvMessage(SOCKET socket, char *buf) {
    Message msg;
    int len = 0;
    memset(&msg, 0, sizeof(Message));
    if (recv(socket, (char*)&msg, sizeof(Message), 0) <= 0) {
        return -1;
    }
    len = strnlen(msg.data, ChattingClient::MAXSTRLEN);
    strncpy(buf, msg.data, len);
    buf[len] = 0;
    return 0;
}

int SendRecvInterface::sendMessage(SOCKET socket, const char *buf) {
    Message msg;
    memset(&msg, 0, sizeof(Message));

    if (buf != nullptr) {
        int len = strnlen(buf, ChattingClient::MAXSTRLEN);
        strncpy(msg.data, buf, len);
        msg.data[len] = 0;
    }
    if (send(socket, (const char*)&msg, sizeof(Message), 0) == SOCKET_ERROR)
    {
        std::cout<<WSAGetLastError()<<std::endl;
        return -1;
    }
    return 0;
}

SendThread::SendThread(SOCKET cs, ChattingClient& cc, std::string param_message) : client_socket(cs), chatting_client(cc), message(param_message)
{
    //hs modify part 190523
    if(cs != temp) {
        client_socket = temp;
    }
}

//hs modify part===============
//about error 10058
void SendThread::RedirectSocket(SOCKET sock)
{
    //here***
    std::cout<<"shared-resource socket: "<< temp << "\nparameter sock: "<< sock<< std::endl;
    if(temp != sock)
    {
        std::cout << "send_redirect!" << std::endl;
        client_socket = temp;
    }
    this->run();
}

//std::string SendThread::ConvertMessageToJson()
//{
//    int input;
//    Json::Value root;
//    Json::FastWriter fastWriter;
//    std::string str;

//    switch (input)
//    {
//    case MessageType::LOGIN_PASS:
//    {
//        // summery : Client -> LoginServer 전송하기 이전에 메세지 Json Formatting.
//        std::string buf;
//        cout << "LOG-IN || ID : ";
//        cin.clear();
//        cin.ignore();
//        cin >> buf;
//        root["type"] = MessageType::LOGIN_PASS;
//        root["id"] = buf;
//        str = fastWriter.write(root);
//        return str;
//    }
//    case MessageType::TEXT_MESSAGE:
//    {
//        std::string buf;
//        cout << "MESSAGE || INPUT : ";
//        cin.clear();
//        cin.ignore();
//        cin >> buf;
//        root["type"] = MessageType::TEXT_MESSAGE;
//        root["text"] = buf;
//        str = fastWriter.write(root);
//        return str;
//    }
//    case MessageType::ENTERROOM_REQUSET:
//    {
//        cout << "ENTER THE ROOM." << endl;
//        root["type"] = MessageType::ENTERROOM_REQUSET;
//        str = fastWriter.write(root);
//        return str;
//    }
//    default:
//        return nullptr;
//    }
//}

DWORD SendThread::run(void) {
    try {
        const char* message = this->message.c_str();
        if (exitUser(message)) {
            throw ChatException(2100);
        }

        // part1
        if (sendMessage(this->client_socket, message) < 0)
        {
//            chatting_client = chatting_client.getChattingClient();
//            RedirectSocket(chatting_client.getClientSocket());
//            std::cout <<"ST after RedirectSocket: "<<this->client_socket<<std::endl;
        }
        else
        {
            std::cout<<"message sent to Sock: " <<this->client_socket<<"\nMessage: " <<message<< "send to Server" <<std::endl;
        }
    }
    catch (ChatException e) {
        closesocket(this->client_socket);
    }
}

bool SendThread::exitUser(const char *buf) {
    if (stricmp(buf, UserCommand::EXIT) == 0) {
        return true;
    }
    return false;
}

RecvThread::RecvThread(SOCKET cs, ChattingClient& cc) : client_socket(cs), chatting_client(cc) {

}

void RecvThread::RedirectSocket(SOCKET sock)
{
    client_socket = sock;
}

Json::Value RecvThread::ParseMessage(std::string message)
{
    // summery : LoginServer -> Client 메세지를 Json Parsing.
    Json::Reader reader;
    Json::Value root;
    reader.parse(message, root);
    return root;
}


DWORD RecvThread::run(void) {
    char buf[ChattingClient::MAXSTRLEN];
    while (true) {
        try {
            if (recvMessage(this->client_socket, buf) >= 0)
            {
                std::string message(buf);
                Json::Value JsonToMessage = ParseMessage(message);

                switch (JsonToMessage["type"].asInt())
                {
                case MessageType::LOGIN_PASS:
                {
                    if (JsonToMessage["pass"].asBool() == true)
                    {
                        std::string temp(JsonToMessage["ip"].asString());
                        std::vector<char> writable(temp.begin(), temp.end());
                        writable.push_back('\0');

                        char* ip = &writable[0];
                        int port = JsonToMessage["port"].asInt();

                        QString numS515 = QString::fromStdString(JsonToMessage["numS515"].asString());
                        QString numS516 = QString::fromStdString(JsonToMessage["numS516"].asString());
                        QString numS517 = QString::fromStdString(JsonToMessage["numS517"].asString());

                        std::cout<<"JsonToMessage: "<<JsonToMessage<<std::endl;

                        chatting_client.RedirectConnection(ip, port, numS515, numS516, numS517);

                        //** edit
                    }
                    else {
                        //maybe log out??
                        //HWS, JJH
                    }
                    break;
                }
                case MessageType::TEXT_MESSAGE:
                {
                    std::cout<<"message recevied froms server: "<<JsonToMessage<<std::endl;
                    if(JsonToMessage["room"].asString() == "515")
                    {
                        QString msg = QString::fromStdString(JsonToMessage["text"].asString());
                        chatting_client.printMessage(msg);
                        break;
                    }

                    else if (JsonToMessage["room"].asString() == "516")
                    {
                        QString msg = QString::fromStdString(JsonToMessage["text"].asString());
                        chatting_client.printMessage516(msg);
                        break;
                    }

                    else if (JsonToMessage["room"].asString() == "517")
                    {
                        QString msg = QString::fromStdString(JsonToMessage["text"].asString());
                        chatting_client.printMessage517(msg);
                        break;
                    }
                    else
                    {
                        std::cout<<"Room Number Error"<<std::endl;
                    }


                }

                //registration
                case MessageType::NEW_ACCOUNT:
                    if (JsonToMessage["pass"].asBool() == true)
                    {
                        chatting_client.regisSuccess();
                    }
                default:
                    break;
                }
            }
            else // 리디렉션 예외가 발생했을 경우
            {
                //cout << "log-in server connection redirects to main server socket." << endl;
                RedirectSocket(chatting_client.getClientSocket());
            }
        }
        catch (ChatException e) {
            closesocket(this->client_socket);
            break;
        }
    }
    return 0;
}
