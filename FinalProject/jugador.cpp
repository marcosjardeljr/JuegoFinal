#include "jugador.h"

jugador::jugador(QGraphicsScene* scene, QObject *parent) : QObject(parent), QGraphicsPixmapItem()
{
    setScale(0.13);
    setPos(70, 70);
    setup();
    scene->addItem(this);
}

jugador::~jugador()
{

}



void jugador::setup()
{
    QPixmap pj2(":/imagenes/image001.png");
    setPixmap(pj2);
}
