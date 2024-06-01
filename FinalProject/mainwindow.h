#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pared.h"
#include "jugador.h"

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
    //void keyPressEvent(QKeyEvent *evento);


signals:


private:

    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QTimer *timer;
    jugador *mijugador;
    QVector<pared*> muros;  // Vector de punteros a pared

};

#endif // MAINWINDOW_H


