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
    int velocidad=30;
    bool small = false, jumped = false;
    float vely, velx, scale1=0.25, scale2=0.18;

//    QPixmap *pixmap1;
//    float ancho, alto;        // Para  determinar la posición y el tamaño del sprite en la hoja de sprites

protected:  // Cambiamos de privado a protegido
    QPixmap *pixmap1;
    float ancho, alto;

public:
    explicit heroe(QObject *parent = nullptr);

    //QTimer *timer1;                                            // Puntero a un QTimer programar actualziacion del sprite


    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int getPosx() const;
    void setPosx(int px);
    int getPosy() const;
    void setPosy(int py);

    QPointF getPos() const;

    void moveBy(int x, int y);
    void acelerateBy(float x, int sceneHeight);
    void jump(float vely);
    void smallRect();
    void bigRect();

    void setLevel3Scale();
};

#endif // HEROE_H


