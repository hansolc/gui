#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "registration.h" //regstration page
#include <iostream>
#include<QMessageBox>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{    
    ui->setupUi(this);
    ui->lineEdit_id->setPlaceholderText("Enter your student ID");
    ui->lineEdit_pw->setPlaceholderText("Enter you password");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Button_register_clicked()
{
    //Registration regis_window;                // this method cannot open main window
    //regis_window.setModal(true);
    //regis_window.exec();
    regis_window = new Registration(this);      //if main window closed regis window also closed
    regis_window->show();
}

void MainWindow::on_Button_login_clicked()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QMYSQL", "MyConnect");
    db.setHostName("127.0.0.1");            //temp local host
    db.setUserName("root");                 //db user name
    db.setPassword("root");                 //db pw
    db.setDatabaseName("student_qt");              //db name

    QString studentId = ui->lineEdit_id->text();
    QString password = ui->lineEdit_pw->text();

    if(db.open()) {
        // this is Log In Button
       // QMessageBox::information(this, "DB Connected", "Database is connected");

        QSqlQuery query(QSqlDatabase::database("MyConnect"));

        query.prepare(QString("SELECT * FROM student_table WHERE studentId = :studentId AND password = :password"));

        query.bindValue(":studentId", studentId);
        query.bindValue(":password", password);


        if(!query.exec()) {
            QMessageBox::information(this, "Failed", "Query failed to execute");
        }
        else {
            while(query.next()) {
                QString studentIdFromDB = query.value(1).toString();
                QString passwordFromDB = query.value(2).toString();

                if(studentIdFromDB == studentId && passwordFromDB == password) {
                    QMessageBox::information(this, "Success", "Login Success");

                    //after login success
                    //coding here
                }
                else {
                    QMessageBox::information(this, "failed", "Login Failed");
                }

            }
        }

    }
    else {
        QMessageBox::information(this, "DB Not Connected", "Database is not connected");
    }







    db.close();



}
