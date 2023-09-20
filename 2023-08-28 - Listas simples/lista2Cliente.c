#include "lista2Cliente.h"

nodo2* inicListaDoble(){
    return NULL;
}

nodo2* crearNodoDoble(stCliente dato){
    nodo2* nuevo = (nodo2*) malloc(sizeof(nodo2));
    nuevo->dato = dato;
    nuevo->ante = NULL;
    nuevo->sig = NULL;
    return nuevo;
}

nodo2* agregarAlPrincipioDoble(nodo2* lista, stCliente dato){
    return agregarAlPpioDoble(lista, crearNodoDoble(dato));
}

nodo2* agregarAlPpioDoble(nodo2* lista, nodo2* nuevo){
    nuevo->sig = lista;
    if(lista){
        lista->ante = nuevo;
    }
    return nuevo;
}

void muestraNodo2(nodo2* nodo){
    muestraUnCliente(nodo->dato);
}

void muestraListaDoble(nodo2* lista){
    nodo2* aux = lista;
    while(aux){
        muestraNodo2(aux);
        aux = aux->sig;
    }
}

void muestraListaDobleRecu(nodo2* lista){
    if(lista){
        muestraNodo2(lista);
        muestraListaDobleRecu(lista->sig);
    }
}

nodo2* buscarUltimoDoble(nodo2* lista){
    if(lista){
        while(lista->sig){
            lista = lista->sig;
        }
    }
    return lista;
}

nodo2* agregarAlFinalDoble(nodo2* lista, stCliente dato){
    return agregarAlFinalD(lista, crearNodoDoble(dato));
}

nodo2* agregarAlFinalD(nodo2* lista, nodo2* nuevo){
    if(!lista){
        lista = nuevo;
    }else{
        nodo2* ultimo = buscarUltimoDoble(lista);
        ultimo->sig = nuevo;
        nuevo->ante = ultimo;
    }

    return lista;
}

nodo2* agregarEnOrdenDoblePorDni(nodo2* lista, stCliente dato){
    return agregarEnOrdenDPorDni(lista, crearNodoDoble(dato));
}

nodo2* agregarEnOrdenDPorDni(nodo2* lista, nodo2* nuevo){
    if(!lista){
        lista = nuevo;
    }else{
        if(atoi(nuevo->dato.persona.dni) <= atoi(lista->dato.persona.dni)){
            nuevo->sig = lista;
            lista->ante = nuevo;
        }else{
            nodo2* aux = lista->sig;
            nodo2* ante = lista;
            while(aux && atoi(nuevo->dato.persona.dni) > atoi(aux->dato.persona.dni)){
                ante = aux;
                aux = aux->sig;
            }
            ante->sig = nuevo;
            nuevo->ante = ante;
            nuevo->sig = aux;
            if(aux){
                aux->ante = nuevo;
            }
        }
    }

    return lista;
}

stCliente verPrimeroDoble(nodo2* lista){
    return lista->dato;
}

nodo2* borrarPrimerNodoDoble(nodo2* lista){
    if(lista){
        nodo2* aBorrar = lista;
        lista = lista->sig;
        free(aBorrar);
        if(lista){
            lista->ante = NULL;
        }
    }
    return lista;
}
