#include "mainwindow.h"
#include <iostream>
#include <QString>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    timer = new QLabel(this);
    timer->setGeometry(80,40,80,20);
}

MainWindow::~MainWindow() {
}

void MainWindow::Ftimer() {
    int t=65340;
    while(t>0) {
        t--;
        int hour = t/3600;
        int minute = (t-hour*3600)/60;
        int second = t-hour*3600-minute*60;
        QString h = QString::number(hour);
        QString m = QString::number(minute);
        QString s = QString::number(second);

        if(h.length()==1) h="0"+h;
        if(m.length()==1) m="0"+m;
        if(s.length()==1) s="0"+s;
        timer->setText(h+":"+m+":"+s);

        QTime dieTime= QTime::currentTime().addSecs(1);
        while (QTime::currentTime() < dieTime)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}

