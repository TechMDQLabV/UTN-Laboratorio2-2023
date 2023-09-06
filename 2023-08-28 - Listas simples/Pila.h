#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "listaCliente.h"

#define Pila nodo*

void inicPila(Pila* pila);
void apilar(Pila* pila, stCliente dato);
stCliente tope(Pila* pila);
stCliente desapilar(Pila* pila);
void mostrar(Pila* pila);
int pilaVacia(Pila* pila);

#endif // PILA_H_INCLUDED
