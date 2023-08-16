#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include "alumno.h"

#define DIM_ALUMNOS 100
#define ESC 27
#define ARCH_ALUMNOS "alumnos.dat"

int cargaArregloAlumnos(stAlumno a[], int dim);
void muestraArregloAlumnos(stAlumno a[], int v);
void arreglo2archivo(stAlumno a[], int v, char nombreArchivo[]);
void arregloCompleto2archivo(stAlumno a[], int v, char nombreArchivo[]);
void muestraArchivoAlumnos(char nombreArchivo[]);
void intercambio(int* a, int* b);
int cuentaRegistros(char nombreArchivo[]);
int cargaArreglo(stAlumno** a, char nombreArchivo[]);
stAlumno* cargaArregloBis(int *v, char nombreArchivo[]);

int main()
{
    int n1 = 10;
    int n2 = 20;
    int cantidadRegistros;
    printf("\n n1 = %d - n2 = %d", n1, n2);
    intercambio(&n1, &n2);
    printf("\n n1 = %d - n2 = %d", n1, n2);

    cantidadRegistros = cuentaRegistros(ARCH_ALUMNOS);
    printf("\n Cantidad de registros: %d", cantidadRegistros);

    stAlumno* arregloAlumnos = NULL;
    int vArregloAlumnos = 0;
    vArregloAlumnos = cargaArreglo(&arregloAlumnos, ARCH_ALUMNOS);

    printf("\n <<<<< Listado de Alumnos de arreglo dinamico >>>>>\n");
    muestraArregloAlumnos(arregloAlumnos, vArregloAlumnos);

    stAlumno alumnos[DIM_ALUMNOS];
    int vAlumnos = 0;
    vAlumnos = cargaArregloAlumnos(alumnos, DIM_ALUMNOS);
    printf("\n <<<<< Listado de Alumnos >>>>>\n");
    muestraArregloAlumnos(alumnos, vAlumnos);
    arreglo2archivo(alumnos, vAlumnos, ARCH_ALUMNOS);
    arregloCompleto2archivo(alumnos, vAlumnos, ARCH_ALUMNOS);
    printf("\n <<<<< Listado de Alumnos >>>>>\n");
    muestraArchivoAlumnos(ARCH_ALUMNOS);

    return 0;
}

int cargaArregloAlumnos(stAlumno a[], int dim){
    char opcion = 0;
    int i = 0;
    while(i < dim && opcion != ESC){
        printf("\n <<<<< Carga de Alumnos >>>>>\n\n");
        a[i] = cargarUnAlumno();
        i++;
        printf("\n ESC para salir o cualquier tecla para continuar");
        opcion=getch();
        system("cls");
    }
    return i;
}

void muestraArregloAlumnos(stAlumno a[], int v){
    for(int i=0; i<v; i++){
        muestraUnAlumno(a[i]);
    }
}

void arreglo2archivo(stAlumno a[], int v, char nombreArchivo[]){
    FILE* archi = fopen(nombreArchivo, "ab");
    if(archi){ /// if(archi!=null)
        for(int i=0; i<v; i++){
            fwrite(&a[i], sizeof(stAlumno), 1, archi);
        }
        fclose(archi);
    }
}

void arregloCompleto2archivo(stAlumno a[], int v, char nombreArchivo[]){
    FILE* archi = fopen(nombreArchivo, "ab");
    if(archi){
        fwrite(a, sizeof(stAlumno), v, archi);
        fclose(archi);
    }
}

void muestraArchivoAlumnos(char nombreArchivo[]){
    stAlumno a;
    FILE* archi = fopen(nombreArchivo, "rb");
    if(archi){
        while(fread(&a, sizeof(stAlumno), 1, archi) > 0){
            muestraUnAlumno(a);
        }
        fclose(archi);
    }
}

void intercambio(int* a, int* b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

int cuentaRegistros(char nombreArchivo[]){
    FILE* archi = fopen(nombreArchivo, "rb");
    int cantidad = 0;
    if(archi){
        fseek(archi, 0 , SEEK_END);
        cantidad = ftell(archi)/sizeof(stAlumno);
        fclose(archi);
    }
    return cantidad;
}

int cargaArreglo(stAlumno** a, char nombreArchivo[]){
    int cant = cuentaRegistros(nombreArchivo);

    (*a) = (stAlumno *) malloc(sizeof(stAlumno)*cant);

    FILE* archi = fopen(nombreArchivo, "rb");
    if(archi){
        fread(*a, sizeof(stAlumno), cant, archi);
        fclose(archi);
    }
    return cant;
}

stAlumno* cargaArregloBis(int *v, char nombreArchivo[]){
    int cant = cuentaRegistros(nombreArchivo);

    stAlumno *a = (stAlumno *) malloc(sizeof(stAlumno)*cant);

    FILE* archi = fopen(nombreArchivo, "rb");
    if(archi){
        fread(a, sizeof(stAlumno), cant, archi);
        fclose(archi);
    }
    *v = cant;
    return a;
}
