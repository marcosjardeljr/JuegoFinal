#ifndef MOVIMIENTOS_H
#define MOVIMIENTOS_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <iostream>
#include <fstream>
#include <cmath>
#include <QPointF>

class movimientos
{
public:
    movimientos();
    //es static ya que se puede usar sin crear un objeto de la clase enemigos
    static void movimientoCircular(QGraphicsPixmapItem *enemigo,  qreal &angle, QPointF &posicionInicial);
    static void caidaLibre(QGraphicsPixmapItem *enemigo, QPointF initialPos);
    static void movimientoEliptico(QGraphicsPixmapItem *bitone, qreal &angle2, QPointF posicionInicial);
    static bool EvaluarColisionMalos(QGraphicsItem *item,const QList<QGraphicsItem *> &items);

};

#endif // MOVIMIENTOS_H
