#include "listacmantenimiento.h"

listaCMantenimiento::listaCMantenimiento()
{
    primero =nullptr;

}

bool listaCMantenimiento::insertar(Estacion* nuevo){


    if(isEmpty()){
       this->primero=nuevo;
        return true;
    }else{
        if(isHere(nuevo->id)){
            return false;
        }else{
            nuevo->sig=primero;
            this->primero=nuevo;
            return true;
        }
    }
}

bool listaCMantenimiento::isEmpty(){
    return (primero==nullptr);
}

int listaCMantenimiento::getSize(){
    Estacion* temp = primero;
    int size=0;
    for(; temp->sig!=nullptr;temp=temp->sig){
        size+=1;
    }
    return size;
}

Estacion* listaCMantenimiento::getLast(){
    Estacion* temp= primero;

   if(isEmpty()){
       return nullptr;
   }else{
       while(temp->sig!=nullptr){
           temp=temp->sig;
       }
       return temp;
   }
}

Estacion* listaCMantenimiento::get(string id){
    Estacion* temp =primero;

    if(isEmpty()){
        return nullptr;
    }else{
        for(;temp->sig!=nullptr;temp=temp->sig){
            if(temp->id==id){
                return temp;
            }
        }
        return nullptr;
    }
}

bool listaCMantenimiento::isHere(string id){
    return (get(id)!=nullptr);
}

bool listaCMantenimiento::isHere(Estacion* estacion){
    return (isHere(estacion->id));
}
