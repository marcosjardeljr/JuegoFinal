#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>
#include <QKeyEvent>
#include <QDateTime>
#include "jugador.h"
#include "enemigos.h"
#include "movimientos.h"
#include <QMessageBox>

bool level = false;
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
    connect(timer, &QTimer::timeout, this, &MainWindow::movEnemigos);
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
    bitPos = QPointF(250,250);
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
    granadaPos = QPointF(750,100);
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
    muros.push_back(new pared(105, 20, 840, 200)); scene->addItem(muros.back());
    muros.push_back(new pared(20, 200, 520, 350)); scene->addItem(muros.back());
    muros.push_back(new pared(20, 170, 520, 100)); scene->addItem(muros.back());
    muros.push_back(new pared(100, 20, 650, 350)); scene->addItem(muros.back());

    //tunel 1:
    tunel1 = new escape(250, 100, 50, 50);
    scene->addItem(tunel1);
    tunel1->setVisible(false);
    tunel1->setPos(900, 82);

    listaEnemigos = {avion, soldado};
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



void MainWindow::movEnemigos()
{
    if (level == false)
    {
    movimientos::movimientoCircular(bit, angle, bitPos);
    if (mijugador->collidesWithItem(bit)){
         QMessageBox::about(this, "Adios", "\n\n Perdiste :(");
         timer->stop();
         exit(0);
    }
    movimientos::movimientoEliptico(bitone, angle2, bitonePos);
    if (mijugador->collidesWithItem(bitone)){
         QMessageBox::about(this, "Adios", "\n\n Perdiste :(");
         timer->stop();
         exit(0);
    }

    movimientos::caidaLibre(granada, granadaPos);
    if (mijugador->collidesWithItem(granada)){
         QMessageBox::about(this, "Adios", "\n\n Perdiste :(");
         timer->stop();
         exit(0);

    }

    movimientos::movimientoParabolico(canon, angle3);
    if (mijugador->collidesWithItem(canon)){
         QMessageBox::about(this, "Adios", "\n\n Perdiste :(");
         timer->stop();
         exit(0);

    }

    // Evaluamos colision con el túnel

    if (tunel1 != nullptr) {
        // Verifica si el jugador está en la posición para mostrar el túnel
        bool mostrarTunel = (mijugador->pos().x() >= 880 && mijugador->pos().x() <= 930 &&
                             mijugador->pos().y() >= 72 && mijugador->pos().y() <= 92);

        // Muestra u oculta el túnel según la posición del jugador
        tunel1->setVisible(mostrarTunel);

        // Si el túnel está visible, verifica la colisión
        if (mostrarTunel && mijugador != nullptr && tunel1->isVisible() && mijugador->collidesWithItem(tunel1)) {
            // Cambiamos de nivel
            level = true;
           // timer->stop();
            cambiarNivel();
            return;  // Importante: salimos de la función para evitar operaciones adicionales después de cambiar de nivel
        }
}
}
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

void MainWindow::cambiarNivel() {

        // Eliminar el jugador y limpiar la escena actual
        scene->removeItem(mijugador);
        delete mijugador;
        mijugador = nullptr;

        // Limpiar y eliminar los muros
        qDeleteAll(muros);
        muros.clear();

    //remueve muros
        //Columna izquierda
        for(int i=-111; i<650; i+=32){
            muros.push_back(new pared(25,40,40,i));
            scene->removeItem(muros.back());
            muros.pop_back();
        }

        //Columna derecha
        for(int i =30; i<1000; i+=32){
            muros.push_back(new pared(100,50,955,i));
            scene->removeItem(muros.back());
            muros.pop_back();
        }

        //fila superior abajo
        for(int i =300; i<700; i+=37){
            muros.push_back(new pared(70,20,i,80));
            scene->removeItem(muros.back());
            muros.pop_back();
        }

        //fila inferior
        for(int i=50; i<1000; i+=45){
            muros.push_back(new pared(70,20,i,505));
            scene->removeItem(muros.back());
            muros.pop_back();
        }

        //fila inferior
        for(int i=50; i<1000; i+=45){
            muros.push_back(new pared(70,20,i,505));
            scene->removeItem(muros.back());
            muros.pop_back();
        }
        muros.push_back(new pared(100, 20, 70, 200)); scene->addItem(muros.back()); muros.pop_back();
        muros.push_back(new pared(100, 20, 840, 350)); scene->addItem(muros.back()); muros.pop_back();
        muros.push_back(new pared(100, 20, 70, 350)); scene->addItem(muros.back()); muros.pop_back();
        muros.push_back(new pared(90, 20, 320, 350)); scene->addItem(muros.back()); muros.pop_back();
        muros.push_back(new pared(90, 20, 450, 350)); scene->addItem(muros.back()); muros.pop_back();
        muros.push_back(new pared(20, 100, 700, 200)); scene->addItem(muros.back()); muros.pop_back();
        muros.push_back(new pared(105, 20, 840, 200)); scene->addItem(muros.back()); muros.pop_back();
        muros.push_back(new pared(20, 200, 520, 350)); scene->addItem(muros.back()); muros.pop_back();
        muros.push_back(new pared(20, 170, 520, 100)); scene->addItem(muros.back()); muros.pop_back();
        muros.push_back(new pared(100, 20, 650, 350)); scene->addItem(muros.back()); muros.pop_back();


    //liberamos enemigos
        for (enemigos *enemigo : listaEnemigos) {
            scene->removeItem(enemigo);
            delete enemigo;
            enemigo = nullptr;
        }

        //liberamos trampas
        scene->removeItem(trampa);
        delete trampa;
        trampa = nullptr;

        //Liberamos tunel
        scene->removeItem(tunel1);
        delete tunel1;
        tunel1= nullptr;


        // Elimina todos los elementos de la escena actual
        scene->clear();

        // Elimina la escena anterior
        delete scene;

        // Crea una nueva escena y configúrala con el fondo y elementos del nuevo nivel
        ui->setupUi(this);
        scene2 = new QGraphicsScene;
        ui->graphicsView->setScene(scene2);
        QImage nuevoFondo(":/imagenes/fondo_circuito.jpg");
        QBrush newBrochaf(nuevoFondo);
        ui->graphicsView->setBackgroundBrush(newBrochaf);
        scene2->setSceneRect(420, 205, 180, 160);
        ui->graphicsView->scale(1.2, 1.2);
        timer = new QTimer(this);

        // Reiniciar el temporizador para el nuevo nivel
        timer->start(100);

        //jugador
        mijugador = new jugador(scene2);
        scene2->addItem(mijugador);

        // Restablece la posición del jugador en el nuevo nivel
        mijugador->setPos(100, 100);
        qDebug() << "Se cambia de nivel efectivamente";


        //Fila superior
        for(int i=40;i<1070;i+=37){
            muros.push_back(new pared(50,30,i,37));
            scene2->addItem(muros.back());
        }
        //Columna izquierda
        for(int i=-111; i<650; i+=32){
            muros.push_back(new pared(25,40,40,i));
            scene2->addItem(muros.back());
        }

        //Columna derecha
        for(int i =30; i<1000; i+=32){
            muros.push_back(new pared(100,50,955,i));
            scene2->addItem(muros.back());
        }

        //fila inferior
        for(int i=50; i<1000; i+=45){
            muros.push_back(new pared(70,20,i,505));
            scene2->addItem(muros.back());
        }

        //ancho, alto, posx , pos y
        //muros verticales
        muros.push_back(new pared(15, 100, 280, 60)); scene2->addItem(muros.back());
        muros.push_back(new pared(15, 300, 280, 230)); scene2->addItem(muros.back());
        muros.push_back(new pared(15, 100, 780, 420)); scene2->addItem(muros.back());
        muros.push_back(new pared(15, 300, 780, 60)); scene2->addItem(muros.back());
        muros.push_back(new pared(15, 280, 330, 130)); scene2->addItem(muros.back());
        muros.push_back(new pared(15, 40, 330, 480)); scene2->addItem(muros.back());
        muros.push_back(new pared(15, 60, 380, 390)); scene2->addItem(muros.back());
        muros.push_back(new pared(15, 60, 380, 270)); scene2->addItem(muros.back());
        muros.push_back(new pared(15, 80, 470, 200)); scene2->addItem(muros.back());
        muros.push_back(new pared(15, 80, 380, 60)); scene2->addItem(muros.back());
        muros.push_back(new pared(15, 80, 428, 135)); scene2->addItem(muros.back());
        muros.push_back(new pared(15, 80, 480, 60)); scene2->addItem(muros.back());
        muros.push_back(new pared(15, 80, 540, 130)); scene2->addItem(muros.back());
        muros.push_back(new pared(15, 80, 480, 350)); scene2->addItem(muros.back());
        muros.push_back(new pared(15, 80, 520, 270)); scene2->addItem(muros.back());
        muros.push_back(new pared(15, 100, 540, 420)); scene2->addItem(muros.back());
        muros.push_back(new pared(15, 230, 600, 200)); scene2->addItem(muros.back());
        muros.push_back(new pared(15, 80, 656, 130)); scene2->addItem(muros.back());
        muros.push_back(new pared(15, 80, 700, 60)); scene2->addItem(muros.back());
        muros.push_back(new pared(15, 230, 730, 200)); scene2->addItem(muros.back());
        muros.push_back(new pared(15, 80, 670, 430)); scene2->addItem(muros.back());

        //muros horizontales
        muros.push_back(new pared(100, 15, 340, 200)); scene2->addItem(muros.back()); //ancho, alto, posx , pos y
        muros.push_back(new pared(100, 15, 380, 270)); scene2->addItem(muros.back());
        muros.push_back(new pared(80, 15, 480, 200)); scene2->addItem(muros.back());
        muros.push_back(new pared(120, 15, 380, 420)); scene2->addItem(muros.back());
        muros.push_back(new pared(130, 15, 430, 350)); scene2->addItem(muros.back());
        muros.push_back(new pared(130, 15, 540, 130)); scene2->addItem(muros.back());
        muros.push_back(new pared(160, 15, 520, 270)); scene2->addItem(muros.back());
        muros.push_back(new pared(80, 15, 660, 200)); scene2->addItem(muros.back());
        muros.push_back(new pared(80, 15, 660, 350)); scene2->addItem(muros.back());
        muros.push_back(new pared(80, 15, 600, 420)); scene2->addItem(muros.back());
        muros.push_back(new pared(60, 5, 730, 300)); scene2->addItem(muros.back());


}

