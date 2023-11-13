#ifndef VIDA_H
#define VIDA_H

#include <QObject>
#include <QGraphicsTextItem>
#include <QGraphicsItem>
#include <QGraphicsScene>

class vida : public QGraphicsTextItem
{
    Q_OBJECT

public:
    vida(QGraphicsItem *parent = nullptr);

    void lessVidaN1();
    int getVidaN1();

    void setVidaN1(int newPunVIDA);

private:
    int punVIDA;

};

#endif // VIDA_H
