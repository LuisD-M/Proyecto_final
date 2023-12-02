#include "enemy1.h"
#include <QDebug>

enemy1::enemy1(QObject *parent) : QObject{parent}
{
    pixmap1_2 = new QPixmap(":/Imagenes/Marciano.png");                     // inicializar puntero de QPixmap

    ancho = 87;                                                    //dimensiones imagen
    alto = 177;
}

enemy1::enemy1(int x, int y)
{
    posx = x;
    posy = y;
    setPos(posx,posy);
}

QRectF enemy1::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void enemy1::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2, -alto/2,*pixmap1_2,0,0,ancho,alto);
    setScale(0.31);
}

void enemy1::moveBy(heroe *heroeptr)
{
    QPointF heroPos = heroeptr->getPos();

    // Calcula la dirección hacia el héroe
    float dx = heroPos.x() - x();
    float dy = heroPos.y() - y();

    float angle = atan(dy/dx);

    if( heroPos.x() < x())
        angle = angle+3.1416;


    // Actualiza la posición del enemigo en la escena

    setPos(x() + velocidad * cos(angle) , y() + velocidad * sin(angle));
}

int enemy1::getPosx() const{
    return posx;
}

void enemy1::setPosx(int px){
    posx = px;
}

int enemy1::getPosy() const{
    return posy;
}

void enemy1::setPosy(int py){
    posy=py;
}

QPointF enemy1::getPos() const
{
    return mapToScene(0,0);
}

