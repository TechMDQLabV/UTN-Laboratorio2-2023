#include "adl.h"

int alta(celda adl[], int v, char materia[], stAlumno alumno){
    nodoAlumno* nuevo = crearNodo(alumno);
    int pos = buscaPos(adl, v, materia);
    if(pos == -1){
        v = agregar(adl, v, materia);
        pos = v -1;
    }
    adl[pos].listaAlumnos = agregarAlFinal(adl[pos].listaAlumnos, nuevo);
    return v;
}

int buscaPos(celda adl[], int v, char materia[]){
    int pos = -!;
    int i = 0;
    while(i < v && pos == -1){
        if(strcmp(adl[i].materia, materia)==0){
            pos = i;
        }
        i++;
    }
    return pos;
}

int agragar(celda adl[], int v, char materia[]){
    strcpy(adl[v].materia, materia);
    adl[v].listaAlumnos = inicLista();
    v++;
    return v;
}
