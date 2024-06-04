#include "pared.h"

pared::pared(int w_, int h_, int x, int y)
{
    w = w_;
    h = h_;
    posx = x;
    posy = y;


}


QRectF pared::boundingRect() const
{
    return QRectF(posx, posy, w, h);
}

void pared::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Definir la ruta del sprite
    QString spritePath = ":/imagenes/obstaculo1.jpg";

    // Cargar el sprite
    QImage sprite(spritePath);

    // Verificar si la carga del sprite fue exitosa
    if (sprite.isNull()) {
        painter->setBrush(Qt::red);
        painter->drawRect(boundingRect());
        return;
    }

    // Dibujar el sprite en lugar del rectángulo gris
    painter->drawImage(boundingRect(), sprite);

    //muros escena dos

    QString spritePath2 = ":/imagenes/obstaculo2.jpg";

    // Cargar el sprite
    QImage sprite2(spritePath2);

    // Verificar si la carga del sprite fue exitosa
    if (sprite2.isNull()) {
        painter->setBrush(Qt::blue);
        painter->drawRect(boundingRect());
        return;
    }

    // Dibujar el sprite en lugar del rectángulo gris
    painter->drawImage(boundingRect(), sprite);
}
