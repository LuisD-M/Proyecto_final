#include "heroe.h"
#include <QDebug>

heroe::heroe(QObject *parent) : QObject{parent}
{
    timer1 = new QTimer();                                           // inicializar puntero de Qtimer
    pixmap1 = new QPixmap(":/Imagenes/Rick.png");                     // inicializar puntero de QPixmap

    columnas = 0;

    ancho = 159;                                                    //dimensiones imagen
    alto = 315;
}

heroe::sprite(int x, int y)
{
    posx = x;
    posy = y;
    setPos(posx,posy);                                          // establecer la posicion del sprite en la escena
}

QRectF heroe::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);                                  // delimitador del sprite
}

void heroe::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2, -alto/2,*pixmap1,columnas,0,ancho,alto);
    setScale(0.25);
}

void heroe::moveBy(int x, int y)
{
    posy +=y;
    posx +=x;
    setPos(posx,posy);
}

int heroe::getPosx() const{
    return posx;
}

void heroe::setPosx(int px){
    posx = px;
}

int heroe::getPosy() const{
    return posy;
}

void heroe::setPosy(int py){
    posy=py;
}

QPointF heroe::getPos() const
{
    return mapToScene(0,0);
}





