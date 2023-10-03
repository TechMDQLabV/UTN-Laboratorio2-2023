#include "lista.h"

nodo* inicLista(){
    return NULL;
}

nodo* crearNodo(stPersona dato){
    nodo* nuevo = (nodo*) malloc(sizeof(nodo));
    nuevo->dato = dato;
    nuevo->sig = NULL;
    return nuevo;
}

nodo* agregarAlPrincipio(nodo* lista, nodo* nuevo){
    nuevo->sig = lista;
    return nuevo;
}

nodo* agregarEnOrdenPorApellido(nodo* lista, nodo* nuevo){
    if(!lista){
        lista = nuevo;
    }else{
        if(strcmp(nuevo->dato.apellido, lista->dato.apellido) < 0){
            lista = agregarAlPrincipio(lista, nuevo);
        }else{
            nodo* ante = lista;
            nodo* aux = lista->sig;
            while(aux && strcmp(nuevo->dato.apellido, aux->dato.apellido)>0){
                ante = aux;
                aux = aux->sig;
            }
            nuevo->sig = aux;
            ante->sig = nuevo;
        }
    }

    return lista;
}

void muestraUnNodo(nodo* nodo){
    muestraUnaPersona(nodo->dato);
}

void muestraLista(nodo* lista){
    nodo* aux = lista;
    while(aux){
        muestraUnNodo(aux);
        aux = aux->sig;
    }
}

/// Hacer una función recursiva que sume las edades de
/// las personas de la lista que tengan DNI par y
/// sean mayores de edad. (Recuerde que el dato DNI
/// es de tipo char[]).

int sumaEdades(nodo* lista, int limiteEdad){
    int total = 0;
    if(lista){
        if(atoi(lista->dato.dni)%2 == 0 && lista->dato.edad >= limiteEdad){
            total = lista->dato.edad + sumaEdades(lista->sig, limiteEdad);
        }else{
            total = sumaEdades(lista->sig, limiteEdad);
        }
    }
    return total;
}

/// Hacer una función recursiva que busque la persona de menor
/// edad en la lista y la retorne.

stPersona buscaMenorEdad(nodo* lista){
    stPersona menor;
    if(lista->sig){
        menor = buscaMenorEdad(lista->sig);
        if(menor.edad > lista->dato.edad){
            menor = lista->dato;
        }
    }else{
        menor = lista->dato;
    }
    return menor;
}

/// Hacer una función recursiva que cuente las personas de la
/// lista, mayores a una edad recibida por parámetro.

int cuentaPersonasMayores(nodo* lista, int edadLimite){
    int cont = 0;
    if(lista){
        if(lista->dato.edad > edadLimite){
            cont = 1 + cuentaPersonasMayores(lista->sig, edadLimite);
        }else{
            cont = cuentaPersonasMayores(lista->sig, edadLimite);
        }
    }
    return cont;
}
