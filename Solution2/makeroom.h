#pragma once

#ifndef MAKEROOM_H
#define MAKEROOM_H

#include <QDialog>

namespace Ui {
class MakeRoom;
}

class MakeRoom : public QDialog
{
    Q_OBJECT

public:
    explicit MakeRoom(QWidget *parent = 0);
    ~MakeRoom();

    int numStudent;
    QString subject() const;
    //int numStudent() const;
    QString roomNumber() const;
    void getNum(int numStudent);
    int setNum();

private slots:
    void on_pushButton_makeRoom_clicked();

    void on_pushButton_close_clicked();

private:
    Ui::MakeRoom *ui;
};

#endif // MAKEROOM_H
