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
    // this need to be changed
    // get db info from previous page
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");            //temp local host
    db.setUserName("root");                 //db user name
    db.setPassword("root");                 //db pw
    db.setDatabaseName("student_qt");              //db name

    if(db.open()) {
        cout<<"db opend"<<endl;
        // ***ji hyuk: need Query for password check

    }
    else {
        cout<<"db not opened"<<endl;
    }
}
