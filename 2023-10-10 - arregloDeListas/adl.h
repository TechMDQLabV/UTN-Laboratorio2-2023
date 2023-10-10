#ifndef ADL_H_INCLUDED
#define ADL_H_INCLUDED

#include "nodoAlumno.h"

typedef struct{
    char materia[20];
    nodoAlumno* listaAlumnos;
}celda;

int alta(celda adl[], int v, int dim, char materia[], stAlumno alumno);
int buscaPos(celda adl[], int v, char materia[]);
int agragar(celda adl[], int v, int dim, char materia[]);

#endif // ADL_H_INCLUDED
