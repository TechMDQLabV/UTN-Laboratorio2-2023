#ifndef ADL_H_INCLUDED
#define ADL_H_INCLUDED

#include "nodoAlumno.h"
#include <string.h>

typedef struct{
    char materia[20];
    nodoAlumno* listaAlumnos;
}celda;

int alta(celda adl[], int v, char materia[], stAlumno alumno);
int buscaPos(celda adl[], int v, char materia[]);
int agregar(celda adl[], int v, char materia[]);

#endif // ADL_H_INCLUDED
