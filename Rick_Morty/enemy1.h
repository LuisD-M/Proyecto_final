#ifndef ENEMY1_H
#define ENEMY1_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QWidget>

class enemy1 : public QObject, public QGraphicsItem
{
    Q_OBJECT

private:
    int posx=0, posy=0;
    int velocidad=10;
    QPixmap *pixmap1_2;


public:
    explicit enemy1(QObject *parent = nullptr);

    enemy1(int x, int y);                       // Constructor para inicializar  las posiciones posx e posy del sprite
    //ddddddenemy1(QPixmap* pixmap1_2);


    //QPixmap *pixmap1_2;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int getPosx() const;
    void setPosx(int px);
    int getPosy() const;
    void setPosy(int py);

    QPointF getPos() const;
    //QPixmap *getElip() const;
    //void setElip(QPixmap *newPixmap);

    void moveBy(int x, int y);

    float ancho, alto;

};

#endif // ENEMY1_H
