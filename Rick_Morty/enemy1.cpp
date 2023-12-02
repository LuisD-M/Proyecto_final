#include "enemy1.h"
#include <QDebug>

enemy1::enemy1(QObject *parent) : QObject{parent}
{
    pixmap1_2 = nullptr;                     // inicializar puntero de QPixmap
}

enemy1::enemy1(int x, int y)
{
    posx = x;
    posy = y;
    setPos(posx,posy);
}

enemy1::~enemy1()
{
    delete pixmap1_2;
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

void enemy1::moveBy(int x, int y)
{
    posy +=y;
    posx +=x;
    setPos(posx,posy);
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

