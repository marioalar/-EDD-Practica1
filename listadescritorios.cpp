#include "listadescritorios.h"

listaDescritorios::listaDescritorios()
{
    this->primero=nullptr;

}

bool listaDescritorios::insertar(Escritorio * nuevo){

    if(isEmpty()){
        this->primero = nuevo;
        return true;
    }else{
        if(isHere(nuevo->id)){
         return false;
         //No se creo el nodo, ya existe
        }else{
         nuevo->sig =this->primero;
         this->primero->ant = nuevo;
         this->primero=nuevo;
         return true;
        }
        }
    }

bool listaDescritorios::isEmpty(){
       return (primero==nullptr);
}

int listaDescritorios::getSize(){
    Escritorio* temp = primero;
    int size=0;
    for(; temp!=nullptr;temp=temp->sig){
       size+=1;
    }
    return size;
}

Escritorio* listaDescritorios::get(char id){
    Escritorio* temp = primero;
    for(;temp!=nullptr;temp=temp->sig){
        if(temp->id==id){
            return temp;
        }
    }
    return nullptr;
}

bool listaDescritorios::isHere(char id){
    return (get(id)!=nullptr);
}

bool listaDescritorios::isHere(Escritorio *escritorio){
    return(isHere(escritorio));
}

Escritorio* listaDescritorios::getLast(){
    Escritorio* temp = primero;

    if(isEmpty()){
        return nullptr;
    }else{
        while (temp->sig!=nullptr) {
            temp= temp->sig;
        }
        return temp;
    }
}

void listaDescritorios::imprimir(){
    Escritorio* temp = primero;

    for(; temp->sig!=nullptr;temp=temp->sig){
        cout<< "Escritorio: " << temp->id << "\n"<<endl;
    }
    cout<<"****Lista Escritorios****"<<endl;
}
