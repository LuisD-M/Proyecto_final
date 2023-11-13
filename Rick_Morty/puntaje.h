#ifndef PUNTAJE_H
#define PUNTAJE_H

#include <QObject>
#include <QGraphicsTextItem>
#include <QGraphicsItem>
#include <QGraphicsScene>

class puntaje : public QGraphicsTextItem
{
    Q_OBJECT

public:
    puntaje(QGraphicsItem *parent = nullptr);

    void increaseN1();
    int getpuntaje();

    void setPuntuacion(int newPuntuacion);

private:
    int puntuacion;
};

#endif // PUNTAJE_H
