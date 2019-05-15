#include "makeroom.h"
#include "ui_makeroom.h"
#include <iostream>

using namespace std;


MakeRoom::MakeRoom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MakeRoom)
{
    ui->setupUi(this);
}

MakeRoom::~MakeRoom()
{
    delete ui;
}

void MakeRoom::on_pushButton_makeRoom_clicked()
{
    accept();
}

void MakeRoom::on_pushButton_close_clicked()
{
    reject();
}

QString MakeRoom::subject() const
{
    return ui->lineEdit_subject->text();
}

//int MakeRoom::numStudent() const
//{
//    return ui->numStudent->value();
//}

QString MakeRoom::roomNumber() const
{
    return ui->lineEdit_room->text();
}

void MakeRoom::getNum(int numStudent)
{
    this->numStudent = numStudent;
}

int MakeRoom::setNum()
{
    return this->numStudent;
}
