#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
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
    personaje->setPos(20,20 );


    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(bulletMove()));     //Conecta el temporizador para mover balas
    timer->start(16);                                                // 16


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
        personaje->setRotation(-45);

    }
    else if (keysPressed.contains(Qt::Key_A) && keysPressed.contains(Qt::Key_S)){
        personaje->moveBy(-step, step);
        personaje->setRotation(225);

    }
    else if (keysPressed.contains(Qt::Key_D) && keysPressed.contains(Qt::Key_W)){
        personaje->moveBy(step, -step);
        personaje->setRotation(45);

    }
    else if (keysPressed.contains(Qt::Key_D) && keysPressed.contains(Qt::Key_S)){
        personaje->moveBy(step, step);
        personaje->setRotation(135);

    }
    else {
        switch (event->key())
        {
        case Qt::Key_A:
            personaje->moveBy(-step, 0);
            personaje->setRotation(0);
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

void MainWindow::keyReleaseEvent(QKeyEvent* event)
{
    keysPressed.remove(event->key());
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPointF mousePos = ui->graphicsView->mapToScene(event->pos());         //
    balas *bala = new balas(mousePos, personaje->getPos());                //crea nueva bala desde la posicion del heroe
    bala->balasAzules();
    scene1->addItem(bala->getElip());
    allyBullets.push_front(bala);
    setFocus();                                                             //Recibir eventos del teclado y raton
}

void MainWindow::bulletMove()
{
    for (auto it = allyBullets.begin(); it != allyBullets.end();)
    {
        balas *bala = *it;
        bala->move();
        if (bala->getX() > scene1->width() || bala->getX() < 0-bala->getWidth() || bala->getY() > scene1->height() || bala->getY() < 0-bala->getHeight())
        {
            scene1->removeItem(bala->getElip());
            it = allyBullets.erase(it);
            delete bala;
        }else
        {
            it++;
        }
    }

  /*  for (auto it = enemyBullets.begin(); it != enemyBullets.end();)
    {
        Bullet *bullet = *it;
        bullet->move();
        if (bullet->getX() > scene1->width() || bullet->getX() < 0 - bullet->getWidth() || bullet->getY() > scene1->height() || bullet->getY() < 0-bullet->getHeight())
        {
            scene1->removeItem(bullet->getElip());
            it = enemyBullets.erase(it);
            delete bullet;
        }else
        {
            it++;
        }
    }  */

}
