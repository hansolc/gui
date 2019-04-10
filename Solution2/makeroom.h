#ifndef MAKEROOM_H
#define MAKEROOM_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>

namespace Ui {
class MakeRoom;
}

class MakeRoom : public QDialog
{
    Q_OBJECT

public:
    explicit MakeRoom(QWidget *parent = 0);
    ~MakeRoom();

private slots:
    void on_pushButton_makeRoom_clicked();

private:
    Ui::MakeRoom *ui;
    QSqlDatabase db;
};

#endif // MAKEROOM_H
