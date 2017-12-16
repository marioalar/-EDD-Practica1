#include "listadaviones.h"

listaDaviones::listaDaviones()
{
            this->primero=nullptr;
    srand(time(NULL));


}

    bool listaDaviones::isEmpty(){
        return primero==nullptr;
}


bool listaDaviones::insertar(Avion * nuevo){

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
        cout << "ListaAviones::insertar parametro incorrecto" <<endl;
    }

}
bool listaDaviones::insertar(string id){

    Avion *nuevo = new Avion(id);

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

Avion* listaDaviones::getLast(){
    Avion* temp =this->primero;

    if (isEmpty()){
        return nullptr;
    }
    else {
        while(temp->sig != nullptr){
            temp=temp->sig;
        }
        return temp;
    }
}

bool listaDaviones::isHere(string clave){
   return (get(clave)!=nullptr);
}

bool listaDaviones::isHere(Avion* avion){
    return isHere(avion->id);
}

Avion* listaDaviones::get(string id){
    Avion* temp = primero;
    for(; temp!=nullptr;temp=temp->sig){
        if(temp->id == id){
            return temp;
        }
    }
    return nullptr;
}

Avion* listaDaviones::extract(string id){
    Avion* toExtract= get(id);

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

Avion* listaDaviones::extract(Avion* avion){
    return extract(avion->id);
}

Avion* listaDaviones::pop(){
    return extract(this->primero);
}

Avion* listaDaviones::unquee(){
    return extract(getLast());
}

int listaDaviones::getSize(){
    Avion* temp = primero;
    int size=0;
    for(; temp!=nullptr;temp=temp->sig){
       size+=1;
}
    return size;
}

void listaDaviones::imprimir(){
    Avion* temp = primero;
    int size=0;
    for(; temp!=nullptr;temp=temp->sig){
        cout<< "Avion: "<<temp->id
            <<" Tama;o: "<<temp->tipo
            <<" Pasajeros: "<< temp->pasajeros
            << " Desbordo: "<< temp->desbordaje
            << " Mantenimiendo:"<< temp->mantenimiento <<endl;
    }


    cout<<  "\n ********* \n"<<endl;
}
