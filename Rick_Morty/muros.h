#ifndef MUROS_H
#define MUROS_H

#include <QGraphicsItem>
#include <QPainter>

class muros : public QGraphicsItem
{
    int posx, posy;
    int w, h;


public:
    muros();
    muros(int w, int h, int x, int y);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);   //dibujar paredes en la escena
    QRectF boundingRect() const;       //delimita la pared en la escena

};

#endif // MUROS_H
