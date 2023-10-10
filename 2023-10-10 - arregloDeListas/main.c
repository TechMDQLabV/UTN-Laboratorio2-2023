#include <stdio.h>
#include <stdlib.h>

#include "materia.h"
#include "adl.h"
#define DIM 100

int cargaArreglo(char nombreArchivo[], celda adl[], int dim);

int main()
{
    celda adl[DIM];
    int v = 0;

    v = cargaArreglo(ARCHIVO_MATERIAS, adl, DIM);

    return 0;
}

int cargaArreglo(char nombreArchivo[], celda adl[], int dim){
    FILE* archi = fopen(nombreArchivo, "rb");
    char materia[20];
    stAlumno alumno;
    stMateria registro;
    int v = 0;
    if(archi){
        while(v < dim && fread(&registro, sizeof(stMateria), 1, archi) > 0){
            strcpy(materia, registro.materia);
            alumno = getAlumno(registro);
            v = alta(adl, v, materia, alumno);
        }
        fclose(archi);
    }
    return v;
}

stAlumno getAlumno(stMateria materia){
    stAlumno alumno;
    strcpy(alumno.nombreAlumno, materia.nombreAlumno);
    strcpy(alumno.apellidoAlumno, materia.apellidoAlumno);
    alumno.nota = materia.nota;

    return alumno;
}
