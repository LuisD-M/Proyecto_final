#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    scene1 = new QGraphicsScene;
    ui->graphicsView->setScene(scene1);

    QImage fondo1(":/Imagenes/Fondo1.jpg");
    QBrush BrochaF1(fondo1);

    ui->graphicsView->setBackgroundBrush(BrochaF1);    //Pinta el fondo del nivel 1 y se escala
    scene1->setSceneRect(0,0,1080,599);

    personaje = new heroe();                                 // crea heroe
    scene1->addItem(personaje);                               //Añade a la escena
    personaje->setPos(20,20);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int step=2;

    keysPressed.insert(event->key());

    if (keysPressed.contains(Qt::Key_A) && keysPressed.contains(Qt::Key_W)){
        personaje->moveBy(-step, -step);
        personaje->setRotation(-135);

    }
    else if (keysPressed.contains(Qt::Key_A) && keysPressed.contains(Qt::Key_S)){
        personaje->moveBy(-step, step);
        personaje->setRotation(135);

    }
    else if (keysPressed.contains(Qt::Key_D) && keysPressed.contains(Qt::Key_W)){
        personaje->moveBy(step, -step);
        personaje->setRotation(-45);

    }
    else if (keysPressed.contains(Qt::Key_D) && keysPressed.contains(Qt::Key_S)){
        personaje->moveBy(step, step);
        personaje->setRotation(45);

    }
    else {
        switch (event->key())
        {
        case Qt::Key_A:
            personaje->moveBy(-step, 0);
            personaje->setRotation(180);
            break;
        case Qt::Key_D:
            personaje->moveBy(step, 0);
            personaje->setRotation(0);
            break;
        case Qt::Key_W:
            personaje->moveBy(0, -step);
            personaje->setRotation(-90);
            break;
        case Qt::Key_S:
            personaje->moveBy(0, step);
            personaje->setRotation(90);
            break;
        default:
            break;
        }
    }
}

