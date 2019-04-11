#pragma once

#ifndef __APP_CONF__
#define __APP_CONF__

#include <iostream>
#include "ChattingClient.h"
#include <Windows.h>

using std::cout;
using std::cin;
using std::endl;

namespace MessageType
{
enum Type { LOGIN_PASS = 1, TEXT_MESSAGE = 2, ENTERROOM_REQUSET = 3 };
}

class client_App : public CThread {
private:
    char serverip[16];
    int serverport;
    ChattingClient *chattingclient;

public:
    client_App();
    ~client_App();

    void printStart();
    void printExit();
    void printError();
    virtual DWORD run(void);
    void sendMessage(std::string);
};

#endif
