#include "enemigos.h"


enemigos::enemigos(QGraphicsScene* scene, QPixmap pixmap, qreal scale, QPointF pos, QObject *parent)
    : QObject(parent), QGraphicsPixmapItem()
{
    setup(pixmap, scale, pos);
    scene->addItem(this);
}

enemigos::~enemigos()
{

}

void enemigos::setup(QPixmap pixmap, qreal scale, QPointF pos)
{
    this->setPixmap(pixmap);
    this->setScale(scale);
    this->setPos(pos);
}
