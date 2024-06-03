#ifndef ESCAPE_H
#define ESCAPE_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>

class escape : public QGraphicsItem
{
    int posx;
    int posy;
    int ancho;
    int alto;
public:
    QRectF boundingRect() const;
    void paint(QPainter *painte, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    escape();
    escape(int x, int y, int an, int h);
    void setVisible(bool visible);
};

#endif // ESCAPE_H
