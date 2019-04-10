#include "registration.h"
#include "ui_registration.h"
#include <iostream>
#include <QMessageBox>

using namespace std;

Registration::Registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
    ui->lineEdit_id->setPlaceholderText("put you id here");
    ui->lineEdit_pw->setPlaceholderText("put you pw here");
    ui->lineEdit_pw->setPlaceholderText("put you phone-number here");
    ui->lineEdit_email->setPlaceholderText("put you email here");
}

Registration::~Registration()
{
    delete ui;
}

void Registration::on_Button_registration_clicked()
{
    // MYSQL CONNECTION
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");            //temp local host
    db.setUserName("root");                 //db user name
    db.setPassword("root");                 //db pw
    db.setDatabaseName("student_qt");              //db name

    if(db.open()) {
        cout<<"db connected"<<endl;
        QString studentId = ui->lineEdit_id->text();
        QString password = ui->lineEdit_pw->text();
        QString email = ui->lineEdit_email->text();
        QString phone = ui->lineEdit_ph->text();

        // Query HERE!!!!
        QSqlQuery qry;

        // query command here
        qry.prepare("INSERT INTO student_table (studentId, password, email, phone)"
                    "VALUES (:studentId, :password, :email, :phone)");

        // binding your value, my value
        qry.bindValue(":studentId", studentId);
        qry.bindValue(":password", password);
        qry.bindValue(":email", email);
        qry.bindValue(":phone", phone);

        if(qry.exec()) {
            QMessageBox::information(this, "Inserted", "Insert Success");
        }
        else {
            QMessageBox::information(this, "Failed", "Failed to Insert");
        }

    }
    else {
        QMessageBox::information(this, "DB Not Connected", "Database is not connected");
    }
}
