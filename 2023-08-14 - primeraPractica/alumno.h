#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char nombre[20];
    char apellido[20];
    char dni[13];
    int nota;
}stAlumno;

stAlumno cargarUnAlumno();
void muestraUnAlumno(stAlumno a);

#endif // ALUMNO_H_INCLUDED
