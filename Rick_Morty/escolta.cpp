#include "escolta.h"

escolta::escolta(QObject *parent) : enemy1(parent)     //LLama al construrtor de  la clase general heroe
{
    pixmap1_2 = new QPixmap(":/Imagenes/Escolta.jpg");                     // inicializar puntero de QPixmap
    setScale(0.3);
    ancho = 105;                                                    //dimensiones imagen
    alto = 277;
}

void escolta::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2, -alto/2, *pixmap1_2, 0, 0, ancho, alto);

}
