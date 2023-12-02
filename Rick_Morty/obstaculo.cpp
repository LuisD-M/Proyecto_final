#include "obstaculo.h"

Obstaculo::Obstaculo(const QRectF &sceneSize, const float scale, QGraphicsItem* im)
{
    setPixmap(QPixmap(":/Imagenes/escombro.png"));
    setScale(0.012*scale);
    setPos(sceneSize.width(),sceneSize.height()-this->boundingRect().height()*this->scale());
}

Obstaculo::~Obstaculo()
{

}

void Obstaculo::moveBy(int x, int y)
{
    setPos(this->x()+x,this->y()+y);
}

void Obstaculo::move()
{
    setPos(this->x()-vel,this->y());
}

//


int Obstaculo::getVel() const
{
    return vel;
}
