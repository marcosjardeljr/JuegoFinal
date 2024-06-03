#include "escape.h"

escape::escape()
{

}

escape::escape(int x, int y, int an, int h)
{
    this->posx = x;
    this->posy = y;
    this->ancho = an;
    this->alto = h;

    setPos(posx,posy);
}

QRectF escape::boundingRect() const
{
    return QRectF(0,0,ancho,alto);
}

void escape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap tunel(":/imagenes/obstaculo2.jpg");
    painter->drawPixmap(boundingRect(),tunel,tunel.rect());
}

void escape::setVisible(bool visible)
{
    QGraphicsItem::setVisible(visible);
}
