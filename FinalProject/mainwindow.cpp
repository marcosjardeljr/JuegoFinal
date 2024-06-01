#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>
#include <QKeyEvent>
#include <QDateTime>
#include "jugador.h"
#include "enemigos.h"
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
    connect(timer, &QTimer::timeout, this, &MainWindow::moverJugador);
    mijugador = new jugador(scene);


    QString rutaMalo1 = ":/imagenes/aviondeguerra.png";
    QPixmap malo1(rutaMalo1);
    avionPos = QPointF(360,140);
    avion = new enemigos(scene, malo1, 0.12, avionPos);

    QString rutaMalo2 = ":/imagenes/soldadorecortado.png";
    QPixmap malo2(rutaMalo2);
    soldadoPos = QPointF(75,410);
    soldado = new enemigos(scene, malo2, 0.04, soldadoPos);

    QString rutaMalo3 = ":/imagenes/bit0.png";
    QPixmap malo3(rutaMalo3);
    bitPos = QPointF(200,250);
    bit = new enemigos(scene, malo3, 0.04, bitPos);

    QString rutaMalo4 = ":/imagenes/bit1.png";
    QPixmap malo4(rutaMalo4);
    bitonePos = QPointF(600,250);
    bitone = new enemigos(scene, malo4, 0.05, bitonePos);

    QString rutaMalo5 = ":/imagenes/trampa.png";
    QPixmap malo5(rutaMalo5);
    trampaPos = QPointF(600,455);
    trampa = new enemigos(scene, malo5, 0.06, trampaPos);

    QString rutaMalo6 = ":/imagenes/trampa.png";
    QPixmap malo6(rutaMalo6);
    trampaPos = QPointF(630,455);
    trampa = new enemigos(scene, malo6, 0.06, trampaPos);

    QString rutaMalo7 = ":/imagenes/trampa.png";
    QPixmap malo7(rutaMalo7);
    trampaPos = QPointF(660,455);
    trampa = new enemigos(scene, malo7, 0.06, trampaPos);

    QString rutaMalo8 = ":/imagenes/trampa.png";
    QPixmap malo8(rutaMalo8);
    trampaPos = QPointF(690,455);
    trampa = new enemigos(scene, malo8, 0.06, trampaPos);

    QString rutaMalo9= ":/imagenes/trampalado.png";
    QPixmap malo9(rutaMalo9);
    trampaPos = QPointF(690,370);
    trampa = new enemigos(scene, malo9, 0.06, trampaPos);

    QString rutaMalo10= ":/imagenes/grenade.png";
    QPixmap malo10(rutaMalo10);
    granadaPos = QPointF(690,100);
    granada = new enemigos(scene, malo10, 0.02, granadaPos);

    QString rutaMalo11= ":/imagenes/canon.png";
    QPixmap malo11(rutaMalo11);
    canonPos = QPointF(850,300);
    canon = new enemigos(scene, malo11, 0.2, canonPos);

    QString rutaMalo12 = ":/imagenes/trampa.png";
    QPixmap malo12(rutaMalo12);
    trampaPos = QPointF(400,455);
    trampa = new enemigos(scene, malo12, 0.06, trampaPos);

    QString rutaMalo13 = ":/imagenes/trampa.png";
    QPixmap malo13(rutaMalo13);
    trampaPos = QPointF(430,455);
    trampa = new enemigos(scene, malo13, 0.06, trampaPos);

    QString rutaMalo14 = ":/imagenes/trampa.png";
    QPixmap malo14(rutaMalo14);
    trampaPos = QPointF(370,455);
    trampa = new enemigos(scene, malo14, 0.06, trampaPos);

    QString rutaMalo15 = ":/imagenes/trampa.png";
    QPixmap malo15(rutaMalo15);
    trampaPos = QPointF(340,455);
    trampa = new enemigos(scene, malo15, 0.06, trampaPos);

    QString rutaMalo16= ":/imagenes/trampalado.png";
    QPixmap malo16(rutaMalo16);
    trampaPos = QPointF(500,370);
    trampa = new enemigos(scene, malo16, 0.06, trampaPos);

    QString rutaMalo17= ":/imagenes/trampalado.png";
    QPixmap malo17(rutaMalo17);
    trampaPos = QPointF(500,400);
    trampa = new enemigos(scene, malo17, 0.06, trampaPos);

    QString rutaMalo18= ":/imagenes/trampalado.png";
    QPixmap malo18(rutaMalo18);
    trampaPos = QPointF(500,430);
    trampa = new enemigos(scene, malo18, 0.06, trampaPos);




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

void MainWindow::keyPressEvent(QKeyEvent *evento){

    if(evento->key() == Qt::Key_S) {
        mijugador->setPos(mijugador->pos().x(), mijugador->pos().y() + 10);

        // Colision
        if(EvaluarColision(mijugador)){
            mijugador->setPos(mijugador->pos().x(), mijugador->pos().y() - 20);
        }
    }
    else if(evento->key() == Qt::Key_W) {
        mijugador->setPos(mijugador->pos().x(), mijugador->pos().y() - 10);

        // Colision
        if(EvaluarColision(mijugador)){
            mijugador->setPos(mijugador->pos().x(), mijugador->pos().y() + 20);
        }
    }
    else if(evento->key() == Qt::Key_D) {
        mijugador->setPos(mijugador->pos().x() + 10, mijugador->pos().y());

        // Colision
        if(EvaluarColision(mijugador)){
            mijugador->setPos(mijugador->pos().x() - 20, mijugador->pos().y());
        }
    }
    else if(evento->key() == Qt::Key_A) {
        mijugador->setPos(mijugador->pos().x() - 10, mijugador->pos().y());

        // Colision
        if(EvaluarColision(mijugador)){
            mijugador->setPos(mijugador->pos().x() + 20, mijugador->pos().y());
        }
    }
}


void MainWindow::moverJugador(){

}

bool MainWindow::EvaluarColision(QGraphicsItem *item)
{
    QVector<pared*>::Iterator it;
    for(it=muros.begin();it!=muros.end();it++){
        if((*it)->collidesWithItem(item)){
            return true;
        }
    }
    return false;
}

