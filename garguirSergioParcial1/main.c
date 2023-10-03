#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

#define DIM 1000
#define AR_PERSONAS "personas.dat"

void muestraArreglo(stPersona p[], int v);
int archivo2arreglo(char nombreArchivo[], stPersona personas[], int dim);
nodo* arreglo2lista(stPersona personas[], int v, nodo* lista);
void guardaPersonasEnArchivo(char nombreArchivo[], nodo* lista, char inicial);

int main()
{
    stPersona personas[DIM];
    int v = 0;

    v = archivo2arreglo(AR_PERSONAS, personas, DIM);
    printf("\n Arreglo de Personas");
    muestraArreglo(personas, v);

    nodo* listaDePersonas = inicLista();
    listaDePersonas = arreglo2lista(personas, v, listaDePersonas);
    printf("\n Lista de Personas");
    muestraLista(listaDePersonas);


    printf("\n Total de Personas Mayores de edad con DNI par %d", sumaEdades(listaDePersonas, 18));
    printf("\n La persona de menor edad es:");
    muestraUnaPersona(buscaMenorEdad(listaDePersonas));

    char inicial;
    printf("\n Ingrese una inicial: ");
    fflush(stdin);
    scanf("%c", &inicial);
    inicial=toupper(inicial);
    char nombreArchivo[20];
    nombreArchivo[0]=inicial;
    nombreArchivo[1]='\0';
    strcat(nombreArchivo, ".dat");

    guardaPersonasEnArchivo(nombreArchivo, listaDePersonas, inicial);
    return 0;
}

/// Copiar los datos
/// de las personas del archivo en un arreglo de personas.

int archivo2arreglo(char nombreArchivo[], stPersona personas[], int dim){
    int v = 0;
    FILE* archi = fopen(nombreArchivo, "rb");
    if(archi){
        while(v < dim && fread(&personas[v], sizeof(stPersona), 1, archi) > 0){
            v++;
        }

        fclose(archi);
    }

    return v;
}

void muestraArreglo(stPersona p[], int v){
    for(int i=0;i<v;i++){
        muestraUnaPersona(p[i]);
    }
}

/// Copiar los datos de las personas del arreglo en una
///  lista simplemente enlazada, insertando sus datos en orden por apellido.

nodo* arreglo2lista(stPersona personas[], int v, nodo* lista){
    for(int i=0;i<v;i++){
        lista = agregarEnOrdenPorApellido(lista, crearNodo(personas[i]));
    }
    return lista;
}


/// Hacer una función que recorra la lista y copie las personas cuyo apellido
/// comience con una letra recibida por parámetro a un archivo nuevo.
/// (Recuerde que un string es un arreglo de caracteres).

void guardaPersonasEnArchivo(char nombreArchivo[], nodo* lista, char inicial){
    stPersona p;
    FILE* archi = fopen(nombreArchivo, "ab");
    if(archi){
        while(lista){
            if(lista->dato.apellido[0] == inicial){
                p = lista->dato;
                fwrite(&p, sizeof(stPersona), 1, archi);
            }
            lista=lista->sig;
        }
        fclose(archi);
    }
}

/// Hacer una función que calcule el porcentaje de personas mayores
/// a cierta edad con respecto al total de personas de la lista.
///  (Para éste cálculo deberá utilizar la función anterior (dos veces enviando distintos parámetros?), piense!!!).

float porcentajeMayores(nodo* lista, int edadLimite){
    int totalPersonas = cuentaPersonasMayores(lista, 0);
    int totalMayores = cuentaPersonasMayores(lista, edadLimite);
    float porcentaje = 0;
    if(lista){
        porcentaje = (float) totalMayores * 100 / totalPersonas;
    }
    return porcentaje;
}
