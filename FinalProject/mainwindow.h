#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pared.h"
#include "jugador.h"
#include "enemigos.h"

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
    void moverJugador();


signals:


private:

    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QTimer *timer;
    jugador *mijugador;
    QVector<pared*> muros;  // Vector de punteros a pared
    QList<enemigos *> listaEnemigos;
    enemigos *soldado;
    QPointF soldadoPos;

    bool EvaluarColision(QGraphicsItem *item); // Evaluamos las colisiones con los enemigos

};

#endif // MAINWINDOW_H


