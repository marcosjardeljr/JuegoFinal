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
    void updateEnemies();

signals:


private:

    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsScene *scene2;
    QTimer *timer;
    jugador *mijugador;
    QVector<pared*> muros;  // Vector de punteros a pared
    QVector<pared*> muros2;
    escape *tunel1;
    //Enemigos nivel 1
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
    enemigos *trampa1;
    enemigos *trampa2;
    enemigos *trampa3;
    enemigos *trampa4;
    QPointF trampaPos;
    enemigos *granada;
    QPointF granadaPos;
    enemigos *canon;
    QPointF canonPos;
    enemigos *bala;
    QPointF balaPos;


    //Elementos nivel 1
    enemigos *elemento;
    QPointF elementoPos;

    enemigos *elemento2;
    QPointF elementoPos2;

    enemigos *elemento3;
    QPointF elementoPos3;

    bool colisionConElemento1;
    bool colisionConElemento2;
    bool colisionConElemento3;

    //Movimientos
    qreal angle;   // Para el movimiento circular
    qreal angle2;   // Para el movimiento eliptico
    qreal angle3;   // Para el movimiento parabolico

    bool EvaluarColision(QGraphicsItem *item); // Evaluamos las colisiones con los enemigos

    //enemigos segundo nivel
    enemigos *perseguidor;
    QPointF perseguidorPos;
    enemigos *pildora;
    QPointF pildoraPos;
    enemigos *soga;
    QPointF sogaPos;
    enemigos *apple;
    QPointF applePos;

};

#endif // MAINWINDOW_H


