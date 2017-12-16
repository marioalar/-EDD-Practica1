#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    listaAviones =new listaDaviones();

    colapasa = new colapasajeros();
    equipaje= new listaCequipaje();
    mantenimiento = new listaCMantenimiento();
    escritorios = new listaDescritorios();
    documentos= new piladocumentos();
    estaciones = new listaCMantenimiento();

    desabordaje = new colapasajeros();


    turn = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    qDebug() << "Prueba Avion";
    qDebug() << "Vacio? " <<  QString::number(listaAviones->isEmpty());

    for (int i = 0; i < 5; i++){
        Avion * avion = new Avion("Avion"+to_string(i));
        listaAviones->insertar(avion);
    }

    qDebug() << "Size: " <<  QString::number(listaAviones->getSize());

    listaAviones->imprimir();


    /*
    qDebug() << "Prueba";
    qDebug() << "Vacio? " <<  QString::number(colapasa->isEmpty());

    for (int i = 0; i < 5; i++){
        Pasajero * pasajero = new Pasajero("Pasajero"+to_string(i));
        colapasa->encolar(pasajero);
    }

    qDebug() << "Size: " <<  QString::number(colapasa->getSize());

    colapasa->imprimir();
    */

}




void MainWindow::on_pushButton_2_clicked()
{
    //lista->pop();

    documentos->pop();



}

void MainWindow::on_pushButton_3_clicked()
{
    //lista->unquee();
    colapasa->desencolar();
    //equipaje->extract("Pasajero1");


}

void MainWindow::on_pushButton_4_clicked()
{
    //lista->extract(string(ui->texto));
}

void MainWindow::on_pushButton_5_clicked()
{
    //lista->imprimir();
    colapasa->imprimir();
    //equipaje->imprimir();
    //documentos->imprimir();
}

void MainWindow::on_pushButton_6_clicked()
{

}

void MainWindow::on_generateButton_clicked()
{
    //qDebug() << "presionado " << ui->planeNumberLineEdit->text().toInt();
    int planeNumber = ui->planeNumberLineEdit->text().toInt();
    int desktopNumber = ui->desktopNumberLineEdit->text().toInt();
    int serviceNumber = ui->serviceNumberLineEdit->text().toInt();

    for (int i = 0; i < planeNumber; i++){
        Avion * avion = new Avion("Avion" + to_string(i));
        listaAviones->insertar(avion);
    }

    for (int i = 0; i < desktopNumber; i++){
        Escritorio * escritorio = new Escritorio('A' + i);
        escritorios->insertar(escritorio);
    }

    for (int i = 0; i < serviceNumber; i++){
        Estacion * estacion = new Estacion("Estacion" + to_string(i));
        estaciones->insertar(estacion);
    }

}

void MainWindow::on_turnButton_clicked()
{
    turn += 1;
    ui->turnLabel->setText(QString::number(turn));



}
