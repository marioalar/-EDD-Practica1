#ifndef PILADOCUMENTOS_H
#define PILADOCUMENTOS_H
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

typedef struct Documento{

    string id;
    string propietario;
    int numero;

    Documento *sig;

    Documento(string id){
        this->id=id;
        sig=nullptr;

    }
} Documento;

class piladocumentos
{
public:
    piladocumentos();

    Documento* primero;

    bool isEmpty();
    bool isHere(string id);
    bool isHere(Documento* documento);
    void imprimir();
    int getSize();
    bool push(string id);
    Documento* pop();
    Documento* getLast();
    Documento* get(string id);


};

#endif // PILADOCUMENTOS_H
