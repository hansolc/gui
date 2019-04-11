/********************************************************************************
** Form generated from reading UI file 'registration.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATION_H
#define UI_REGISTRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Registration
{
public:
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout;
    QLabel *label_id;
    QLineEdit *lineEdit_id;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_pw;
    QLineEdit *lineEdit_pw;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_email;
    QLineEdit *lineEdit_email;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_ph;
    QLineEdit *lineEdit_ph;
    QPushButton *Button_registration;

    void setupUi(QDialog *Registration)
    {
        if (Registration->objectName().isEmpty())
            Registration->setObjectName(QStringLiteral("Registration"));
        Registration->resize(447, 686);
        groupBox = new QGroupBox(Registration);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 391, 641));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        groupBox->setFont(font);
        verticalLayout_5 = new QVBoxLayout(groupBox);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_id = new QLabel(groupBox);
        label_id->setObjectName(QStringLiteral("label_id"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_id->sizePolicy().hasHeightForWidth());
        label_id->setSizePolicy(sizePolicy);
        label_id->setMinimumSize(QSize(0, 73));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label_id->setFont(font1);

        verticalLayout->addWidget(label_id);

        lineEdit_id = new QLineEdit(groupBox);
        lineEdit_id->setObjectName(QStringLiteral("lineEdit_id"));

        verticalLayout->addWidget(lineEdit_id);


        verticalLayout_5->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_pw = new QLabel(groupBox);
        label_pw->setObjectName(QStringLiteral("label_pw"));
        label_pw->setFont(font1);

        verticalLayout_2->addWidget(label_pw);

        lineEdit_pw = new QLineEdit(groupBox);
        lineEdit_pw->setObjectName(QStringLiteral("lineEdit_pw"));
        lineEdit_pw->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(lineEdit_pw);


        verticalLayout_5->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_email = new QLabel(groupBox);
        label_email->setObjectName(QStringLiteral("label_email"));
        label_email->setFont(font1);

        verticalLayout_3->addWidget(label_email);

        lineEdit_email = new QLineEdit(groupBox);
        lineEdit_email->setObjectName(QStringLiteral("lineEdit_email"));

        verticalLayout_3->addWidget(lineEdit_email);


        verticalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_ph = new QLabel(groupBox);
        label_ph->setObjectName(QStringLiteral("label_ph"));
        label_ph->setFont(font1);

        verticalLayout_4->addWidget(label_ph);

        lineEdit_ph = new QLineEdit(groupBox);
        lineEdit_ph->setObjectName(QStringLiteral("lineEdit_ph"));

        verticalLayout_4->addWidget(lineEdit_ph);


        verticalLayout_5->addLayout(verticalLayout_4);

        Button_registration = new QPushButton(groupBox);
        Button_registration->setObjectName(QStringLiteral("Button_registration"));

        verticalLayout_5->addWidget(Button_registration);


        retranslateUi(Registration);

        QMetaObject::connectSlotsByName(Registration);
    } // setupUi

    void retranslateUi(QDialog *Registration)
    {
        Registration->setWindowTitle(QApplication::translate("Registration", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("Registration", "Sign in", nullptr));
        label_id->setText(QApplication::translate("Registration", "Student ID", nullptr));
        label_pw->setText(QApplication::translate("Registration", "Password", nullptr));
        label_email->setText(QApplication::translate("Registration", "Email", nullptr));
        label_ph->setText(QApplication::translate("Registration", "Phone number", nullptr));
        Button_registration->setText(QApplication::translate("Registration", "Let's Get it!!!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Registration: public Ui_Registration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATION_H
