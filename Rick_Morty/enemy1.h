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
#include <cmath>

#include "heroe.h"


class enemy1 : public QObject, public QGraphicsItem
{
    Q_OBJECT

private:
    float velocidad = 0.1;
    int velocidad=10;

protected:
    QPixmap *pixmap1_2;
    float ancho, alto;
    heroe *heroeptr;             //puntero al heroe

public:
    explicit enemy1(QObject *parent = nullptr);
    ~enemy1();

    enemy1(int x, int y);                       // Constructor para inicializar  las posiciones posx e posy del sprite

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int getPosx() const;
    void setPosx(int px);
    int getPosy() const;
    void setPosy(int py);
    QPointF getPos() const;
    void moveBy(heroe *heroeptr);


};

#endif // ENEMY1_H


