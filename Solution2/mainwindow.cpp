#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "custombutton.h"
#include <QMessageBox>
#include <iostream>
#include <QPalette>

int studentNum, fila, res;
QString subject, roomNum;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Dankook Solutions");

    // text: before edit lineEdit
    ui->lineEdit_id_2->setPlaceholderText("Enter your student ID");
    ui->lineEdit_pw_2->setPlaceholderText("Enter your password");

    char buf[16] = "127.0.0.1";
    //char buf[16] = "172.31.37.201";
    //char buf[16] = "192.168.0.189";
    int port = 3490;

    this->chattingClient = new ChattingClient(*this, buf, port);
    this->chattingClient->start();
    // about after login page
    // ***server: get room numbers

    ui->stackedWidget->setCurrentIndex(0);

    //connect: when changeIndex trigger -> changeStack slot start
    connect(this, SIGNAL(changeIndex(int, int)), this, SLOT(changeStack(int, int)));

    //table widget style sheet
    QPalette p = ui->tableWidget_roomlist->palette();
    p.setColor(QPalette::Base, Qt::red);
    ui->tableWidget_roomlist->setPalette(p);

    //header setting
    QStringList headers;
    QHeaderView* tHeader = ui->tableWidget_roomlist->horizontalHeader();
    ui->tableWidget_roomlist->setColumnCount(3);
    headers <<"RoomNumber" <<"Number of students"<<"Join";
    ui->tableWidget_roomlist->horizontalHeader()->setStyleSheet("QHeaderView { font-size:10pt;}");
    tHeader->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_roomlist->setHorizontalHeaderLabels(headers);

    //insert 3 rows
    ui->tableWidget_roomlist->insertRow(ui->tableWidget_roomlist->rowCount());
    ui->tableWidget_roomlist->insertRow(ui->tableWidget_roomlist->rowCount());
    ui->tableWidget_roomlist->insertRow(ui->tableWidget_roomlist->rowCount());

    //set RoomNumber
    ui->tableWidget_roomlist->setItem(0, 0, new QTableWidgetItem("515"));
    ui->tableWidget_roomlist->setItem(1, 0, new QTableWidgetItem("516"));
    ui->tableWidget_roomlist->setItem(2, 0, new QTableWidgetItem("517"));

    //function for getting present student numbers
    this->getNum();

    //set student number
    //need to change setNum() --> now getting '0'
    ui->tableWidget_roomlist->setItem(0, 1, new QTableWidgetItem(QString::number(this->numS515)));
    ui->tableWidget_roomlist->setItem(1, 1, new QTableWidgetItem(QString::number(20)));
    ui->tableWidget_roomlist->setItem(2, 1, new QTableWidgetItem(QString::number(19)));

    //set Button
    CustomButton* btn_join515 = new CustomButton("Join");
    CustomButton* btn_join516 = new CustomButton("Join");
    CustomButton* btn_join517 = new CustomButton("Join");
    btn_join515->setStyleSheet("QPushButton {color : black}");
    ui->tableWidget_roomlist->setCellWidget(0, 2, (QWidget*)btn_join515);
    ui->tableWidget_roomlist->setCellWidget(1, 2, (QWidget*)btn_join516);
    ui->tableWidget_roomlist->setCellWidget(2, 2, (QWidget*)btn_join517);

    connect(btn_join515, SIGNAL(clicked(bool)), this, SLOT(btn_515_clicked()));
    connect(btn_join516, SIGNAL(clicked(bool)), this, SLOT(btn_516_clicked()));
    connect(btn_join517, SIGNAL(clicked(bool)), this, SLOT(btn_517_clicked()));


}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::btn_515_clicked()
{
    Json::Value root;
    Json::FastWriter fastWriter;
    std::string str;

    root["type"] = MessageType::ENTERROOM_REQUSET;
    str = fastWriter.write(root);
    this->chattingClient->sendMessage(str);

    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::btn_516_clicked()
{
    Json::Value root;
    Json::FastWriter fastWriter;
    std::string str;

    root["type"] = MessageType::ENTERROOM_REQUSET;
    str = fastWriter.write(root);
    this->chattingClient->sendMessage(str);

    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::btn_517_clicked()
{
    Json::Value root;
    Json::FastWriter fastWriter;
    std::string str;

    root["type"] = MessageType::ENTERROOM_REQUSET;
    str = fastWriter.write(root);
    this->chattingClient->sendMessage(str);

    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_Button_register_clicked()
{
    // create object 'Registration'
    regis_window = new Registration(this);
    regis_window->show();
}

void MainWindow::changeStack(int index, int numS515)
{
    if(index != currentIndex) {
        currentIndex = index;
        ui->stackedWidget->setCurrentIndex(currentIndex);
        //emit changeIndex(currentIndex);
    }
}

void MainWindow::changeStackToC1()
{
    //move to chatting room
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::setNum(int updateStudnet)
{
    numS515 = updateStudnet;
    emit numChanged(updateStudnet);
}


void MainWindow::on_Button_login_2_clicked()
{
    // log-in function
    Json::Value root;
    Json::FastWriter fastWriter;
    std::string str;

    makeRoom = new MakeRoom(this);
    root["type"] = MessageType::LOGIN_PASS;
    root["id"] = ui->lineEdit_id_2->text().toStdString();
    root["password"] = ui->lineEdit_pw_2->text().toStdString();
    root["numS515"] = "10";
    //root["numS516"] = ;
    //root["numS517"] = ;

    str = fastWriter.write(root);
    this->chattingClient->sendMessage(str);
}

//void MainWindow::rewrite()
//{
//    QMessageBox::information(this, "Unknown Account", "Unknown Account");
//}

// Making Room
// admin: professor --> insert db info
// this from server? or in ui?
void MainWindow::on_Button_makeRoom_clicked()
{
//    //tableWidget RoomList
//    int studentNum, fila, res;
//    QString subject, roomNum;

//    MakeRoom pd(this);

//    //Exception
//    res = pd.exec();
//    if (res == QDialog::Rejected)
//        return;

//    //use MakeRoom function to transform data type
//    roomNum = pd.roomNumber();
//    studentNum = pd.numStudent();
//    subject = pd.subject();

//    //insert 1. room_num, 2. Subject, 3. Number of Student
//    ui->tableWidget_roomlist->insertRow(ui->tableWidget_roomlist->rowCount());
//    fila = ui->tableWidget_roomlist->rowCount()-1;
//    ui->tableWidget_roomlist->setItem(fila, ROOMNUM, new QTableWidgetItem(roomNum));
//    ui->tableWidget_roomlist->setItem(fila, SUBJECT, new QTableWidgetItem(subject));
//    ui->tableWidget_roomlist->setItem(fila, STUDENTNUM, new QTableWidgetItem(QString::number(studentNum)));

//    CustomButton* button_join = new CustomButton("Join");
//    //button_join = new CustomButton("Join");
//    //QPushButton* button_join = new QPushButton();
//    //button_join = new QPushButton();
//    //button_join->setText("Join");
//    button_join->setStyleSheet("QPushButton {color : black}");
//    ui->tableWidget_roomlist->setCellWidget(fila,BUTTON,(QWidget*)button_join);

}

// Log out
void MainWindow::on_Button_toHome_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    //here: Log out service
}

//void MainWindow::on_pushButton_clicked()
//{
//    Json::Value root;
//    Json::FastWriter fastWriter;
//    std::string str;

//    root["type"] = MessageType::ENTERROOM_REQUSET;
//    str = fastWriter.write(root);
//    this->chattingClient->sendMessage(str);

//    ui->stackedWidget->setCurrentIndex(2);
//}

void MainWindow::on_send_clicked()
{

    Json::Value root;
    Json::FastWriter fastWriter;
    std::string str;

    //message send to server
    root["type"] = MessageType::TEXT_MESSAGE;
    root["text"] = ui->lineEdit_msg->text().toStdString();

    str = fastWriter.write(root);
    this->chattingClient->sendMessage(str);

}
