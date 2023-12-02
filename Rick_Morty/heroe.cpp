#include "heroe.h"
#include <QDebug>

heroe::heroe(QObject *parent) : QObject{parent}
{
    pixmap1 = nullptr;
}


heroe::~heroe()
{
    delete pixmap1;
}

QRectF heroe::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);                                  // delimitador del sprite
}

void heroe::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2, -alto/2,*pixmap1,0,0,ancho,alto);
}

void heroe::moveBy(int x, int y)
{

    setPos(this->x()+x,this->y()+y);
}

QPointF heroe::getPos() const
{
    return mapToScene(0,0);
}

void heroe::smallRect()
{
    if (small) return;
    this->setScale(scale2);
    this->setPos(this->x(),this->y()+(this->boundingRect().height()*scale1 - this->boundingRect().height()*scale2));

    small = true;
}
void heroe::bigRect()
{
    if (!small) return;
    this->setScale(scale1);
    this->setPos(this->x(),this->y()-(this->boundingRect().height()*scale1 - this->boundingRect().height()*scale2));
    small = false;
}

void heroe::jump(float vely)
{
    if (!jumped)
    {
        this->vely = vely;
        jumped = true;
    }
}

void heroe::acelerateBy(float x, int sceneHeight)
{
    if (this->y()+this->boundingRect().height()*this->scale() < sceneHeight || vely < 0)
    {
        vely += 0.22;
        setPos(this->x()+x,this->y()+vely);
    }else
    {
        jumped = false;
    }
}

void heroe::setLevel3Scale()
{
    this->setScale(scale1);
}
