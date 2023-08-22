#include <stdio.h>
#include <stdlib.h>

int main()
{

    printf("\n %d", factorial(5));
    printf("\n %d", factorial1(5));
    printf("\n %d", factorial2(5));
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



