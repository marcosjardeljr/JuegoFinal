#ifndef MOVIMIENTOS_H
#define MOVIMIENTOS_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>


class movimientos
{
public:
    movimientos();
    //es static ya que se puede usar sin crear un objeto de la clase enemigos
    static void movimientoCircular(QGraphicsPixmapItem *fig4, QGraphicsScene *scene, qreal &angle, QPointF &posicionInicial);
    static bool EvaluarColisionMalos(QGraphicsItem *item,const QList<QGraphicsItem *> &items);
};

#endif // MOVIMIENTOS_H
