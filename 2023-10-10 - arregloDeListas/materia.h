#ifndef MATERIAS_H_INCLUDED
#define MATERIAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char materia[20];
    char nombreAlumno[20]
    char apellidoAlumno[20];
    int nota;
}stMateria;

void muestraUnaMateria(stMateria materia);

#endif // MATERIAS_H_INCLUDED
