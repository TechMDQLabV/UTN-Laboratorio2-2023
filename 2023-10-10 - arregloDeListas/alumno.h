#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nombreAlumno[20]
    char apellidoAlumno[20];
    int nota;
}stAlumno;

void muestraUnAlumno(stAlumno alumno);

#endif // ALUMNO_H_INCLUDED
