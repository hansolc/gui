#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "makeroom.h"

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
    // db setting
    db = QSqlDatabase::addDatabase("QMYSQL", "student_DB");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("root");
    db.setDatabaseName("student_qt");

    QString studentId = ui->lineEdit_id_2->text();
    QString password = ui->lineEdit_pw_2->text();

    if(db.open()) {

        QSqlQuery qry(QSqlDatabase::database("student_DB"));

        qry.prepare(QString("SELECT * FROM student_table WHERE studentId = :studentId AND password = :password"));

        qry.bindValue(":studentId", studentId);
        qry.bindValue(":password", password);

        if(!qry.exec()) {
            QMessageBox::information(this, "qry Failed", "qry failed to execute");
        }
        else {
            while(qry.next()) {
                QString studentIdFromDB = qry.value(1).toString();
                QString passwordFromDB = qry.value(2).toString();

                if(studentIdFromDB == studentId && passwordFromDB == password) {
                    QMessageBox::information(this, "Success", "Login Success");

                    //after Login Code here
                    ui->stackedWidget->setCurrentIndex(1);
                }
                else {
                    QMessageBox::information(this, "Failed", "Login Failed");
                }
            }
        }
    }
    else {
        QMessageBox::information(this, "DB not Connected", "database is not connected");
    }


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
