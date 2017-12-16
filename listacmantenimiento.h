#ifndef LISTACMANTENIMIENTO_H
#define LISTACMANTENIMIENTO_H
#include<string>
#include<iostream>
#include"listadaviones.h"

using namespace std;

typedef struct Estacion{
    string id;
    bool disponible;

    //apuntadores
    Estacion* sig= nullptr;

    //listas
    listaDaviones* Aviones =new listaDaviones();

    Estacion(string id){
        this->id=id;
        sig=nullptr;
    }
}Estacion;


class listaCMantenimiento
{
public:
    listaCMantenimiento();

    Estacion* primero;

    bool isEmpty();
    bool isHere(string id);
    bool isHere(Estacion* estacion);
    void imprimir();
    int getSize();
    bool insertar(Estacion* nuevo);
    Estacion* getLast();
    Estacion* get(string id);
};

#endif // LISTACMANTENIMIENTO_H
