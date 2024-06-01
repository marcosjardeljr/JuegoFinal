#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>
#include <QKeyEvent>
#include <QDateTime>
#include "jugador.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    QImage fondo(":/imagenes/fondo_circuito.jpg");
    QBrush brochaF(fondo);

    ui->graphicsView->setBackgroundBrush(brochaF);
    scene->setSceneRect(420, 205, 180, 160);
    ui->graphicsView->scale(1.2, 1.2);
    timer = new QTimer(this);
    timer->start(100);
    mijugador = new jugador(scene);
    //scene->addItem(mijugador);
    //mijugador->setPos(100, 100);
    //Fila superior
    for(int i=40;i<1070;i+=37){
        muros.push_back(new pared(50,30,i,37));
        scene->addItem(muros.back());
    }
    //Columna izquierda
    for(int i=-111; i<650; i+=32){
        muros.push_back(new pared(25,40,40,i));
        scene->addItem(muros.back());
    }

    //Columna derecha
    for(int i =30; i<1000; i+=32){
        muros.push_back(new pared(100,50,955,i));
        scene->addItem(muros.back());
    }

    //fila superior abajo
    for(int i =300; i<700; i+=37){
        muros.push_back(new pared(70,20,i,80));
        scene->addItem(muros.back());
    }

    //fila inferior
    for(int i=50; i<1000; i+=45){
        muros.push_back(new pared(70,20,i,505));
        scene->addItem(muros.back());
    }

    muros.push_back(new pared(100, 20, 70, 200)); scene->addItem(muros.back()); //ancho, alto, posx , pos y
    muros.push_back(new pared(100, 20, 840, 350)); scene->addItem(muros.back());

    muros.push_back(new pared(100, 20, 70, 350)); scene->addItem(muros.back());
    muros.push_back(new pared(90, 20, 320, 350)); scene->addItem(muros.back());

    muros.push_back(new pared(90, 20, 450, 350)); scene->addItem(muros.back());

    muros.push_back(new pared(20, 100, 700, 200)); scene->addItem(muros.back());
    muros.push_back(new pared(105, 20, 840, 200)); scene->addItem(muros.back()); //parte superior del cañon fila superior

    muros.push_back(new pared(20, 200, 520, 350)); scene->addItem(muros.back());

    muros.push_back(new pared(20, 170, 520, 100)); scene->addItem(muros.back());

    muros.push_back(new pared(100, 20, 650, 350)); scene->addItem(muros.back()); //base del cañon
}

MainWindow::~MainWindow()
{
    delete ui;
}

