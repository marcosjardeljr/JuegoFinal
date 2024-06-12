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

void enemigos::fuerzadeAtraccion(const QPointF &objetivo) {
    // Calcula la dirección hacia el objetivo restando la posición actual del enemigo
    QPointF direccion = objetivo - pos();

    // Calcula la longitud de la dirección usando la distancia euclidiana
    qreal longitud = qSqrt(qPow(direccion.x(), 2) + qPow(direccion.y(), 2));

    // Si la longitud es mayor que 0, normaliza la dirección y actualiza la posición del enemigo
    if (longitud > 0) {
        // Normaliza la dirección
        direccion /= longitud;

        // Actualiza la posición del enemigo moviéndolo en la dirección del objetivo
        setPos(pos() + direccion * scale());
    }
}
