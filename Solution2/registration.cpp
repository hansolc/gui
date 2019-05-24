#include "registration.h"
#include "ui_registration.h"
#include <iostream>
#include <QMessageBox>
#include "json.h"
#include "chattingclient.h"

using namespace std;

Registration::Registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
    ui->lineEdit_id_2_reg->setPlaceholderText("put you id here");
    ui->lineEdit_pw_2_reg->setPlaceholderText("put you pw here");

}

Registration::~Registration()
{
    delete ui;
}

void Registration::on_Button_register_reg_clicked()
{
    //here about db
    Json::Value root;
    Json::FastWriter fastWriter;
    std::string str;

    root["type"] = MessageType::NEW_ACCOUNT;
    root["id"] = ui->lineEdit_id_2_reg->text().toStdString();
    root["password"] = ui->lineEdit_pw_2_reg->text().toStdString();

    str = fastWriter.write(root);
    this->chattingClient->sendMessage(str);
}
