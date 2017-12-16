#ifndef LISTADESCRITORIOS_H
#define LISTADESCRITORIOS_H
#include <string>
#include <iostream>
#include "colapasajeros.h"
#include "piladocumentos.h"
#include "piladocumentos.h"
#include "colapasajeros.h"

using namespace std;
typedef struct Escritorio{
    char id;
    bool ocupado;
    int capacidad;
    //Apuntadores
    Escritorio *sig;
    Escritorio *ant;
    //Listas
    piladocumentos* Documento =new piladocumentos();
    colapasajeros* Pasajeros = new colapasajeros();

    Escritorio(char id){
        this->id = id;
        sig=nullptr;
        ant = nullptr;

    }
}Escritorio;


class listaDescritorios
{
public:
    listaDescritorios();

    Escritorio * primero;


    bool insertar(Escritorio * nuevo);
    bool isEmpty();
    Escritorio* getLast();
    bool isHere(char id);
    bool isHere(Escritorio* escritorio);
    int getSize();
    Escritorio* get(char id);
    void imprimir();

};

#endif // LISTADESCRITORIOS_H
