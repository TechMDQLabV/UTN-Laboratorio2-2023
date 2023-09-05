#include <stdio.h>
#include <stdlib.h>
#include "listaCliente.h"


nodo* inicLista(){
    return NULL;
}

nodo* crearNodo(stCliente dato){
    nodo* nuevoNodo = (nodo*) malloc(sizeof(nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->sig = NULL;
    return nuevoNodo;
}

nodo* agregarAlPrincipioDidactica(nodo* lista, nodo* nuevo){
    if(lista == NULL){
        lista = nuevo;
    }else{
        nuevo->sig = lista;
        lista = nuevo;
    }
    return lista;
}

nodo* agregarAlPrincipio(nodo* lista, nodo* nuevo){
    nuevo->sig = lista;
    return nuevo;
}

void muestraNodo(nodo* nodoCliente){
    printf("\n _____ %p", nodoCliente);
    muestraUnCliente(nodoCliente->dato);
    printf("\n >>>>> %p", nodoCliente->sig);
}

void muestraLista(nodo* lista){
    nodo* aux = lista;
    while(aux){   /// while(aux != NULL)
        muestraNodo(aux);
        aux = aux->sig;
    }
}

void muestraListaRecursiva(nodo* lista){
    if(lista){
        muestraNodo(lista);
        muestraListaRecursiva(lista->sig);
    }
}

int cuentaNodos(nodo* lista){
    int cont = 0;
    nodo* aux = lista;
    while(aux){
        cont++;
        aux = aux->sig;
    }
    return cont;
}

int cuentaNodosRecursivo(nodo* lista){
    int cont = 0;
    if(lista){
        cont = 1 + cuentaNodosRecursivo(lista->sig);
    }
    return cont;
}

int cuentaNodosRecursivoConFiltro(nodo* lista){
    int cont = 0;
    if(lista){
        if(lista->dato.id > 10){
            cont = 1 + cuentaNodosRecursivoConFiltro(lista->sig);
        }else{
            cont = cuentaNodosRecursivoConFiltro(lista->sig);
        }
    }
    return cont;
}

nodo* agregarEnOrdenDni(nodo* lista, nodo* nuevo){
    if(!lista){  /// if(lista == NULL)
        lista = nuevo;
    }else{
        if(atoi(nuevo->dato.persona.dni) <= atoi(lista->dato.persona.dni)){
            lista=agregarAlPrincipio(lista, nuevo);
        }else{
            nodo* ante = lista;
            nodo* aux = lista->sig;
            while(aux && atoi(nuevo->dato.persona.dni) > atoi(aux->dato.persona.dni)){
                ante = aux;
                aux = aux->sig;
            }
            nuevo->sig = aux;
            ante->sig = nuevo;
        }
    }

    return lista;
}

nodo* buscarUltimo(nodo* lista){
    nodo* aux = lista;
    while(aux->sig){  /// while(aux->sig != NULL)
        aux = aux->sig;
    }
    return aux;
}

nodo* agregarAlFinal(nodo* lista, nodo* nuevo){
    if(!lista){
        lista = nuevo;
    }else{
        nodo* ultimo = buscarUltimo(lista);
        ultimo->sig = nuevo;
    }
    return lista;
}

nodo* borrarLista(nodo* lista){
    nodo* proximo = NULL;
    nodo* aux = lista;
    while(aux){
        proximo = aux->sig;
        free(aux);
        aux = proximo;
    }
    return aux;
}

nodo* borrarNodo(nodo* lista, char dni[]){
    nodo* aux = NULL;
    if(lista && strcmp(lista->dato.persona.dni, dni)==0){
        aux = lista;
        lista = lista->sig;
        free(aux);
    }else{
        aux = lista->sig;
        nodo* ante = lista;
        while(aux && strcmp(aux->dato.persona.dni, dni)!=0){
            ante = aux;
            aux = aux->sig;
        }
        if(aux){
            ante->sig = aux->sig;
            free(aux);
        }
    }

    return lista;
}

nodo* buscarNodoPorDni(nodo* lista, char dni[]){
    nodo* aux = lista;
    while(aux && strcmp(aux->dato.persona.dni, dni)!=0){
        aux = aux->sig;
    }
    return aux;
}




