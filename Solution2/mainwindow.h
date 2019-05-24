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
#include <iostream>

class ChattingClient;
class Registration;

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
    Registration *regis_window;
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

    void on_send_516_clicked();

    void on_send_517_clicked();

public slots:
    void changeStack(int index);
    void changeStackToC1();
    void setNum(QString updateStudnet, QString updateStudnet516, QString updateStudnet517);
    QString getNum();
    void regisSlot();
    void printMessage(QString msg);
    void printMessage516(QString msg);
    void printMessage517(QString msg);


private:
    Ui::MainWindow *ui;
    ChattingClient *chattingClient;
    GThread *gThread;
    int currentIndex;
    QListWidgetItem* item;
    QString numS515;
    QString numS516;
    QString numS517;
    int count515;
    int count516;
    int count517;

    //for table widget
    enum Columns
    {
        ROOMNUM, SUBJECT, STUDENTNUM, BUTTON

    };

signals:
    void changeIndex(int index);
    void numChanged(QString newNum, QString newNum516, QString newNum517);
    void regisSignal();
    void showMessage(QString msg);
    void showMessage516(QString msg);
    void showMessage517(QString msg);
};

#endif // MAINWINDOW_H
