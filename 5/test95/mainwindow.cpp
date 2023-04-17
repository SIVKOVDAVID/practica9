#include "mainwindow.h"
#include <tbook.h>
#include <string>
#include <fstream>
#include <iostream>

TBook books[10];
int i=0;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    this->setFixedWidth(450);
    this->setFixedHeight(150);

    ifstream fin;
    fin.open("C:/Sivkov David/Homework ggpi/9/5/test95/book.txt");
    if (fin.is_open()) {
        for (int var = 0; var < 10; var++) {
            string temp;
            getline(fin, books[var].Name);
            getline(fin, books[var].Author);
            getline(fin, temp);
            books[var].Count = stoi(temp);
        }
        fin.close();
    } else cout << "Can't find a file!" << endl;

    Book = new QLineEdit(this);
    startbutton = new QPushButton(this);
    stopbutton = new QPushButton(this);

    Book->setGeometry(20,20,400,20);
    startbutton->setGeometry(20,50,60,25);
    stopbutton->setGeometry(80,50,60,25);

    startbutton->setText("Play");
    stopbutton->setText("Stop");

    connect(startbutton, &QPushButton::clicked, this, &MainWindow::starting);
    connect(stopbutton, &QPushButton::clicked, this, &MainWindow::stoping);
}

MainWindow::~MainWindow() {
}

void MainWindow::showBooks() {
    if(i==9) i=0;
    Book->setText("Name: " + QString::fromStdString(books[i].Name) +
                       " Author: " + QString::fromStdString(books[i].Name) +
                       " Count: " + QString::fromStdString(to_string(books[i].Count)));
    i++;
}
void MainWindow::starting() {
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), SLOT(showBooks()));
    timer->start(1000);
}

void MainWindow::stoping() {
    timer->stop();
}




