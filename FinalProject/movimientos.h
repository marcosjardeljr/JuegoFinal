#ifndef MOVIMIENTOS_H
#define MOVIMIENTOS_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>


class movimientos
{
public:
    movimientos();
    //es static ya que se puede usar sin crear un objeto de la clase enemigos
    static void movimientoCircular(QGraphicsPixmapItem *enemigo,  qreal &angle, QPointF &posicionInicial);
    static void movimientoEliptico(QGraphicsPixmapItem *enemigo, qreal &angle2, QPointF initialPos);
    static void caidaLibre(QGraphicsPixmapItem *enemigo, QPointF initialPos);
    static void movimientoParabolico(QGraphicsPixmapItem *enemigo, qreal &tiempo);

    static bool EvaluarColisionMalos(QGraphicsItem *item,const QList<QGraphicsItem *> &items);
};

#endif // MOVIMIENTOS_H
