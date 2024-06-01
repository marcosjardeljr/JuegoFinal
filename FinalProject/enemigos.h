#ifndef ENEMIGOS_H
#define ENEMIGOS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QGraphicsScene>

class enemigos : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    //el explicit es porque el constructor solo crea objetos clase enemigo.
    //QObject *parent = nullptr indica que es hijo de la clase Qobjet
    explicit enemigos(QGraphicsScene* scene, QPixmap pixmap, qreal scale, QPointF pos, QObject *parent = nullptr);
    ~enemigos();

private:
    //configuracion de la clase.
    void setup(QPixmap pixmap, qreal scale, QPointF pos);

signals:

};

#endif // ENEMIGOS_H
