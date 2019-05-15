#pragma once

#include "chattingclient.h"

const int ChattingClient::MAXSTRLEN = 255;

ChattingClient::ChattingClient(MainWindow& mainWindow ,const char *ip, int port) {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    this->client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (this->client_socket == INVALID_SOCKET) {
        throw ChatException(1000);
        WSACleanup();
    }
    //mainwindow = mainwindow
    mainwindow = &mainWindow;
    memset(&this->server_address, 0, sizeof(this->server_address));
    this->server_address.sin_addr.S_un.S_addr = inet_addr(ip);
    this->server_address.sin_port = htons(port);
    this->server_address.sin_family = AF_INET;
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

void ChattingClient::RedirectConnection(const char *ip, int port, int numS515)
{
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    std::cout << "prev_recv_redirect socket : " << client_socket << std::endl;

    shutdown(this->client_socket, SD_SEND);
    this->client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (this->client_socket == INVALID_SOCKET) {
        throw ChatException(1000);
        WSACleanup();
    }
    std::cout << "recv_redirect socket : " << client_socket << std::endl;

    memset(&this->server_address, 0, sizeof(this->server_address));
    this->server_address.sin_addr.S_un.S_addr = inet_addr(ip);
    this->server_address.sin_port = htons(port);
    this->server_address.sin_family = AF_INET;
    //this->st->RedirectSocket(this->client_socket);
    //(*st.RedirectSocket(this->client_socket);
    connectServer();

    //send SIGNAL to mainWindow
    mainwindow->setNum(numS515);
    mainwindow->changeIndex(1, numS515);


}

void ChattingClient::connectServer()
{
    if (connect(this->client_socket, (SOCKADDR*)&this->server_address, sizeof(this->server_address)) == SOCKET_ERROR) {
        throw ChatException(1001);
    }
}

void ChattingClient::sendMessage(std::string message)
{
    std::cout<<"in sendMessage"<<std::endl;

    this->st = new SendThread(client_socket, getChattingClient(), message);
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

int SendRecvInterface::recvMessage(SOCKET socket, char *buf) {
    Message msg;
    int len = 0;
    memset(&msg, 0, sizeof(Message));
    std::cout << socket << std::endl;
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
        std::cout << "socket error" << std::endl;
        return -1;
    }
    return 0;
}

SendThread::SendThread(SOCKET cs, ChattingClient& cc, std::string param_message) : client_socket(cs), chatting_client(cc), message(param_message)
{
    std::cout<<"Address ChattingClient in ST: "<<&cc<<std::endl;
}

void SendThread::RedirectSocket(SOCKET sock)
{
    if(client_socket != sock)
    {
        std::cout << "send_redirect!" << std::endl;
        client_socket = sock;
    }
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
        std::cout<<"in sendThread run function"<<std::endl;
        const char* message = this->message.c_str();
        if (exitUser(message)) {
            throw ChatException(2100);
        }

        std::cout <<"ST run before Redirection: "<<this->client_socket<<std::endl;

        // if message correct
        if (sendMessage(this->client_socket, message) < 0)
        {
            std::cout<<"====Redirection===="<<message<<std::endl;
            //std::cout << "send_redirect socket : " << chatting_client.getClientSocket() << std::endl;
            std::cout <<"ST run before Redirection in if loop: "<<this->client_socket<<std::endl;
            RedirectSocket(chatting_client.getClientSocket());
        }
        else
        {
            std::cout<<"message sent to Sock: " <<this->client_socket<<"\nMessage: " <<message<< "send to Server" <<std::endl;
        }
    }
    catch (ChatException e) {
        std::cout<<"in catch func"<<std::endl;
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
    std::cout<<"Address ChattingClient in RT: "<<&cc<<std::endl;
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
                std::cout<<"json:===="<<JsonToMessage<<std::endl;

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

                        int numS515 = JsonToMessage["numS515"].asInt();
                        std::cout<<"numS515: "<<numS515<<std::endl;
                        chatting_client.RedirectConnection(ip, port, numS515);

                        //** edit
                    }
                    else {
                        std::cout<<"in false loop"<<std::endl;
                    }
                    break;
                }
                case MessageType::TEXT_MESSAGE:
                {
                    //cout << JsonToMessage["id"] << " : " << JsonToMessage["text"] << endl;
                    break;
                }

                case MessageType::NEW_ACCOUNT:



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
