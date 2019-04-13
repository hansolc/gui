#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "makeroom.h"
#include "client_app.h"
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // text: before edit lineEdit
    ui->lineEdit_id_2->setPlaceholderText("Enter your student ID");
    ui->lineEdit_pw_2->setPlaceholderText("Enter your password");

    // about after login page
    // ***server: get room numbers

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Button_register_clicked()
{
    // create object 'Registration'
    regis_window = new Registration(this);
    regis_window->show();
}

void MainWindow::on_Button_login_2_clicked()
{


    // Try Connect Server
    gt->run();

    // go to next page

}

// Making Room
// admin: professor --> insert db info
// this from server? or in ui?
void MainWindow::on_Button_makeRoom_clicked()
{
    //***DB check needed
    //makeRoom_window = new MakeRoom(this);
    //makeRoom_window->show();

    //***Server
    //get roomNo
    //get number of students
    QString roomNo = "517";
    QString numStudents = "30";
    ui->label_makeRoom->setText(QString("RoomNo:%1 students:%2/40").arg(roomNo, numStudents));
}

// Log out
void MainWindow::on_Button_toHome_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
