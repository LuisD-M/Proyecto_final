#include "alien.h"

alien::alien(QObject *parent) : enemy1(parent)     //LLama al construrtor de  la clase general heroe
{
    pixmap1_2 = new QPixmap(":/Imagenes/Marciano.png");                     // inicializar puntero de QPixmap
    setScale(0.3);
    ancho = 87;                                                    //dimensiones imagen
    alto = 177;
}

void alien::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2, -alto/2, *pixmap1_2, 0, 0, ancho, alto);

}
