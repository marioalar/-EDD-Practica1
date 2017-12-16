#include "listacequipaje.h"

listaCequipaje::listaCequipaje()
{
    this->primero=nullptr;

}

Maleta* listaCequipaje::extract(string id){
    Maleta* toExtract = get(id);

    if(isEmpty()){
        return nullptr;
    }else{
        if(toExtract!=nullptr){
            if(toExtract==primero){ //Primero
                toExtract->ant->sig=toExtract->sig;
                toExtract->sig->ant=toExtract->ant;
                this->primero=toExtract->sig;
            }
            if(toExtract->sig==primero){ //Ultimo
                toExtract->ant->sig=this->primero;
                toExtract->sig->ant=toExtract->ant;
            }

            if(toExtract->ant!=primero ||toExtract->sig!=primero ){
                toExtract->ant->sig=toExtract->sig;
                toExtract->sig->ant=toExtract->ant;

            }
        }
    }
    return toExtract;
}

Maleta* listaCequipaje::extract(Maleta *maleta){
    return extract(maleta->id);
}

bool listaCequipaje::insertar(string id){
    Maleta* nuevo= new Maleta(id);

    if(isEmpty()){

        primero= nuevo;
        primero->sig=primero;
        primero->ant=primero;
        /*
        nuevo->ant=nuevo;
        nuevo->sig=nuevo;
        this->primero=nuevo;
        */
        return true;
    }else{
            Maleta* ult = getLast();
            nuevo->sig = this->primero;
            this->primero->ant=nuevo;
            nuevo->ant = ult;
            getLast()->sig=nuevo;
            cout<<"entrea";
            return true;
    }
    delete(nuevo);
    return false;
}

bool listaCequipaje::isEmpty(){
    return this->primero==nullptr;
}

Maleta* listaCequipaje::getLast(){
    Maleta* temp=primero;
    if(!isEmpty()){
        while (temp->sig!=primero){
            temp=temp->sig;

        }
    }
    return temp;
}

Maleta* listaCequipaje::get(string id){
    Maleta* temp=primero;

    for(; temp!=nullptr;temp=temp->sig){
        if(temp->id == id){
            return temp;
        }
    }
    return nullptr;
}

bool listaCequipaje::isHere(string id){
    return get(id)!=nullptr;
}

bool listaCequipaje::isHere(Maleta *maleta){
    return isHere(maleta->id);
}

int listaCequipaje::getSize(){
    Maleta* temp=primero;
    int size=0;

    do{
        temp=temp->sig;
        size+=1;

    }while (temp->sig!=primero);
    return size;
}

void listaCequipaje::imprimir(){
    Maleta* temp=primero;

    if(isEmpty()){

    }else{
    do{
        cout<<"Maleta: "<< temp->id << endl;
        temp=temp->sig;
    }while(temp!=primero);
/*
    while (temp->sig!=primero){

        cout<< "Maleta: "<< temp->id  << endl;
        temp=temp->sig;

    }
*/
    }
        cout<< "*******Maletas"<<endl;
}












