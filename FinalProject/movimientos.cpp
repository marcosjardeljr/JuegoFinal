#include "movimientos.h"
#include <cmath>
using namespace std;

void movimientos::movimientoCircular(QGraphicsPixmapItem *bit, qreal &angle, QPointF &posicionInicial)
{
    qreal radio = 70;
    qreal x_ = radio * cos(angle);
    qreal y_ = radio * sin(angle);
    bit->setPos(x_ + posicionInicial.x(), y_ + posicionInicial.y());
    angle += 0.7;
}

void movimientos::caidaLibre(QGraphicsPixmapItem *granada, QPointF initialPos)
{
    granada->setPos(granada->pos().x(), granada->pos().y() + 5);
    if (granada->pos().y() + 2 < 515)
        granada->setPos(granada->pos().x(), granada->pos().y() + 5);
    else
        granada->setPos(initialPos);
}

void movimientos::movimientoParabolico(QGraphicsPixmapItem *canon, qreal &tiempo)
{
    qreal velocidadInicialX = 1;
    qreal velocidadInicialY = -4;
    //qreal gravedad = 4.4;

    qreal xp = velocidadInicialX * tiempo;
    qreal yp = velocidadInicialY * tiempo + (0.2 * tiempo );

    canon->setPos(canon->pos().x() - xp + yp, canon->pos().y() -xp );
    tiempo += 0.01;
}

bool movimientos::EvaluarColisionMalos(QGraphicsItem *item, const  QList<QGraphicsItem *> &items)
{
    for (QGraphicsItem *otroItem : items) {
        if (item->collidesWithItem(otroItem)) {
            return true;
        }
    }
    return false;
}

void movimientos::movimientoEliptico(QGraphicsPixmapItem *bitone, qreal &angle2, QPointF posicionInicial) {
    qreal radioX = 50;
    qreal radioY = 30;
    qreal x = radioX * cos(angle2);
    qreal y = radioY * sin(angle2);
    bitone->setPos(x + posicionInicial.x(), y + posicionInicial.y());

    // Abrir archivo para escritura
    ofstream archivoPos("ArchivoPos.txt", ios::out | ios::app);

    if (!archivoPos) {
        cerr << "No se pudo abrir el archivo ArchivoPos.txt" << endl;
        return;
    }

    // Escribir la posición en el archivo
    archivoPos << "Posición: (" << x + posicionInicial.x() << ", " << y + posicionInicial.y() << ")\n";

    // Cerrar archivo
    archivoPos.close();

    angle2 -= 0.5;
}

