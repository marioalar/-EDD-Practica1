#include "piladocumentos.h"

piladocumentos::piladocumentos()
{
    this->primero=nullptr;
}

/*
    bool pop();
    void imprimir();
*/


bool piladocumentos::isEmpty(){
    return (primero==nullptr);
}

int piladocumentos::getSize(){

    Documento* temp = primero;
    int size=0;
    for(; temp->sig!=nullptr;temp=temp->sig){
        size+=1;
    }
    return size;
}

Documento* piladocumentos::getLast(){
    Documento* temp= primero;

   if(isEmpty()){
       return nullptr;
   }else{
       while(temp->sig!=nullptr){
           temp=temp->sig;
       }
       return temp;
   }
}

Documento* piladocumentos::get(string id){
    Documento* temp =primero;

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

bool piladocumentos::isHere(string id){
    return (get(id)!=nullptr);
}

bool piladocumentos::isHere(Documento* documento){
    return (isHere(documento->id));
}

bool piladocumentos::push(string id){

    Documento* nuevo= new Documento(id);

    if(isEmpty()){
        this->primero = nuevo; //Si no existe un nodo primero, utilizar el nodo nuevo como primero
        return true;
    }else{
        if(isHere(id)){
            return false;
            //Ya esta el documento
        }else{
           nuevo->sig=this->primero;
           this->primero=nuevo;
           return true;
        }
    }
}

Documento* piladocumentos::pop(){
    ///// pop
    Documento* toExtract= primero;

    if(isEmpty()){
       return nullptr;
    }else{
        if(toExtract==this->primero){
            this->primero=toExtract->sig;
        }
    }
    return toExtract;
}

void piladocumentos::imprimir(){
    Documento* temp =primero;

    for(; temp !=nullptr ; temp=temp->sig){
        cout<< "Documento: " << temp->id <<endl;
    }
    cout<<"**********Documentos"<<endl;
}
