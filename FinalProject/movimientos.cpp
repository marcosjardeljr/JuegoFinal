#include "movimientos.h"
#include <cmath>

void movimientos::movimientoCircular(QGraphicsPixmapItem *bit, QGraphicsScene *scene, qreal &angle, QPointF &posicionInicial)
{
    qreal radio = 70;
    qreal x_ = radio * cos(angle);
    qreal y_ = radio * sin(angle);
    bit->setPos(x_ + posicionInicial.x(), y_ + posicionInicial.y());
    angle += 0.2;
}


bool movimientos::EvaluarColisionMalos(QGraphicsItem *item,const  QList<QGraphicsItem *> &items)
{
    for (QGraphicsItem *otroItem : items) {
        if (item->collidesWithItem(otroItem)) {
            return true;
        }
    }
    return false;
}

