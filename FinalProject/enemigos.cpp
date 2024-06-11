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

void enemigos::moveTowards(const QPointF &target) {
    QPointF direction = target - pos();
    qreal length = qSqrt(qPow(direction.x(), 2) + qPow(direction.y(), 2));
    if (length > 0) {
        direction /= length;
        setPos(pos() + direction * scale());
    }
}
