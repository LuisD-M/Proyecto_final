#include "obstaculo.h"

Obstaculo::Obstaculo()
{

}

Obstaculo::Obstaculo(QGraphicsRectItem* rect)
{
    this->rect = rect;
}

Obstaculo::Obstaculo(const QRectF &sceneSize,const QRectF &size)
{
    rect = new QGraphicsRectItem(0,0,size.width(),size.height());
    rect->setPos(sceneSize.width(), sceneSize.height()-size.height());
}

Obstaculo::Obstaculo(const QRectF &sceneSize,const int width, const int height)
{
    rect = new QGraphicsRectItem(0,0,width,height);
    rect->setPos(sceneSize.width(), sceneSize.height()-height);
}

Obstaculo::~Obstaculo()
{
    delete rect;
}

int Obstaculo::getX() const
{
    return rect->x();
}
void Obstaculo::setX(int x)
{
    rect->setX(x);
}
int Obstaculo::getY() const
{
    return rect->y();
}
void Obstaculo::setY(int y)
{
    rect->setY(y);
}
QPointF Obstaculo::getPos() const
{
    return rect->scenePos();
}
void Obstaculo::setPos(QPointF pos)
{
    rect->setPos(pos);
}
void Obstaculo::setPos(int x, int y)
{
    rect->setPos(x,y);
}

void Obstaculo::moveBy(int x, int y)
{
    rect->setPos(rect->x()+x,rect->y()+y);
}

void Obstaculo::move()
{
    rect->setPos(rect->x()-vel,rect->y());
}

//


int Obstaculo::getVel() const
{
    return vel;
}

QGraphicsRectItem *Obstaculo::getRect() const
{
    return rect;
}

void Obstaculo::setRect(QGraphicsRectItem *newRect)
{
    rect = newRect;
}

int Obstaculo::getWidth() const
{
    return rect->rect().width();
}

int Obstaculo::getHeight() const
{
    return rect->rect().height();
}
