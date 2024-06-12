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

    QString rutaMalo3 = ":/imagenes/bit0.png";
    QPixmap malo3(rutaMalo3);
    bitPos = QPointF(250,250);
    bit = new enemigos(scene, malo3, 0.04, bitPos);

    QString rutaMalo4 = ":/imagenes/bit1.png";
    QPixmap malo4(rutaMalo4);
    bitonePos = QPointF(600,250);
    bitone = new enemigos(scene, malo4, 0.05, bitonePos);

    QString rutaMalo10= ":/imagenes/grenade.png";
    QPixmap malo10(rutaMalo10);
    granadaPos = QPointF(750,100);
    granada = new enemigos(scene, malo10, 0.02, granadaPos);



    QString rutaTrampa = ":/imagenes/trampa.png";
    QPixmap malo12(rutaTrampa);
    trampaPos = QPointF(400,455);
    trampa = new enemigos(scene, malo12, 0.06, trampaPos);

    trampaPos = QPointF(430,455);
    trampa1 = new enemigos(scene, malo12, 0.06, trampaPos);

    trampaPos = QPointF(370,455);
    trampa2 = new enemigos(scene, malo12, 0.06, trampaPos);

    trampaPos = QPointF(340,455);
    trampa3 = new enemigos(scene, malo12, 0.06, trampaPos);

    trampaPos = QPointF(600,455);
    trampa4 = new enemigos(scene, malo12, 0.06, trampaPos);

    /* Recreamos todos los elementos que debemos capturar para crear la maquina */

    QString rutaElemen1 = ":/imagenes/elemento1maquina.png";
    QPixmap elemen1(rutaElemen1);
    elementoPos = QPointF(400,420);
    elemento = new enemigos(scene, elemen1, 0.03, elementoPos);

    QString rutaElemen2 = ":/imagenes/elemento2maquina.png";
    QPixmap elemen2(rutaElemen2);
    elementoPos2 = QPointF(880,420);
    elemento2 = new enemigos(scene, elemen2, 0.03, elementoPos2);

    QString rutaElemen3 = ":/imagenes/elemento3maquina.png";
    QPixmap elemen3(rutaElemen3);
    elementoPos3 = QPointF(580,120);
    elemento3 = new enemigos(scene, elemen3, 0.03, elementoPos3);

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


    if (mijugador->collidesWithItem(trampa)){
         QMessageBox::about(this, "Adios", "\n\n Perdiste :(");
         timer->stop();
         exit(0);
    }


    if (mijugador->collidesWithItem(trampa1)){
         QMessageBox::about(this, "Adios", "\n\n Perdiste :(");
         timer->stop();
         exit(0);
    }


    if (mijugador->collidesWithItem(trampa2)){
         QMessageBox::about(this, "Adios", "\n\n Perdiste :(");
         timer->stop();
         exit(0);
    }

    if (mijugador->collidesWithItem(trampa3)){
         QMessageBox::about(this, "Adios", "\n\n Perdiste :(");
         timer->stop();
         exit(0);
    }

    if (mijugador->collidesWithItem(trampa4)){
         QMessageBox::about(this, "Adios", "\n\n Perdiste :(");
         timer->stop();
         exit(0);
    }


    if (mijugador->collidesWithItem(elemento)){
         elemento->setVisible(false);
    }
    if (mijugador->collidesWithItem(elemento2)){
         elemento2->setVisible(false);
    }
    if (mijugador->collidesWithItem(elemento3)){
         elemento3->setVisible(false);
    }

    // Evaluamos colision con el túnel
    if (tunel1 != nullptr && mijugador != nullptr) {
        // Verifica colisiones
        if (mijugador->collidesWithItem(elemento))
        {
            colisionConElemento1 = true;
        }

        if (mijugador->collidesWithItem(elemento2))
        {
            colisionConElemento2 = true;
        }
        if (mijugador->collidesWithItem(elemento3))
        {
            colisionConElemento3 = true;
        }
        // Muestra el túnel solo si se han producido ambas colisiones
        if ((colisionConElemento1 == colisionConElemento2) && (colisionConElemento1 == colisionConElemento3))
        {
            tunel1->setVisible(true);
        }

        // Si el túnel está visible, verifica la colisión
        if (mijugador != nullptr && tunel1->isVisible() && mijugador->collidesWithItem(tunel1))
        {
            // Cambiamos de nivel
            level = true;
            // timer->stop();
            cambiarNivel();
            return;  // Importante: salimos de la función para evitar operaciones adicionales después de cambiar de nivel
        }
    }

    }
    if (level == true){


        // Evaluamos colision con los enemigos
        if (mijugador != nullptr && movimientos::EvaluarColisionMalos(mijugador, QList<QGraphicsItem*>(listaEnemigos.begin(), listaEnemigos.end()))) {
            QMessageBox::about(this, "Adios", "\n\n Perdiste :(");
            timer->stop();
            exit(0);
        }
        if (soga != nullptr) {

            // Si el túnel está visible, verifica la colisión
            if (mijugador != nullptr && mijugador->collidesWithItem(soga)) {
                QMessageBox::about(this, "Adios", "Alan Turing fallece el 7 de junio de 1954");
                timer->stop();
                exit(0);

                return;
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

        // Crea una nueva escena
        ui->setupUi(this);
        scene2 = new QGraphicsScene;
        ui->graphicsView->setScene(scene2);
        QImage nuevoFondo(":/imagenes/newCircuito.png");
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
        mijugador->setPos(90, 150);
        qDebug() << "Se cambia de nivel efectivamente";

        //fila superior
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
        muros.push_back(new pared(15, 100, 230, 410)); scene2->addItem(muros.back());
        muros.push_back(new pared(15, 300, 230, 50)); scene2->addItem(muros.back());
        muros.push_back(new pared(15, 80, 840, 350)); scene2->addItem(muros.back());
        muros.push_back(new pared(15, 80, 840, 200)); scene2->addItem(muros.back());
        muros.push_back(new pared(15, 80, 890, 130)); scene2->addItem(muros.back());
        muros.push_back(new pared(15, 100, 150, 334)); scene2->addItem(muros.back());
        muros.push_back(new pared(15, 100, 112, 334)); scene2->addItem(muros.back());

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
        muros.push_back(new pared(60, 15, 785, 350)); scene2->addItem(muros.back());
        muros.push_back(new pared(50, 15, 840, 420)); scene2->addItem(muros.back());
        muros.push_back(new pared(60, 15, 900, 350)); scene2->addItem(muros.back());
        muros.push_back(new pared(120, 15, 850, 280)); scene2->addItem(muros.back());
        muros.push_back(new pared(110, 15, 780, 130)); scene2->addItem(muros.back());
        muros.push_back(new pared(80, 15, 150, 334)); scene2->addItem(muros.back());
        muros.push_back(new pared(50, 15, 112, 430)); scene2->addItem(muros.back());
        muros.push_back(new pared(100, 15, 60, 250)); scene2->addItem(muros.back());
        muros.push_back(new pared(100, 15, 130, 170)); scene2->addItem(muros.back());

        QString rutaPildora = ":/imagenes/pildora.png";
        QPixmap maloP(rutaPildora);
        pildoraPos = QPointF(380,150);
        pildora = new enemigos(scene2, maloP, 0.03, pildoraPos);

        QString rutaPerseguidor = ":/imagenes/person.png";
        QPixmap maloH(rutaPerseguidor);
        perseguidorPos = QPointF(100,80);
        perseguidor = new enemigos(scene2, maloH, 0.04, perseguidorPos);

        QString rutaPsoga = ":/imagenes/soga.png";
        QPixmap maloS(rutaPsoga);
        sogaPos = QPointF(800,70);
        soga = new enemigos(scene2, maloS, 0.11, sogaPos);

        QString rutaApple = ":/imagenes/manzana.png";
        QPixmap maloA(rutaApple);
        applePos = QPointF(400,220);
        apple = new enemigos(scene2, maloA, 0.06, applePos);

        // Añadir enemigos a la escena
        scene2->addItem(pildora);
        scene2->addItem(perseguidor);
        scene2->addItem(apple);
        // Temporizador para actualizar las posiciones de los enemigos
        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &MainWindow::actualizacionEnemigos);
        timer->start(7);

     listaEnemigos = {pildora,perseguidor,apple};

}

void MainWindow::actualizacionEnemigos() {
    QPointF playerPos = mijugador->pos();
    pildora->fuerzadeAtraccion(playerPos);
    perseguidor->fuerzadeAtraccion(playerPos);
    apple->fuerzadeAtraccion(playerPos);
}
