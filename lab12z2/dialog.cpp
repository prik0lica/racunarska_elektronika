#include "dialog.h"
#include "ui_dialog.h"

const char PCF8591 = 0x48; // adresa
int fd;


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    /*

    wiringPiSetup();
    fd = wiringPiI2cSetup(PCF8591);

    */
    ui->setupUi(this);
    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(checkValues()));
    timer->start(500);

}

double Dialog::readTemp()
{
    FILE *fp = fopen("/sys/bus/w1/devices/28-00000xxxxx/w1_slave", "r");
    char tmp[100];

    if(fp == NULL)
    {
        qDebug() << "Greska temp";
        return 0;
    }


    int i=0;
    for(i=0;i<22;i++)
    {
       fscanf(fp,  "%s", tmp);
    }

    fclose(fp);


    for(i=0;i<10;i++)
    {
        tmp[i] = tmp[i+2];
    }

    int tmp_int = atoi(tmp);

    double temperature=(double)tmp_int/1000;

    return temperature;
}

int Dialog::readVoltage()
{

    int adc_value = 0;
    /*
    //read adc 0x03
    wiringPiI2CReadReg8(fd, PCF8591 + 3);
    adc_value = wiringPiI2CReadReg8(fd, PCF8591 + 3);

    //upisi vrednost u DAC reg, 0x04
    wiringPiI2CWriteReg8 (fd, PCF8591 + 4, adc_value);

    //procitaj DAC preko AIN2, 0x02
    wiringPiI2CReadReg8(fd, PCF8591 + 2);
    adc_value = wiringPiI2CReadReg8(fd, PCF8591 + 2);

    */
    return adc_value;
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
