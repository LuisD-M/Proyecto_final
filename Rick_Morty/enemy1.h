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

protected:
    QPixmap *pixmap1_2;
    float ancho, alto;
    heroe *heroeptr;             //puntero al heroe

public:
    explicit enemy1(QObject *parent = nullptr);
    ~enemy1();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QPointF getPos() const;
    void moveBy(heroe *heroeptr);


};

#endif // ENEMY1_H


