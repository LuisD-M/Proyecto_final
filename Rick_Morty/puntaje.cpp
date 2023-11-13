#include "puntaje.h"
#include <QFont>

puntaje::puntaje(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    puntuacion = 0;
    setPlainText(QString("Puntaje: ") + QString::number(puntuacion));
    setDefaultTextColor(Qt::red);
    setFont(QFont("Comic Sans MS",13));
}

void puntaje::increaseN1(){
    puntuacion++;
    setPlainText(QString("Puntaje: ") + QString::number(puntuacion));
}

int puntaje::getpuntaje(){
    return puntuacion;
}

void puntaje::setPuntuacion(int newPuntuacion)
{
    puntuacion = newPuntuacion;
}

