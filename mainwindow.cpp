#include "mainwindow.h"
#include "ui_mainwindow.h"


using namespace std;

LpmsSensorManagerI* manager;
LpmsSensorI* lpms;
ImuData d;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer=new QTimer();
    timer->setInterval(20);
    timer->stop();

    connect(timer,SIGNAL(timeout()), this, SLOT(getData()));

}
void MainWindow::getData()
{

       cout<<"getData"<<endl;
    // Checks, if conncted
    if (lpms->getConnectionStatus() == SENSOR_CONNECTION_CONNECTED) {

        // Reads quaternion data
        d = lpms->getCurrentData();
        ui->Dial->setValue(d.r[0]+180.0);
        ui->Dial_2->setValue(d.r[1]+180.0);
        ui->Dial_3->setValue(d.r[2]+180.0);

        // Shows data
        printf("qX=%f, qY=%f, qZ=%f\n", d.r[0]+180.0, d.r[1]+180.0, d.r[2]+180.0);
    }
}
MainWindow::~MainWindow()
{
    //     Removes the initialized sensor
    manager->removeSensor(lpms);

    // Deletes LpmsSensorManager object
    delete manager;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->Dial->setNeedle(new QwtDialSimpleNeedle( QwtDialSimpleNeedle::Arrow ,true , Qt::red ));
    ui->Dial_2->setNeedle(new QwtDialSimpleNeedle( QwtDialSimpleNeedle::Arrow ,true , Qt::red ));
    ui->Dial_3->setNeedle(new QwtDialSimpleNeedle( QwtDialSimpleNeedle::Arrow ,true , Qt::red ));

    // Gets a LpmsSensorManager instance
    manager = LpmsSensorManagerFactory();
    cout<<"LpmsSensorManagerFactory"<<endl;

    // Connects to LPMS-B sensor with address 00:11:22:33:44:55
    QString bluetooth_mac = ui->lineEdit->text();

    lpms = manager->addSensor(DEVICE_LPMS_B, bluetooth_mac.toStdString().c_str());
//    lpms = manager->addSensor(DEVICE_LPMS_B, "00:06:66:4b:24:d2");
    cout<<"addSensor"<<endl;

    while(1)
    {
        if (lpms->getConnectionStatus() == SENSOR_CONNECTION_CONNECTED)
        {
            cout<<"get connection"<<endl;
            break;
        }
    }


    // Checks, if conncted
    cout<<"timer start"<<endl;
    timer->start();
}

