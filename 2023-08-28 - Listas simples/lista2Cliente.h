#ifndef LISTA2CLIENTE_H_INCLUDED
#define LISTA2CLIENTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

typedef struct _nodo2{
    stCliente dato;
    struct _nodo2* ante;
    struct _nodo2* sig;
}nodo2;

nodo2* inicListaDoble();
nodo2* crearNodo2(stCliente dato);
nodo2* agregarAlPrincipioDoble(nodo2* lista, stCliente dato);
nodo2* agregarAlPpioDoble(nodo2* lista, nodo2* nuevo);
void muestraNodo2(nodo2* nodo);
void muestraListaDoble(nodo2* lista);
nodo2* buscarUltimoDoble(nodo2* lista);
nodo2* agregarAlFinalDoble(nodo2* lista, stCliente dato);
nodo2* agregarAlFinalD(nodo2* lista, nodo2* nuevo);
nodo2* agregarEnOrdenDoblePorDni(nodo2* lista, stCliente dato);
nodo2* agregarEnOrdenDPorDni(nodo2* lista, nodo2* nuevo);
#endif // LISTA2CLIENTE_H_INCLUDED
