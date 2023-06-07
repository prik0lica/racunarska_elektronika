#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimer>
#include <QDebug>
//#include <wiringPiI2C>
//#include <wiringPi>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);

    double readTemp();
    int readVoltage();
    int readLightLevel();

    ~Dialog();


public slots:
    void checkValues();

private:
    Ui::Dialog *ui;
    QTimer *timer;
    double temperature;
};
#endif // DIALOG_H
