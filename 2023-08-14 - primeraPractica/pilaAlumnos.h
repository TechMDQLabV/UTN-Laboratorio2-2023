#ifndef PILAALUMNOS_H_INCLUDED
#define PILAALUMNOS_H_INCLUDED

#include <malloc.h>
#include "alumno.h"

typedef struct {
    stAlumno *a;
    int v;
    int dim;
}pilaAlumnos;

void inicPilaAlumnos(pilaAlumnos *p);
void apilarAlumnos(pilaAlumnos *p, stAlumno a);
stAlumno desapilarAlumnos(pilaAlumnos *p);
stAlumno topeAlumnos(pilaAlumnos *p);
int pilaVaciaAlumnos(pilaAlumnos *p);

#endif // PILAALUMNOS_H_INCLUDED
