#include "start.h"
#include "ui_start.h"
#include "mainwindow.h"

start::start(QWidget *parent) :QMainWindow(parent), ui(new Ui::start)
{
    ui->setupUi(this);

    setStyleSheet("start {background-image:url(:/Imagenes/FondoVentana1.png)}");


}

start::~start()
{
    delete ui;
}

void start::on_pushButton_clicked()
{
    gw = new MainWindow(nullptr, dificultad,selheroe);
    gw->show();
    this->hide();
}

void start::on_DifiMedio_clicked()
{
    dificultad = 30;
}

void start::on_DifiEasy_clicked()
{
    dificultad = 50;
}

void start::on_DifiHard_clicked()
{
    dificultad = 10;
}

void start::on_Rick_clicked()
{
    selheroe = 1;
}

void start::on_Morty_clicked()
{
    selheroe = 2;
}

