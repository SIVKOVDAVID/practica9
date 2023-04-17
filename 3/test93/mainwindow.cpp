#include "mainwindow.h"
#include <iostream>

int hori = 20;
int vert = 20;
int k = 1;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    this->setFixedWidth(200);
    this->setFixedHeight(150);
    Label1 = new QLabel(this);
    Label1->setGeometry(20,20,100,20);
    Label1->setText("Test v9.2: OK.");
    horizbtn = new QPushButton(this);
    vertbtn = new QPushButton(this);

    timer = new QTimer(this);

    horizbtn->setText("Vert");
    vertbtn->setText("Horiz");
    horizbtn->setGeometry(150,100,50,20);
    vertbtn->setGeometry(150,120,50,20);

    connect(horizbtn, &QPushButton::clicked, this, &MainWindow::hor);
    connect(vertbtn, &QPushButton::clicked, this, &MainWindow::ver);
}

MainWindow::~MainWindow() {
}

void MainWindow::goH () {
    if(k==1) {
        hori=hori+20;
        Label1->setGeometry(20,hori,100,20);
    }
    if(k==0) {
        hori=hori-20;
        Label1->setGeometry(20,hori,100,20);
    }
    if(hori>=170) k=0;
    if(hori<=10) k=1;
}
void MainWindow::goV () {
    if(k==1) {
        vert=vert+20;
        Label1->setGeometry(vert,20,100,20);
    }
    if(k==0) {
        vert=vert-20;
        Label1->setGeometry(vert,20,100,20);
    }
    if(vert>=140) k=0;
    if(vert<=10) k=1;
}

void MainWindow::hor() {
    timer->stop();
    Label1->setGeometry(20,20,100,20);
    connect(timer, SIGNAL(timeout()), SLOT(goH()));
    timer->start(1000);
}
void MainWindow::ver() {
    timer->stop();
    Label1->setGeometry(20,20,100,20);
    connect(timer, SIGNAL(timeout()), SLOT(goV()));
    timer->start(1000);
}

