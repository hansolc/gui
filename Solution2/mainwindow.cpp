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

    ui->stackedWidget->setCurrentIndex(0);

    //connect: when changeIndex trigger -> changeStack slot start
    connect(this, SIGNAL(changeIndex(int)), this, SLOT(changeStack(int)));
    connect(this, SIGNAL(numChanged(QString, QString, QString)), this, SLOT(setNum(QString, QString, QString)));

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

    ui->tableWidget_roomlist->setItem(0, 1, new QTableWidgetItem(this->numS515));
    ui->tableWidget_roomlist->setItem(1, 1, new QTableWidgetItem(this->numS516));
    ui->tableWidget_roomlist->setItem(2, 1, new QTableWidgetItem(this->numS517));

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


    //signal/slot for chattinglog
    connect(this, SIGNAL(showMessage(QString)), this, SLOT(printMessage(QString)));
    connect(this, SIGNAL(showMessage516(QString)), this, SLOT(printMessage516(QString)));
    connect(this, SIGNAL(showMessage517(QString)), this, SLOT(printMessage517(QString)));

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
    root["numS515"] = this->numS515.toStdString();
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
    root["numS516"] = this->numS515.toStdString();
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
    root["numS517"] = this->numS515.toStdString();
    str = fastWriter.write(root);
    this->chattingClient->sendMessage(str);

    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_Button_register_clicked()
{
    // create object 'Registration'
    regis_window = new Registration(this);
    regis_window->chattingClient = this->chattingClient;
    regis_window->show();
}

void MainWindow::changeStack(int index)
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

void MainWindow::setNum(QString updateStudnet, QString updateStudnet516, QString updateStudnet517)
{
    numS515 = updateStudnet;
    numS516 = updateStudnet516;
    numS517 = updateStudnet517;

    ui->tableWidget_roomlist->setItem(0, 1, new QTableWidgetItem(this->numS515));
    ui->tableWidget_roomlist->setItem(1, 1, new QTableWidgetItem(this->numS516));
    ui->tableWidget_roomlist->setItem(2, 1, new QTableWidgetItem(this->numS517));
    //emit numChanged(updateStudnet);
}

QString MainWindow::getNum()
{
    std::cout<<"this->numS515: "<<std::endl;
    return this->numS515;
}

void MainWindow::regisSlot()
{
    QMessageBox::information(this, "Success", "Success");
}

void MainWindow::printMessage(QString msg)
{
    // here chatting 515.
    ui->Chatting_log->append(msg);

}

void MainWindow::printMessage516(QString msg)
{
    ui->chatting_log_516->append(msg);
}

void MainWindow::printMessage517(QString msg)
{
    ui->chatting_log_517->append(msg);
}

void MainWindow::on_Button_login_2_clicked()
{
    // log-in function
    Json::Value root;
    Json::FastWriter fastWriter;
    std::string str;

    root["type"] = MessageType::LOGIN_PASS;
    root["id"] = ui->lineEdit_id_2->text().toStdString();
    root["password"] = ui->lineEdit_pw_2->text().toStdString();
    //root["numS515"] = this->numS515.toStdString();
    //root["numS516"] = this->numS516.toStdString();
    //root["numS517"] = this->numS517.toStdString();
    root["numS515"] = "10";
    root["numS516"] = "20";
    root["numS517"] = "30";

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
//    int studentNum, field, res;
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
//    field = ui->tableWidget_roomlist->rowCount()-1;
//    ui->tableWidget_roomlist->setItem(field, ROOMNUM, new QTableWidgetItem(roomNum));
//    ui->tableWidget_roomlist->setItem(field, SUBJECT, new QTableWidgetItem(subject));
//    ui->tableWidget_roomlist->setItem(field, STUDENTNUM, new QTableWidgetItem(QString::number(studentNum)));

//    CustomButton* button_join = new CustomButton("Join");
//    //button_join = new CustomButton("Join");
//    //QPushButton* button_join = new QPushButton();
//    //button_join = new QPushButton();
//    //button_join->setText("Join");
//    button_join->setStyleSheet("QPushButton {color : black}");
//    ui->tableWidget_roomlist->setCellWidget(field,BUTTON,(QWidget*)button_join);

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
    QString room = "515";

    //message send to server
    root["type"] = MessageType::TEXT_MESSAGE;
    root["text"] = ui->lineEdit_msg->text().toStdString();
    root["room"] = room.toStdString();

    str = fastWriter.write(root);
    this->chattingClient->sendMessage(str);

    ui->lineEdit_msg->clear();

}

void MainWindow::on_send_516_clicked()
{
    Json::Value root;
    Json::FastWriter fastWriter;
    std::string str;

    //message send to server
    root["type"] = MessageType::TEXT_MESSAGE;
    root["text"] = ui->lineEdit_msg_516->text().toStdString();
    root["room"] = std::to_string(516);

    str = fastWriter.write(root);
    this->chattingClient->sendMessage(str);

    ui->lineEdit_msg_516->clear();
}

void MainWindow::on_send_517_clicked()
{
    Json::Value root;
    Json::FastWriter fastWriter;
    std::string str;

    //message send to server
    root["type"] = MessageType::TEXT_MESSAGE;
    root["text"] = ui->lineEdit_msg_517->text().toStdString();
    root["room"] = std::to_string(517);

    str = fastWriter.write(root);
    this->chattingClient->sendMessage(str);

    ui->lineEdit_msg_517->clear();
}
