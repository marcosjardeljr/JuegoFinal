#ifndef PARED_H
#define PARED_H
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>

class pared: public QGraphicsItem
{

    int w,h; //w = ancho, h = alto, pos x, pos y
    int posx, posy;

public:
    pared(int w_, int h_, int x, int y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void paintObstaculos(QPainter *paintObstaculos, const QStyleOptionGraphicsItem *option, QWidget *widget);

};
#endif
