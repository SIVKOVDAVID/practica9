#include <QtWidgets>
const int LENGTH_ROAD = 600;
class Road
{
public:
    Road(double newLength, int newWidth);
    double  Length;
    int 	Width;

};
Road::Road(double newLength, int newWidth)
{
    Length = newLength;
    Width  = newWidth;
}

class Car
{
public:
    Car(int newP, double newV, Road *ptrRoad);
    Road *_road;
    double  X;
    int 	P;
    double  V;

    void move();
};
Car::Car(int newP, double newV, Road *ptrRoad)
{
    _road = ptrRoad;
    X = 0;
    P = newP;
    V = newV;
}



void Car::move()
{
    X+=V;
    if (X>_road->Length)
    {
        X=0;
    }
}
class MainWindow : public QMainWindow
{
public:
    Car *_carA;
    Car *_carB;
    MainWindow(Car *ptrCarA, Car *ptrCarB);
    void updateCars();
private:
    int xCarA = 0;
    int xCarB = 0;
    int timerInterval;
    QLabel 		*carALabel;
    QTimer  	*timer;
    QLabel      *carBLabel;
};
MainWindow::MainWindow(Car *ptrCarA, Car *ptrCarB)
{
    _carA = ptrCarA;
    _carB = ptrCarB;
    resize(LENGTH_ROAD,500);
    setWindowTitle("Racing Labels v9.4");
    QFont labelAFont("TypeWriter",72,QFont::Bold);
    carALabel = new QLabel("A",this);
    carALabel->setGeometry(0,0,100,150);
    carALabel->setFont(labelAFont);

    QFont labelBFont("Fantasy",72,QFont::Bold);
    carBLabel = new QLabel("B",this);
    carBLabel->setGeometry(0,100,100,150);
    carBLabel->setFont(labelBFont);

    timer = new QTimer(this);
    timer->setInterval(200);
    timer->start();

    connect(timer, &QTimer::timeout,this, &MainWindow::updateCars);
}
void MainWindow::updateCars()
{
    //xCarA+=_carB->V;
    _carA->move();
    xCarA = _carA->X;
    carALabel->setGeometry(xCarA,0,100,150);

    //xCarB+=_carB->V;
    _carB->move();
    xCarB = _carB->X;
    carBLabel->setGeometry(xCarB,100,100,150);
}
int main(int argc,char *argv[]){
    QApplication app(argc, argv);
    Road road(LENGTH_ROAD,3);
    Car carA(1, 6, &road);
    Car carB(1, 9, &road);
    MainWindow mainWin(&carA,&carB);
    mainWin.show();
    return app.exec();
}

