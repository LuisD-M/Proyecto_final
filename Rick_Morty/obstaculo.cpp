#include "obstaculo.h"

Obstaculo::Obstaculo()
{
    pixmap = new QPixmap(":/Imagenes/escombro.png");
}

Obstaculo::Obstaculo(const QRectF &sceneSize,const int ancho, const int alto, QObject *parent): QObject{parent}
{
    pixmap = new QPixmap(":/Imagenes/escombro.png");
    setRect(new QGraphicsRectItem(0,0,ancho,alto));
    setPos(sceneSize.width(), sceneSize.height()-this->getHeight());
}

Obstaculo::~Obstaculo()
{
    delete pixmap;
}

void Obstacle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    float scaledHeight = this->getWidth()*2;

    // Draw the scaled pixmap on the obstacle
    painter->drawPixmap(this->getWidth, scaledHeight, *pixmap,0,0,);
}

int Obstaculo::getX() const
{
    return this->x();
}
//void Obstaculo::setX(int x)
//{
//    this->setX(x);
//}
//int Obstaculo::getY() const
//{
//    return this->y();
//}
//void Obstaculo::setY(int y)
//{
//    this->setY(y);
//}
//QPointF Obstaculo::getPos() const
//{
//    return this->scenePos();
//}
//void Obstaculo::setPos(QPointF pos)
//{
//    this->setPos(pos);
//}
//void Obstaculo::setPos(int x, int y)
//{
//    this->setPos(x,y);
//}

void Obstaculo::moveBy(int x, int y)
{
    this->setPos(this->x()+x,this->y()+y);
}

void Obstaculo::move()
{
    this->setPos(this->x()-vel,this->y());
}

//


int Obstaculo::getVel() const
{
    return vel;
}


int Obstaculo::getWidth() const
{
    return this->getRect()->rect().width();
}

int Obstaculo::getHeight() const
{
    return this->getRect()->rect().height();
}
