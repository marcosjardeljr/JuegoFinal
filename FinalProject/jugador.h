#ifndef JUGADOR_H
#define JUGADOR_H
#include <QMainWindow>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QGraphicsScene>

class jugador : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit jugador(QGraphicsScene* scene, QObject *parent = nullptr);
    ~jugador();

private:
    void setup();

signals:

};
#endif // jugador_H
