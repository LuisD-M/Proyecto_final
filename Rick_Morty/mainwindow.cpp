#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene1 = new QGraphicsScene;
    scene2 = new QGraphicsScene;
    scene3 = new QGraphicsScene;
    ui->graphicsView->setScene(scene1);
    escena = 1;



    QImage fondo1(":/Imagenes/Fondo1.jpg");
    QBrush BrochaF1(fondo1);

    ui->graphicsView->setBackgroundBrush(BrochaF1);    //Pinta el fondo del nivel 1 y se escala
    scene1->setSceneRect(0,0,1080,599);
    scene2->setSceneRect(0,0,1080,599);
    scene3->setSceneRect(0,0,1080,599);

    personaje = new heroe();                                 // crea heroe
    scene1->addItem(personaje);                               //Añade a la escena
    personaje->setPos(scene1->width()/2,scene1->height()/2);

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, [this]{
        bulletMove();
        enemyBulletGeneration();
        colission();
        setFocus();
        cambioEscena();
    });                                                         //Conecta el temporizador para mover balas
    timer->start(10);                                                             // 16

    enemyTimer = new QTimer(this);
    connect(enemyTimer, SIGNAL(timeout()), this, SLOT(enemyGeneration()));
    enemyTimer->start(2000);

    puntos = new puntaje;                            //añade puntaje
    scene1->addItem(puntos);
    puntos->setPos(0,0);

    vidas = new vida;
    scene1->addItem(vidas);
    vidas->setPos(1000,0);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    keysPressed.insert(event->key());
    switch (escena) {
    case 1:
    {
        int step=5;                                         //Velocidad personaje

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
        break;
    }
    case 2:
    {
        break;
    }
    case 3:
    {
        break;
    }
    default:
        qDebug() << "ERROR: la escena no existe";
        break;
    }

}

void MainWindow::keyReleaseEvent(QKeyEvent* event)
{
    keysPressed.remove(event->key());
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    switch (escena) {
    case 1:
    {
        QPointF mousePos = ui->graphicsView->mapToScene(event->pos());         //
        balas *bala = new balas(mousePos, personaje->getPos());                //crea nueva bala desde la posicion del heroe
        bala->balasAzules();
        scene1->addItem(bala->getElip());
        allyBullets.push_front(bala);
        break;
    }
    case 2:
    {

        break;
    }
    case 3:
    {

        break;
    }
    default:
        break;
    }
}

void MainWindow::bulletMove()
{
    switch (escena) {
    case 1:
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

        for (auto it = enemyBullets.begin(); it != enemyBullets.end();)
        {
            balas *bala = *it;
            bala->move();
            if (bala->getX() > scene1->width() || bala->getX() < 0 - bala->getWidth() || bala->getY() > scene1->height() || bala->getY() < 0-bala->getHeight())
            {
                scene1->removeItem(bala->getElip());
                it = enemyBullets.erase(it);
                delete bala;
            }else
            {
                it++;
            }
        }
        break;
    }
    case 2:
    {
        break;
    }
    case 3:
    {
        break;
    }
    default:
        break;
    }
}

void MainWindow::enemyGeneration()
{
    switch (escena) {
    case 1:
    {
        int place = rand() % 4 + 1;
        int posy, posx;
        switch (place) {

        case 1: // arriba
        {
            posy = 60;
            posx = rand() % ((int)scene1->width()- 10 +1 ) + 10;
            break;
        }
        case 2: // abajo
        {
            posy = 533;
            posx = rand() % ((int)scene1->width()- 10 +1 ) + 10;
            break;
        }
        case 3: // izquierda
        {
            posy = rand() % ((int)scene1->height() - 89) + 50;
            posx = 20;

            break;
        }
        case 4: // derecha
        {
            posy = rand() % ((int)scene1->height() - 89) + 50;
            posx = 1050;
            break;
        }
        default:
        {
            posx = scene1->width()/2;
            posy = scene1->height()/2;
            qDebug() << "Numero aleatorio generado no es el esperado";
        }
        break;
        }
        villano = new enemy1();
        scene1->addItem(villano);
        villano->setPos(posx,posy);
        enemies.push_front(villano);
        break;
    }
    case 2:
    {
        break;
    }
    case 3:
    {
        break;
    }
    default:
        break;
    }
}

void MainWindow::enemyBulletGeneration()
{
    switch (escena) {
    case 1:
    {
        for (auto villano: enemies)
        {
            int probability = rand()%150;
            if (probability == 10)
            {
                balas *bala = new balas(personaje->getPos(), villano->getPos());
                bala->balasAmarillas();
                scene1->addItem(bala->getElip());

                enemyBullets.push_front(bala);
            }
        }
        break;
    }
    case 2:
    {
        break;
    }
    case 3:
    {
        break;
    }
    default:
        break;
    }

}

void MainWindow::colission()
{
    switch (escena) {
    case 1:
    {
        for (auto itEnemy = enemies.begin(); itEnemy != enemies.end();){
            bool erased = false;
            for (auto itBullet = allyBullets.begin(); itBullet != allyBullets.end();){

                if((*itEnemy)->collidesWithItem((*itBullet)->getElip())){

                    erased = true;

                    scene1->removeItem((*itBullet)->getElip());
                    scene1->removeItem((*itEnemy));

                    balas *bala = (*itBullet);
                    enemy1 *enemigo = (*itEnemy);

                    itEnemy = enemies.erase(itEnemy);
                    itBullet = allyBullets.erase(itBullet);
                    puntos->increaseN1();

                    delete (enemigo);
                    delete (bala);
                    break;
                }else
                    itBullet++;

            }
            if (!erased) itEnemy++;
        }

        for(auto it = enemyBullets.begin(); it != enemyBullets.end();){
            if(personaje -> collidesWithItem((*it)->getElip())){

                scene1->removeItem((*it)->getElip());

                balas *bala = (*it);

                it = enemyBullets.erase(it);
                vidas->lessVidaN1();

                delete (bala);

            }
            else
                it++;
        }

        if(vidas->getVidaN1()== 0){

            eliminaItems(scene1);
            perdiste(scene1);
        }
        break;
    }
    case 2:
    {
        break;
    }
    case 3:
    {
        break;
    }
    default:
        break;
    }

}

void MainWindow::eliminaItems(QGraphicsScene *scene)
{
    scene->removeItem(personaje);

    for (auto enemy : enemies) {
        scene->removeItem(enemy);
        delete enemy;
    }
    enemies.clear();

    for (auto bullet : enemyBullets) {
        scene->removeItem(bullet->getElip());
        delete bullet;
    }
    enemyBullets.clear();
}

void MainWindow::perdiste(QGraphicsScene *scene)
{
    QGraphicsTextItem *gameOverText = new QGraphicsTextItem("Game Over");
    QFont font("Comic Sans MS", 30);
    gameOverText->setFont(font);
    gameOverText->setDefaultTextColor(Qt::black);
    gameOverText->setPos(scene->width() / 2 - 100, scene->height() / 2 - 50);
    scene->addItem(gameOverText);
}

void MainWindow::cambioEscena()
{
    int vida = 5;
    if (escena == 1 && puntos->getpuntaje() >= 10)
    {
        ui->graphicsView->setScene(scene2);
        puntos->setPuntuacion(0);
        vidas->setVidaN1(vida);
        scene2->addItem(personaje);
        escena = 2;
    }else if(escena == 2 && puntos->getpuntaje() >= 10)
    {
        ui->graphicsView->setScene(scene3);
        vidas->setVidaN1(vida*2);
        scene3->addItem(personaje);
        escena = 3;
    }
}
