/********************************************************************************
** Form generated from reading UI file 'makeroom.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAKEROOM_H
#define UI_MAKEROOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MakeRoom
{
public:
    QLineEdit *lineEdit_propw;
    QPushButton *pushButton_makeRoom;

    void setupUi(QDialog *MakeRoom)
    {
        if (MakeRoom->objectName().isEmpty())
            MakeRoom->setObjectName(QStringLiteral("MakeRoom"));
        MakeRoom->resize(456, 188);
        lineEdit_propw = new QLineEdit(MakeRoom);
        lineEdit_propw->setObjectName(QStringLiteral("lineEdit_propw"));
        lineEdit_propw->setGeometry(QRect(50, 80, 251, 41));
        pushButton_makeRoom = new QPushButton(MakeRoom);
        pushButton_makeRoom->setObjectName(QStringLiteral("pushButton_makeRoom"));
        pushButton_makeRoom->setGeometry(QRect(320, 90, 93, 28));

        retranslateUi(MakeRoom);

        QMetaObject::connectSlotsByName(MakeRoom);
    } // setupUi

    void retranslateUi(QDialog *MakeRoom)
    {
        MakeRoom->setWindowTitle(QApplication::translate("MakeRoom", "Dialog", nullptr));
        pushButton_makeRoom->setText(QApplication::translate("MakeRoom", "make", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MakeRoom: public Ui_MakeRoom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAKEROOM_H
