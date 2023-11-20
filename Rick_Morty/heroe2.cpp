#include "heroe2.h"

heroe2::heroe2(QObject *parent) : heroe(parent)     //LLama al construrtor de  la clase general heroe
{
    pixmap1 = new QPixmap(":/Imagenes/Morty.png");
}

void heroe2::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2, -alto/2, *pixmap1, 0, 0, ancho, alto);
    setScale(0.20);
}
