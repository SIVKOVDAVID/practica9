#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    timer = new QLabel(this);
    timer->setGeometry(20,20,30,20);
}

MainWindow::~MainWindow() {
}

void MainWindow::Ftimer() {
    int t=120;
    while(t>0) {
        t--;
        QString m = QString::number(t/60);
        QString s = QString::number(t-t/60*60);
        if(t/60 < 10 && t-t/60*60 < 10) timer->setText("0"+m+":"+"0"+s);
        if(t/60 < 10 && t-t/60*60 > 10) timer->setText("0"+m+":"+s);
        if(t/60 > 10 && t-t/60*60 < 10) timer->setText(m+":"+"0"+s);
        if(t/60 > 10 && t-t/60*60 > 10) timer->setText(m+":"+s);
        QTime dieTime= QTime::currentTime().addSecs(1);
        while (QTime::currentTime() < dieTime)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}

