#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "registration.h" //regstration page

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

private:
    Ui::MainWindow *ui;
    Registration *regis_window;
};

#endif // MAINWINDOW_H
