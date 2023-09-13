#include <stdio.h>
#include <stdlib.h>
#include "listaCliente.h"
#include "lista2Cliente.h"

#define AR_CLIENTES "clientes.dat"
#define ESC 27

void muestraMenu();
nodo* archivoClientes2lista(char nombreArchivo[], nodo* lista);

int main()
{
    char opcion;
    nodo* lista = inicLista();
    nodo2* lista2 = inicListaDoble();

    do{
        system("cls");
        muestraMenu();

        opcion = getch();

        switch(opcion){
            case 48:
                generaArchivoRandom(100);
                break;
            case 49:
                muestraClientesArchivo(AR_CLIENTES);
                break;
            case 50:
                lista = archivoClientes2lista(AR_CLIENTES, lista);
                break;
            case 51:
                muestraListaRecursiva(lista);
            case 52:
                lista2 = listaAlista2(lista, lista2);
            case 53:
                muestraListaDoble(lista2);
        }
        system("pause");
    }while(opcion != ESC);

    printf("Hello world!\n");
    return 0;
}

void muestraMenu(){
    printf("\n\t\t\t Menu Principal \n\n");
    printf("\n 0 - Genera 100 registros aleatorios en el archivo de Clientes");
    printf("\n 1 - Muestra archivo de clientes");
    printf("\n 2 - Pasa archivo de Clientes a la lista");
    printf("\n 3 - Muestra lista de Clientes");
    printf("\n 4 - Pasa lista de Clientes a la lista Doble");
    printf("\n 5 - Muestra lista Doble de Clientes");

    printf("\n\n    ESC para salir.....");
}

nodo* archivoClientes2lista(char nombreArchivo[], nodo* lista){
    FILE* archi = fopen(nombreArchivo, "rb");
    stCliente cliente;
    if(archi){
        while(fread(&cliente, sizeof(stCliente), 1, archi) > 0){
            lista = agregarAlPrincipio(lista, crearNodo(cliente));
        }
        fclose(archi);
    }
    return lista;
}

int lista2arreglo(nodo* lista, stCliente clientes[], int v, int dim){
    while(lista && v < dim){
        clientes[v] = lista->dato;
        v++;
        lista = lista->sig;
    }
    return v;
}

nodo* arreglo2lista(stCliente clientes[], int v, nodo* lista, char dni[]){
    for(int i = 0; i < v; i++){
        if(atoi(clientes[i].persona.dni) > atoi(dni)){
            lista = agregarAlFinal(lista, crearNodo(clientes[i]));
        }
    }

    return lista;
}

nodo2* listaAlista2(nodo* lista, nodo2* lista2){
    nodo* aux = lista;
    while(aux){
        if(atoi(aux->dato.persona.dni)%2==0){
            lista2 = agregarAlPrincipioDoble(lista2, aux->dato);
        }
        aux = aux->sig;
    }

    return lista2;
}
