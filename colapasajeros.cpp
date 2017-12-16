#include "colapasajeros.h"

colapasajeros::colapasajeros()
{
    primero=nullptr;
    srand(time(NULL));
}

Pasajero* colapasajeros::desencolar(){
    Pasajero* toExtract = getLast();
    if(isEmpty()){
        return nullptr;
    }else{
        if(toExtract!=nullptr){
            if(toExtract->sig!=nullptr){
                toExtract->sig->ant = toExtract->ant;
            }
            if(toExtract->ant!=nullptr){
                toExtract->ant->sig = toExtract->sig;

            }
            if(toExtract==this->primero){
                this->primero=toExtract->sig;
            }
        }
    return toExtract;
    }

}


bool colapasajeros::encolar(Pasajero * nuevo){
    if (nuevo != nullptr){
        if(isEmpty()){
            this->primero = nuevo; //Si no existe un nodo primero, utilizar el nodo nuevo como primero
            return true;
        }else{
            if(isHere(nuevo->id)){
                return false;
            }else{
                nuevo->sig = this->primero;
                this->primero->ant=nuevo;
                this->primero=nuevo;
                return true;
            }
        }
    }
    else {
        cout << "colapasajeros: Envio un parametor incorrecto" << std::endl;
    }
}

bool colapasajeros::encolar(string id){
    Pasajero* nuevo = new Pasajero(id);

    if(isEmpty()){
        this->primero = nuevo; //Si no existe un nodo primero, utilizar el nodo nuevo como primero
        return true;
    }else{
        if(isHere(id)){
            return false;
        }else{
            nuevo->sig = this->primero;
            this->primero->ant=nuevo;
            this->primero=nuevo;
            return true;
        }
    }
}

bool colapasajeros::isEmpty(){
    return(this->primero==nullptr);
}

bool colapasajeros::isHere(string id){
   return(get(id)!=nullptr);
}

bool colapasajeros::isHere(Pasajero *pasajero){
    return(isHere(pasajero->id));
}

Pasajero* colapasajeros::get(string id){
    Pasajero* temp = primero;
    for(; temp!=nullptr;temp=temp->sig){
        if(temp->id == id){
            return temp;
        }
    }
    return nullptr;
}

Pasajero* colapasajeros::getLast(){
    Pasajero* temp =primero;

    if(isEmpty()){
        return nullptr;
    }else{
        while(temp->sig!=nullptr){
            temp=temp->sig;
        }
        return temp;
    }
}

int colapasajeros::getSize(){
    Pasajero* temp= primero;
    int size=0;

    if(isEmpty()){
        return 0;
    }else{
        for(;temp!=nullptr;temp=temp->sig){
            size+=1;
        }
    }
    return size;
}

void colapasajeros::imprimir(){

    if(isEmpty()){
    }else{
        for(Pasajero* temp= primero;temp!=nullptr;temp=temp->sig){
        cout<< "Pasajero: "<< temp->id
            <<" Equipaje: " << temp->maletas
            <<" Turnos: "<<temp->turnos
            <<" Documentos: " <<temp->documentos<<endl;
        }

        cout<< "***********Pasajeros"<<endl;
    }
}


