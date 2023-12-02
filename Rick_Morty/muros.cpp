#include "muros.h"

muros::muros(){}

muros::muros(int w, int h, int x, int y)
{
    this->posx = x;
    this->posy = y;
    this->w = w;
    this->h = h;
}

void muros::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen(Qt::blue);                     //Crea la plumma para dibujar con Color azul
    pen.setWidth(2);                        //Ancho de la linea
    painter->setPen(pen);                   //Conecta la pluma para dibuhar
    painter->setBrush(Qt::black);           //Se desabilita el relleno
    qreal radius = 1.0;                    //radio de curva esquinas
    painter->drawRoundedRect(boundingRect(), radius, radius);
}

QRectF muros::boundingRect() const
{
    return QRectF(posx, posy, w, h);
}
