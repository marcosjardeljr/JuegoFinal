#include "jugador.h"

jugador::jugador(QGraphicsScene* scene, QObject *parent) : QObject(parent), QGraphicsPixmapItem()
{
    setScale(0.1);
    setPos(-450, -60);
    setup();
    scene->addItem(this);
}

jugador::~jugador()
{

}



void jugador::setup()
{
    QPixmap pj2(":/imagenes/cientifico2.jpg");
    setPixmap(pj2);
}
