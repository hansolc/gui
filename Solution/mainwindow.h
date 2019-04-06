#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "registration.h" //regstration page
#include <QtSql>
#include <QSqlDatabase>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Button_register_clicked();

    void on_Button_login_clicked();

private:
    Ui::MainWindow *ui;
    Registration *regis_window;
    QSqlDatabase db;
};

#endif // MAINWINDOW_H
