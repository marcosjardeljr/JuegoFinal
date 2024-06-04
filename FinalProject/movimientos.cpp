#include "movimientos.h"
#include <cmath>

void movimientos::movimientoCircular(QGraphicsPixmapItem *bit, qreal &angle, QPointF &posicionInicial)
{
    qreal radio = 70;
    qreal x_ = radio * cos(angle);
    qreal y_ = radio * sin(angle);
    bit->setPos(x_ + posicionInicial.x(), y_ + posicionInicial.y());
    angle += 0.7;
}

void movimientos::movimientoEliptico(QGraphicsPixmapItem *bitone, qreal &angle2, QPointF posicionInicial)
{
    qreal radioX = 50;
    qreal radioY = 30;
    qreal x = radioX * cos(angle2);
    qreal y = radioY * sin(angle2);
    bitone->setPos(x + posicionInicial.x(), y + posicionInicial.y());
    angle2 -= 0.5;
}

void movimientos::caidaLibre(QGraphicsPixmapItem *granada, QPointF initialPos)
{
    granada->setPos(granada->pos().x(), granada->pos().y() + 5);
    if (granada->pos().y() + 2 < 515)
        granada->setPos(granada->pos().x(), granada->pos().y() + 5);
    else
        granada->setPos(initialPos);
}

void movimientos::movimientoParabolico(QGraphicsPixmapItem *canon, qreal &tiempo)
{
    qreal velocidadInicialX = 1;
    qreal velocidadInicialY = -1;
    qreal gravedad = 4.4;

    qreal xp = velocidadInicialX * tiempo;
    qreal yp = velocidadInicialY * tiempo + (0.5 * gravedad * tiempo * tiempo);

    canon->setPos(canon->pos().x() - xp, canon->pos().y() -xp );
    tiempo += 0.2;
}

bool movimientos::EvaluarColisionMalos(QGraphicsItem *item, const  QList<QGraphicsItem *> &items)
{
    for (QGraphicsItem *otroItem : items) {
        if (item->collidesWithItem(otroItem)) {
            return true;
        }
    }
    return false;
}

