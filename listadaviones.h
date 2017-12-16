#ifndef LISTADAVIONES_H
#define LISTADAVIONES_H
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;


typedef struct Avion {
    string id="";
    string tipo="";
    int pasajeros=0;
    int desbordaje=0;
    int mantenimiento=0;

    int prob=0; // tipo de avion
    int turnosCaducados = 0;
    int desbordado = false;
    bool arribado = false;

   Avion *sig=nullptr;
   Avion *ant=nullptr;

   //Constructor
   Avion(string id){
       this->prob= 1+rand()%(4-1);
       if(prob==1){
           this->id=id;
           this->tipo="pequeño";
           this->pasajeros = 5+rand()%(11-5);
           this->desbordaje=1; //turnos
           this->mantenimiento= 1+rand()%(4-1); //turnos


       }else if(prob==2){
           this->id=id;
           this->tipo="mediano";
           this->pasajeros = 15+rand()%(26-15);
           this->desbordaje=2; //turnos
           this->mantenimiento= 2+rand()%(5-2); //turnos

       }else if(prob==3){
           this->id=id;
           this->tipo="grande";
           this->pasajeros = 30+rand()%(41-30);
           this->desbordaje=3; //turnos
           this->mantenimiento= 3+rand()%(7-3); //turnos

       }

   }
} Avion;



class listaDaviones
{
public:
    listaDaviones();

    Avion *primero;



    bool insertar(string id);
    bool insertar(Avion * avion);
    bool isEmpty();
    Avion* getLast();
    bool isHere(string clave);
    bool isHere(Avion* avion);
    int getSize();
    Avion* extract(string id);
    Avion* extract(Avion* avion);
    Avion* get(string id);
    Avion* pop();
    Avion* unquee();
    void imprimir();


};

#endif // LISTADAVIONES_H
