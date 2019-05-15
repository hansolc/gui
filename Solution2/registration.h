#pragma once

#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include "json.h"

namespace Ui {
class Registration;
}

class Registration : public QDialog
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = 0);
    ~Registration();

private slots:
    void on_Button_registration_clicked();

private:
    Ui::Registration *ui;
    //ChattingClient *chattingClient;
};

#endif // REGISTRATION_H
