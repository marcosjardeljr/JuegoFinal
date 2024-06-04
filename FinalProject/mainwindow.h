#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pared.h"
#include "jugador.h"
#include "enemigos.h"
#include "escape.h"

QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void keyPressEvent(QKeyEvent *evento);
    void movEnemigos();
    void cambiarNivel();

signals:


private:

    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsScene *scene2;
    QTimer *timer;
    jugador *mijugador;
    QVector<pared*> muros;  // Vector de punteros a pared
    escape *tunel1;
    //Enemigos
    QList<enemigos *> listaEnemigos;

    enemigos *soldado;
    QPointF soldadoPos;
    enemigos *avion;
    QPointF avionPos;
    enemigos *bit;
    QPointF bitPos;
    enemigos *bitone;
    QPointF bitonePos;
    enemigos *trampa;
    QPointF trampaPos;
    enemigos *granada;
    QPointF granadaPos;
    enemigos *canon;
    QPointF canonPos;


    //Movimientos
    qreal angle;   // Para el movimiento circular
    qreal angle2;   // Para el movimiento eliptico
    qreal angle3;   // Para el movimiento parabolico

    bool EvaluarColision(QGraphicsItem *item); // Evaluamos las colisiones con los enemigos

};

#endif // MAINWINDOW_H


