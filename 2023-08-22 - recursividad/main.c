#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arreglo[]={1,2,3,4,5,6,7,8};
    int vArreglo = 8;
    printf("\n %d", factorial(5));
    printf("\n %d", factorial1(5));
    printf("\n %d", factorial2(5));
    printf("\n %d", potencia(2, 6));
    printf("\n %d", potencia1(2, 6));
    printf("\n %d", potencia2(2, 6));
    printf("\n");
    muestraArreglo(arreglo, vArreglo, 0);
    printf("\n");
    muestraArregloInvertido(arreglo, vArreglo, 0);
    return 0;
}

int factorial(int x){
    int rta;
    if(x==0){
        rta = 1;
    }else{
        printf("\n Viaje de IDA - valor de x = %d",x);
        rta = x * factorial(x-1);
        printf("\n Viaje de VUELTA - valor de x = %d",x);
    }
    return rta;
}

int factorial1(int x){
    int rta = 1;
    if(x > 0){
        rta = x * factorial1(x-1);
    }
    return rta;
}

int factorial2(int x){
    return (x > 0) ? x * factorial2(x-1) : 1;
}

int potencia(int base, int exponente){
    int rta;
    if(exponente == 0){
        rta = 1;
    }else{
        rta = base * potencia(base, exponente - 1);
    }
    return rta;
}

int potencia1(int base, int exponente){
    int rta = 1;
    if(exponente > 0){
        rta = base * potencia1(base, exponente - 1);
    }
    return rta;
}

int potencia2(int base, int exponente){
    return (exponente > 0) ? base * potencia(base, exponente - 1) : 1;
}

void muestraArreglo(int a[], int v, int i){
    if(i < v){
        printf("%d - ", a[i]);
        muestraArreglo(a, v, i + 1);
    }
}

void muestraArregloInvertido(int a[], int v, int i){
    if(i < v){
        muestraArreglo(a, v, i + 1);
        printf("%d - ", a[i]);
    }
}







