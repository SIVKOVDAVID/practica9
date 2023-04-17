#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QApplication>
#include <QPushButton>
#include <QTimer>
#include <QLineEdit>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QLineEdit *Book;
    QTimer *timer;
    QPushButton *startbutton;
    QPushButton *stopbutton;

private slots:
    void showBooks();
    void starting();
    void stoping();
};
#endif

