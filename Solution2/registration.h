#pragma once

#ifndef REGISTRATION_H
#define REGISTRATION_H

#include "chattingclient.h"
#include "json.h"
#include <QDialog>

class ChattingClient;

namespace Ui {
class Registration;
}

class Registration : public QDialog
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = 0);
    ChattingClient *chattingClient;
    ~Registration();

private slots:
    void on_Button_register_reg_clicked();

private:
    Ui::Registration *ui;

};

#endif // REGISTRATION_H
