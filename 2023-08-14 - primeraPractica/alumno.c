#include "alumno.h"

stAlumno cargarUnAlumno(){
    stAlumno a;
    static int id = 0;
    id++;
    a.id = id;
    printf("\n Nombre.......: ");
    fflush(stdin);
    gets(a.nombre);
    printf(" Apellido.....: ");
    fflush(stdin);
    gets(a.apellido);
    printf(" DNI..........: ");
    fflush(stdin);
    gets(a.dni);
    printf(" Nota.........: ");
    scanf("%d",&a.nota);

    return a;
}

void muestraUnAlumno(stAlumno a){
    printf("\n Id.........: %d", a.id);
    printf("\n Nombre.....: %s", a.nombre);
    printf("\n Apellido...: %s", a.apellido);
    printf("\n DNI........: %s", a.dni);
    printf("\n Nota.......: %d", a.nota);
    printf("\n ------------------------------------------------");
}
