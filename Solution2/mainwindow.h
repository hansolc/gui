#pragma once

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "chattingclient.h"
#include "registration.h"
#include "makeroom.h"
#include <QMainWindow>
#include <gthread.h>
#include <QListWidget>
#include "json.h"

class ChattingClient;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
//    Json::Value root;
//    Json::FastWriter fastWriter;
//    std::string str;
    ~MainWindow();

private slots:
    void on_Button_register_clicked();
    void on_Button_login_2_clicked();
    void on_Button_makeRoom_clicked();
    void on_Button_toHome_clicked();
    void on_send_clicked();
    void btn_515_clicked();
    void btn_516_clicked();
    void btn_517_clicked();

public slots:
    void changeStack(int index, int numS1);
    void changeStackToC1();
    void setNum(int updateStudnet);
    int getNum() const {return numS515;}

private:
    Ui::MainWindow *ui;
    ChattingClient *chattingClient;
    Registration *regis_window;
    MakeRoom *makeRoom;
    GThread *gThread;
    int currentIndex;
    QListWidgetItem* item;
    int numS515;

    //for table widget
    enum Columns
    {
        ROOMNUM, SUBJECT, STUDENTNUM, BUTTON

    };

signals:
    void changeIndex(int index, int numS);
    void numChanged(int newNum);
};

#endif // MAINWINDOW_H
