#ifndef NODOARBOL_H_INCLUDED
#define NODOARBOL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

typedef struct _arbol{
    stCliente dato;
    struct _arbol* izq;
    struct _arbol* der;
}nodoArbol;

nodoArbol* inicArbol();
nodoArbol* crearNodoArbol(stCliente dato);
nodoArbol* agregarNodoArbol(nodoArbol* arbol, stCliente dato);
void preOrden(nodoArbol* arbol);
void inOrden(nodoArbol* arbol);
void postOrden(nodoArbol* arbol);
nodoArbol* buscaNodoArbol(nodoArbol* arbol, char dni[]);

#endif // NODOARBOL_H_INCLUDED
