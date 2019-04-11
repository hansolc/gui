#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "chattingclient.h"
#include "registration.h"
#include "makeroom.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void ChangeStackedWidget(int index);

private slots:
    void on_Button_register_clicked();
    void on_Button_login_2_clicked();
    void on_Button_makeRoom_clicked();
    void on_Button_toHome_clicked();

private:
    Ui::MainWindow *ui;
    ChattingClient *chattingClient;
    Registration *regis_window;
    MakeRoom *makeRoom_window;

};

#endif // MAINWINDOW_H
