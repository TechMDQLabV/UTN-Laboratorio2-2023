#include "pilaAlumnos.h"

void inicPilaAlumnos(pilaAlumnos *p){
    p->dim = 50;
    p->v = 0;
    p->a = (stAlumno *) malloc(sizeof(stAlumno)*p->dim);
}

void apilarAlumnos(pilaAlumnos *p, stAlumno a){
    if(p->v == p->dim){
        p->dim += 50; /// p->dim = p->dim + 50;
        p->a = (stAlumno *) realloc(p->a, sizeof(stAlumno) * p->dim);
    }
    p->a[p->v]=a;
    p->v++;
}

stAlumno desapilarAlumnos(pilaAlumnos *p){
    stAlumno a = p->a[p->v - 1];
    p->v--;
    return a;
}

stAlumno topeAlumnos(pilaAlumnos *p){
    return p->a[p->v - 1];
}

int pilaVaciaAlumnos(pilaAlumnos *p){
    int pv = 0;
    if(p->v == 0){
        pv = 1;
    }
    return pv;
}

int pilaVaciaAlumnosTernario(pilaAlumnos *p){
    return (p->v == 0) ? 1 : 0;
}

int pilaVaciaAlumnosBool(pilaAlumnos *p){
    return p->v == 0;
}
