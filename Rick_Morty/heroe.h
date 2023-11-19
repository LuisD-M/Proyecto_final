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
    int posx=545, posy=300;                                      // posición del heroe en la escena.
    int velocidad=30;
    QPixmap *pixmap1;
    float ancho, alto;        // Para  determinar la posición y el tamaño del sprite en la hoja de sprites

public:
    explicit heroe(QObject *parent = nullptr);

    heroe(int x, int y);                       // Constructor para inicializar  las posiciones posx e posy del sprite
    //QTimer *timer1;                                            // Puntero a un QTimer programar actualziacion del sprite


    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int getPosx() const;
    void setPosx(int px);
    int getPosy() const;
    void setPosy(int py);

    QPointF getPos() const;

    void moveBy(int x, int y);

};

#endif // HEROE_H


