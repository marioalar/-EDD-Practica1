#ifndef COLAPASAJEROS_H
#define COLAPASAJEROS_H
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

typedef struct Pasajero {
    string id;
    int maletas ;
    int documentos ;
    int turnos;

    Pasajero *sig =nullptr;
    Pasajero *ant =nullptr;

    Pasajero(string id){
        sig = nullptr;
        this->id=id;
        this->maletas = 1+rand()%(5-1);
        this->documentos = 1+rand()%(11-1);
        this->turnos = 1+rand()%(4-1);
    }
}Pasajero;



class colapasajeros
{
public:
    colapasajeros();

    Pasajero *primero;

    bool isEmpty();
    bool isHere(string id);
    bool isHere(Pasajero* pasajero);
    Pasajero* get(string id);
    Pasajero* getLast();
    bool encolar(string id);
    bool encolar(Pasajero * pasajero);
    Pasajero* desencolar();
    int getSize();
    void imprimir();


};

#endif // COLAPASAJEROS_H
