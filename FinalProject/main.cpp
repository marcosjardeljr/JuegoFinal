#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QIcon>
#include <QTimer>
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/imagenes/alan turing (1).png"));
    splash->show();

    MainWindow w;
    QTimer::singleShot(5000,splash,&QSplashScreen::close);
    QTimer::singleShot(5100,&w,&MainWindow::show);
    return a.exec();

}
