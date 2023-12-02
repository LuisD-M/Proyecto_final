#include "rick.h"

rick::rick(QObject *parent) : heroe(parent)     //LLama al construrtor de  la clase general heroe
{
    pixmap1 = new QPixmap(":/Imagenes/Rick.png");                     // inicializar puntero de QPixmap
    setScale(0.20);
    ancho = 159;                                                    //dimensiones imagen
    alto = 315;
}

void rick::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2, -alto/2, *pixmap1, 0, 0, ancho, alto);

}
