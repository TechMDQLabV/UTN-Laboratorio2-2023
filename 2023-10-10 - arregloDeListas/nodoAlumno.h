#ifndef NODOALUMNO_H_INCLUDED
#define NODOALUMNO_H_INCLUDED

#include "alumno.h"

typedef struct _nodoAlumno{
    stAlumno dato;
    struc _nodoAlumno* sig;
}nodoAlumno;

nodoAlumno* inicLista();
nodoAlumno* crearNodo(stAlumno dato);
nodoAlumno* agregarAlPrincipio(nodoAlumno* lista, nodoAlumno* nuevo);
nodoAlumno* buscarUltimo(nodoAlumno* lista);
nodoAlumno* agregarAlFinal(nodoAlumno* lista, nodoAlumno* nuevo);
nodoAlumno* agregarPorApellido(nodoAlumno* lista, nodoAlumno* nuevo);
void muestraUnNodoAlumno(nodoAlumno* nodo);
void muestraListaAlumno(nodoAlumno* lista);

#endif // NODOALUMNO_H_INCLUDED
