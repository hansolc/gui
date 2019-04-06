#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "registration.h" //regstration page

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
