#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(checkValues()));
    timer->start(500);

}

double Dialog::readTemp()
{
    return 0;
}

int Dialog::readVoltage()
{
    return 0;
}

int Dialog::readLightLevel()
{
    return 0;
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::checkValues()
{
    ui->dial->setValue(readVoltage());
    ui->lcdNumber->display(readTemp());
    ui->verticalSlider->setValue(readLightLevel());

}



