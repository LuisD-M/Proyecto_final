#include "heroe.h"
#include <QDebug>

heroe::heroe(QObject *parent) : QObject{parent}
{
    timer1 = new QTimer();                                           // inicializar puntero de Qtimer
    pixmap1 = new QPixmap(":/Imagenes/Rick.jpg");                     // inicializar puntero de QPixmap

    columnas = 0;

    //dimensiones imagen
    ancho = 140;
    alto = 140;
    timer1->start(100);                                                // definir el timer de 100 ms
    connect(timer1,&QTimer::timeout, this,&heroe::Actualizacion);                 // conectar el slot
    setPos(20,20);                                                  // establecer la posición inicial del sprite en la escena

}

heroe::sprite(int x, int y)
{
    posx = x;
    posy = y;
    setPos(posx,posy);                                          // establecer la posicion del sprite en la escena

}

QRectF heroe::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto); // delimitador del sprite

}

void heroe::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2, -alto/2,*pixmap1,columnas,0,ancho,alto);
    setScale(0.29);
}

void heroe::Actualizacion()
{
    columnas += 140;                       // aumentar 140 para cambiar la posición de la imagen del sprite en la spritesheet.
    if(columnas >= 420){
        columnas = 0;                                               // Si columnas es 400, se reinicia a cero
    }
    this->update(-ancho/2,-alto/2,ancho,alto);                      //  actualizar la apariencia visual del sprite
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

