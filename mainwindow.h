#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qwt_dial_needle.h>
#include <QTimer>
#include "stdio.h"
#include "D:\LIB\OpenMAT-1.3.4\include\LpmsSensorI.h"
#include "D:\LIB\OpenMAT-1.3.4\include\LpmsSensorManagerI.h"
#include <iostream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void getData();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer* timer;
};

#endif // MAINWINDOW_H
