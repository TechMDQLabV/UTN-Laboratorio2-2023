#include "pila.h"

void inicPila(Pila* pila){
    (*pila) = inicLista();
}

void apilar(Pila* pila, stCliente dato){
    (*pila)=agregarAlPrincipio(*pila, crearNodo(dato));
}

stCliente tope(Pila* pila){
    return verPrimeroLista(*pila);
}

stCliente desapilar(Pila* pila){
    stCliente cli = verPrimeroLista(*pila);
    (*pila)=borrarPrimerNodo(*pila);
    return cli;
}

void mostrar(Pila* pila){
    muestraLista(*pila);
}

int pilaVacia(Pila* pila){
    return ((*pila)==NULL);
}
