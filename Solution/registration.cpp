#include "registration.h"
#include "ui_registration.h"
#include <QMessageBox>

Registration::Registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
    ui->lineEdit_id->setPlaceholderText("Put your Id");
    ui->lineEdit_pw->setPlaceholderText("put your password");
    ui->lineEdit_ph->setPlaceholderText("put your phone number");
    ui->lineEdit_email->setPlaceholderText("put your email");
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
    db.setUserName("root");                 //db pw
    db.setDatabaseName("qt5");              //db name

    if(db.open()) {
        QString studentId = ui->lineEdit_id->text();
        QString password = ui->lineEdit_pw->text();
        QString email = ui->lineEdit_email->text();
        QString phone = ui->lineEdit_ph->text();

        // Query HERE!!!!
        QSqlQuery qry;

        // query command here
        qry.prepare("INSERT INTO [TABLE NAME] [ ] VALUES [ ]");

        // binding your value, my value
        qry.bindValue(" ", studentId);
        qry.bindValue(" ", password);
        qry.bindValue(" ", email);
        qry.bindValue(" ", phone);

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
