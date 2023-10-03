#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "persona.h"

typedef struct _nodo{
    stPersona dato;
    struct nodo* sig;
} nodo;

nodo* inicLista();
nodo* crearNodo(stPersona dato);
nodo* agregarAlPrincipio(nodo* lista, nodo* nuevo);
nodo* agregarEnOrdenPorApellido(nodo* lista, nodo* nuevo);
void muestraUnNodo(nodo* nodo);
void muestraLista(nodo* lista);
int sumaEdades(nodo* lista, int limiteEdad);
stPersona buscaMenorEdad(nodo* lista);
int cuentaPersonasMayores(nodo* lista, int edadLimite);

#endif // LISTA_H_INCLUDED
