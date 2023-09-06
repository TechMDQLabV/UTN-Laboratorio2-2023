#ifndef LISTACLIENTE_H_INCLUDED
#define LISTACLIENTE_H_INCLUDED

#include "cliente.h"

typedef struct _nodo{
    stCliente dato;
    struct _nodo* sig;
}nodo;

nodo* inicLista();
nodo* crearNodo(stCliente dato);
nodo* agregarAlPrincipio(nodo* lista, nodo* nuevo);
nodo* agregarEnOrdenDni(nodo* lista, nodo* nuevo);
nodo* agregarEnOrdenPorApellido(nodo* lista, nodo* nuevo);
void muestraNodo(nodo* nodoCliente);
void muestraLista(nodo* lista);
void muestraListaRecursiva(nodo* lista);
int cuentaNodos(nodo* lista);
int cuentaNodosRecursivo(nodo* lista);
int cuentaNodosRecursivoConFiltro(nodo* lista);
stCliente verPrimero(nodo* lista);
nodo* borrarPrimerNodo(nodo* lista);

#endif // LISTACLIENTE_H_INCLUDED
