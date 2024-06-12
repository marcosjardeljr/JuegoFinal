#ifndef ENEMIGOS_H
#define ENEMIGOS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QGraphicsScene>
#include <QPointF>

class enemigos : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    //el explicit es porque el constructor solo crea objetos clase enemigo.
    //QObject *parent = nullptr indica que es hijo de la clase Qobjet
    explicit enemigos(QGraphicsScene* scene, QPixmap pixmap, qreal scale, QPointF pos, QObject *parent = nullptr);
    ~enemigos();
    void fuerzadeAtraccion(const QPointF &target);

private:
    //configuracion de la clase.
    void setup(QPixmap pixmap, qreal scale, QPointF pos);
    qreal speed;
    QGraphicsScene *scene2;

signals:

};

#endif // ENEMIGOS_H
