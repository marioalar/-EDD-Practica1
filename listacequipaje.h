#ifndef LISTACEQUIPAJE_H
#define LISTACEQUIPAJE_H
#include <string>
#include <iostream>

using namespace std;
typedef struct Maleta{
   string id;
   int cantidad;
   Maleta* sig;
   Maleta* ant;


    Maleta(string id, int cantidad){
        this->id=id;
        this->cantidad=cantidad;
        this->ant=nullptr;
        this->sig=nullptr;
    }
    Maleta(string id){
        this->id=id;
        this->ant=nullptr;
        this->sig=nullptr;
    }
} Maleta;



class listaCequipaje
{
public:
    listaCequipaje();
    Maleta* primero;
    Maleta* ultimo;

    bool insertar(string id);
    bool isEmpty();
    Maleta* getLast();
    bool isHere(string id);
    bool isHere(Maleta* maleta);
    int getSize();
    Maleta* extract(string id);
    Maleta* extract(Maleta* maleta);
    Maleta* get(string id);
    void imprimir();

};

#endif // LISTACEQUIPAJE_H
