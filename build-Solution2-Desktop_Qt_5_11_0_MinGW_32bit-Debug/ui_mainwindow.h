/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *login;
    QGroupBox *signin;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_id_2;
    QLineEdit *lineEdit_id_2;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_pw_2;
    QLineEdit *lineEdit_pw_2;
    QPushButton *Button_login_2;
    QPushButton *Button_register;
    QWidget *topPanel;
    QLabel *label_title;
    QWidget *widget_logo;
    QWidget *after_log_page;
    QPushButton *Button_makeRoom;
    QPushButton *Button_toHome;
    QLabel *label_makeRoom;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(781, 736);
        QIcon icon;
        icon.addFile(QStringLiteral("../gui/Solution/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QLatin1String("#MainWindow {\n"
"background-color:url(:/images/bg.jpg)\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 781, 741));
        stackedWidget->setStyleSheet(QLatin1String("* {\n"
"font-family:century gothic;\n"
"font-size: 24px;\n"
"}\n"
"\n"
"\n"
"#login {\n"
"border-image:url(:/images/bg.jpg);\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"background:rgb(184, 244, 255);\n"
"border-radius:60px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"color:#333;\n"
"border-radius:15px;\n"
"background:#49ebff;\n"
"}\n"
"\n"
"#after_log_page {\n"
"border-image:url(:/images/bg.jpg);\n"
"}\n"
""));
        login = new QWidget();
        login->setObjectName(QStringLiteral("login"));
        signin = new QGroupBox(login);
        signin->setObjectName(QStringLiteral("signin"));
        signin->setGeometry(QRect(190, 250, 371, 271));
        QFont font;
        font.setFamily(QStringLiteral("century gothic"));
        signin->setFont(font);
        signin->setLayoutDirection(Qt::LeftToRight);
        signin->setStyleSheet(QStringLiteral(""));
        verticalLayout_4 = new QVBoxLayout(signin);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_id_2 = new QLabel(signin);
        label_id_2->setObjectName(QStringLiteral("label_id_2"));
        label_id_2->setFont(font);

        verticalLayout_5->addWidget(label_id_2);

        lineEdit_id_2 = new QLineEdit(signin);
        lineEdit_id_2->setObjectName(QStringLiteral("lineEdit_id_2"));
        lineEdit_id_2->setFont(font);

        verticalLayout_5->addWidget(lineEdit_id_2);


        verticalLayout_4->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_pw_2 = new QLabel(signin);
        label_pw_2->setObjectName(QStringLiteral("label_pw_2"));
        label_pw_2->setFont(font);

        verticalLayout_6->addWidget(label_pw_2);

        lineEdit_pw_2 = new QLineEdit(signin);
        lineEdit_pw_2->setObjectName(QStringLiteral("lineEdit_pw_2"));
        lineEdit_pw_2->setFont(font);
        lineEdit_pw_2->setEchoMode(QLineEdit::Password);

        verticalLayout_6->addWidget(lineEdit_pw_2);


        verticalLayout_4->addLayout(verticalLayout_6);

        Button_login_2 = new QPushButton(signin);
        Button_login_2->setObjectName(QStringLiteral("Button_login_2"));
        Button_login_2->setFont(font);

        verticalLayout_4->addWidget(Button_login_2);

        Button_register = new QPushButton(login);
        Button_register->setObjectName(QStringLiteral("Button_register"));
        Button_register->setGeometry(QRect(590, 680, 181, 51));
        Button_register->setFont(font);
        topPanel = new QWidget(login);
        topPanel->setObjectName(QStringLiteral("topPanel"));
        topPanel->setGeometry(QRect(0, 0, 781, 101));
        topPanel->setStyleSheet(QLatin1String("#topPanel {\n"
"background-color:rgb(158, 218, 255)\n"
"}"));
        label_title = new QLabel(topPanel);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setGeometry(QRect(320, 20, 131, 61));
        label_title->setFont(font);
        widget_logo = new QWidget(topPanel);
        widget_logo->setObjectName(QStringLiteral("widget_logo"));
        widget_logo->setGeometry(QRect(10, 0, 181, 111));
        widget_logo->setStyleSheet(QLatin1String("#widget_logo {\n"
"border-image:url(:/images/logo.png);\n"
"}"));
        stackedWidget->addWidget(login);
        after_log_page = new QWidget();
        after_log_page->setObjectName(QStringLiteral("after_log_page"));
        Button_makeRoom = new QPushButton(after_log_page);
        Button_makeRoom->setObjectName(QStringLiteral("Button_makeRoom"));
        Button_makeRoom->setGeometry(QRect(600, 670, 161, 51));
        Button_toHome = new QPushButton(after_log_page);
        Button_toHome->setObjectName(QStringLiteral("Button_toHome"));
        Button_toHome->setGeometry(QRect(20, 670, 171, 51));
        label_makeRoom = new QLabel(after_log_page);
        label_makeRoom->setObjectName(QStringLiteral("label_makeRoom"));
        label_makeRoom->setGeometry(QRect(40, 70, 671, 41));
        stackedWidget->addWidget(after_log_page);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\354\260\270\354\227\254\355\230\225 \352\265\220\354\234\241 \354\206\224\353\243\250\354\205\230", nullptr));
        signin->setTitle(QApplication::translate("MainWindow", "Log In", nullptr));
        label_id_2->setText(QApplication::translate("MainWindow", "Student ID", nullptr));
        label_pw_2->setText(QApplication::translate("MainWindow", "Password", nullptr));
        Button_login_2->setText(QApplication::translate("MainWindow", "Log In", nullptr));
        Button_register->setText(QApplication::translate("MainWindow", "Make Account", nullptr));
        label_title->setText(QApplication::translate("MainWindow", "\354\236\204\354\213\234 \354\240\234\353\252\251", nullptr));
        Button_makeRoom->setText(QApplication::translate("MainWindow", "Make Room", nullptr));
        Button_toHome->setText(QApplication::translate("MainWindow", "Log Out", nullptr));
        label_makeRoom->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
