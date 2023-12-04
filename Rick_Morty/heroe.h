#ifndef HEROE_H
#define HEROE_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QWidget>
#include <QGraphicsPixmapItem>

class heroe : public QObject, public QGraphicsItem
{
    Q_OBJECT

private:
    bool small = false, jumped = false; // indica si el heroe encogió su tamaño, indica si el heroe saltó
    float vely, velx, scale1=0.25, scale2=0.18; // velocidades que puede tener el heroe, escalas de tamaño del heroe (nivel 3)

protected:
    QPixmap *pixmap1; // imagen del heore
    float ancho, alto; // dimensiones del heroe

public:
    explicit heroe(QObject *parent = nullptr); // constructor
    ~heroe(); // destructor

    QRectF boundingRect() const; // metodo que define las dimensiones del rectangulo que recubre la imagen
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); // metodo que pinta en pantalla la instancia

    // setters y getters
    int getPosx() const;
    void setPosx(int px);
    int getPosy() const;
    void setPosy(int py);
    QPointF getPos() const;

    void moveBy(int x, int y); // metodo que mueve al heroe en pantalla
    void acelerateBy(float x, int sceneHeight); // metodo que se encarga de simular la fisica de caida libre y movimiento rectilineo (nivel 3)
    void jump(float vely); // metodo que se encarga de manejar el salto del heroe (nivel 3)
    void smallRect(); // metodo que encoge el tamaño del heore (nivel 3)
    void bigRect(); // metodo que vuelve al tamaño original al heroe (nivel 3)

    void setLevel3Scale(); // metodo que cambia la escala del heroe al pasar al nivel 3
};

#endif // HEROE_H


