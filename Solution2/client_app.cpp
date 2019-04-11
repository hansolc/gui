#pragma once

#include "client_App.h"

client_App::client_App() : serverport(0) {
    memset(serverip, 0, sizeof(serverip));
}

client_App::~client_App() {
    delete chattingclient;
}

DWORD client_App::run(void)
{
    printStart();
    char buf[16] = "127.0.0.1";
    int port = 3490;

    sprintf(this->serverip, "%s", buf);
    this->serverport = port;

    chattingclient = new ChattingClient(this->serverip, this->serverport);
    chattingclient->start();
    chattingclient->join();
    return 0;
}

void client_App::printStart() {
    cout << "======== CLIENT PROGRAM ========\n";
}

void client_App::printExit() {
    cout << "The connection to the server has been terminated." << endl;
}
void client_App::printError() {
    cout << "The server is disconnected." << endl;
}

void client_App::sendMessage(std::string message){
    chattingclient->sendMessage(message);
}
