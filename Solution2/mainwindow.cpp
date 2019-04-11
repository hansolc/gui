#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // text: before edit lineEdit
    ui->lineEdit_id_2->setPlaceholderText("Enter your student ID");
    ui->lineEdit_pw_2->setPlaceholderText("Enter your password");

    char buf[16] = "127.0.0.1";
    int port = 3490;

    this->chattingClient = new ChattingClient(*this, buf, port);
    this->chattingClient->start();
    // about after login page
    // ***server: get room numbers
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ChangeStackedWidget(int index)
{
    //ui->stackedWidget->setCurrentIndex(index); 수정 필요?
}

void MainWindow::on_Button_register_clicked()
{
    // create object 'Registration'
    regis_window = new Registration(this);
    regis_window->show();
}

void MainWindow::on_Button_login_2_clicked()
{
    // 로그인 버튼 클릭 기능
    Json::Value root;
    Json::FastWriter fastWriter;
    std::string str;
    root["type"] = MessageType::LOGIN_PASS;
    root["id"] = "abc"; // 여기에 gui 정보 id, password 입력해서 메세지 패키징 할 것.
    root["password"] = "123";
    str = fastWriter.write(root);
    this->chattingClient->sendMessage(str);
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
