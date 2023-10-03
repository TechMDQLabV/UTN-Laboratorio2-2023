#include "nodoArbol.h"

nodoArbol* inicArbol(){
    return NULL;
}

nodoArbol* crearNodoArbol(stCliente dato){
    nodoArbol* nuevo = (nodoArbol*) malloc(sizeof(nodoArbol));
    nuevo->dato = dato;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}

nodoArbol* agregarNodoArbol(nodoArbol* arbol, stCliente dato){
    if(!arbol){
        arbol = crearNodoArbol(dato);
    }else{
        if(atoi(dato.persona.dni) > atoi(arbol->dato.persona.dni)){
            arbol->der = agregarNodoArbol(arbol->der, dato);
        }else{
            arbol->izq = agregarNodoArbol(arbol->izq, dato);
        }
    }
    return arbol;
}

void preOrden(nodoArbol* arbol){
    if(arbol){
        muestraUnCliente(arbol->dato);
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}

void inOrden(nodoArbol* arbol){

}

void postOrden(nodoArbol* arbol){

}

nodoArbol* buscaNodoArbol(nodoArbol* arbol, char dni[]){

}
