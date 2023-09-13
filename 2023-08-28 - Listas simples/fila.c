#include "fila.h"

void inicFila(Fila* fila){
    fila->inicio = inicListaDoble();
    fila->fin = inicListaDoble();
}

void agregar(Fila* fila, stCliente dato){
    nodo2* nuevo = crearNodoDoble(dato);
    fila->fin = agregarAlFinalD(fila->fin, nuevo);
    if(!fila->inicio){
        fila->inicio = nuevo;
    }
    fila->fin = nuevo;
}

stCliente verPrimero(Fila* fila){
    return verPrimeroDoble(fila->inicio);
}

stCliente extraer(Fila* fila){
    stCliente c = verPrimeroDoble(fila->inicio);
    fila->inicio = borrarPrimerNodoDoble(fila->inicio);
    if(!fila->inicio){
        fila->fin = inicListaDoble();
    }

    return c;
}

int filaVacia(Fila* fila){
    return (!fila->inicio);
}

int filaVaciaDid(Fila* fila){
    int resp = 0;
    if(fila->inicio == NULL){
        resp = 1;
    }
    return resp;
}

void muestraFila(Fila* fila){
    muestraListaDoble(fila->inicio);
}
