﻿#include "MainWindow.h"

#include <QDebug>
#include <QVBoxLayout>


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}
