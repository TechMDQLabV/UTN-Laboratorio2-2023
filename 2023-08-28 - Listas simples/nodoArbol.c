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

nodoArbol* agregarNodoArbolSinRepetidos(nodoArbol* arbol, stCliente dato){
    if(!arbol){
        arbol = crearNodoArbol(dato);
    }else{
        if(atoi(dato.persona.dni) > atoi(arbol->dato.persona.dni)){
            arbol->der = agregarNodoArbol(arbol->der, dato);
        }else if(atoi(dato.persona.dni) < atoi(arbol->dato.persona.dni)){
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
    if(arbol){
        inOrden(arbol->izq);
        muestraUnCliente(arbol->dato);
        inOrden(arbol->der);
    }
}

void postOrden(nodoArbol* arbol){
    if(arbol){
        postOrden(arbol->izq);
        postOrden(arbol->der);
        muestraUnCliente(arbol->dato);
    }
}

nodoArbol* buscaNodoArbol(nodoArbol* arbol, char dni[]){
    nodoArbol* respuesta = NULL;
    if(arbol){
        if(atoi(dni) == atoi(arbol->dato.persona.dni)){
            restuesta = arbol;
        }else{
            if(atoi(dni) > atoi(arbol->dato.persona.dni)){
                respuesta = buscaNodoArbol(arbol->der, dni);
            }else{
                if(!respuesta){
                    respuesta = buscaNodoArbol(arbol->izq, dni);
                }
            }
        }
    }
    return resputa;
}

int cuentaNodosArbol(nodoArbol* arbol){
    int cont = 0;
    if(arbol){
        cont = 1 + cuentaNodosArbol(arbol->izq) + cuentaNodosArbol(arbol->der);
    }
    return cont;
}

int cuentaNodosArbolConFiltro(nodoArbol* arbol, char dni[]){
    int cont = 0;
    if(arbol){
        if(strcmp(dni, arbol->dato.persona.dni) == 0){
            cont = 1 + cuentaNodosArbol(arbol->izq) + cuentaNodosArbol(arbol->der);
        }else{
            cont = cuentaNodosArbol(arbol->izq) + cuentaNodosArbol(arbol->der);
        }
    }
    return cont;
}

int sumaNodosArbol(nodoArbol* arbol){
    int total = 0;
    if(arbol){
        total = arbol->dato.id + sumaNodosArbol(arbol->izq) + sumaNodosArbol(arbol->der);
    }
    return total;
}
