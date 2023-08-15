#include "pilaAlumnos.h"

void inicPilaAlumnos(pilaAlumnos *p){
    p->dim = 50;
    p->v = 0;
    p->a = (stAlumno *) malloc(sizeof(stAlumno)*p->dim);
}
