#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H
#include <QPushButton>

class CustomButton : public QPushButton
{
    Q_OBJECT
public:
    CustomButton(const QString& text, QWidget* parent = 0);
    virtual ~CustomButton();

    //add button function here

};

#endif // CUSTOMBUTTON_H
