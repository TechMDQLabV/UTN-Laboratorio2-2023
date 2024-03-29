#include "registroArchivo.h"


/// se guarda un dato en el archivo
void agregarRegistro(stCliente e){
    FILE* pArchRegistro = fopen(arRegistro,"ab");
    if(pArchRegistro){
        fwrite(&e,sizeof(stCliente),1,pArchRegistro);
        fclose(pArchRegistro);
    }
}

/// funcion que asigna en la variable recibida un nombre al azar
void getNombre(char n[]){
    char nombres[][20] = {"Amalia","Juan","Roberta","Antonio","Juana","Fernando","Fernanda","Anibal","Antonia","Roberto",
                           "Anastasia","Anastasio","Artura","Arturo","Maria","Mario","Tamara","Adolfo","Adolfa","Pedro","Alfredo",
                           "Alfreda","Mauro","Maura","Benicio","Benicia","Ildefonso","Ildefonsa","Cuchuflito","Cuchuflita",
                           "Remilgo"};

    strcpy(n,nombres[randomRango(0,sizeof(nombres)/(sizeof(char)*30))]);
}
/// funcion que asigna en la variable recibida un apellido al azar
void getApellido(char a[]){
    char apellidos[][30] = {"Gomez","Perez","Rodriguez","Latorre","Fernandez","Torquemada", "Marijuan", "Roca", "Mitre", "Rivadavia",
                            "San Martin", "Alvarez", "Comizo", "Borges", "Zama", "Recato", "Olvido", "Gil", "Trapero", "Restinga",
                            "De Antonio", "Ramirez", "Spinetta", "Cortez", "Gonzalez", "Andujar", "San Juan", "Bautista", "Anchorena", "Paso",
                            "Gaboto","Vega","Vargas","Lloret","Linares","Suarez","Sierra","Amenabar","Blanco","White","Black"};

    strcpy(a,apellidos[randomRango(0,sizeof(apellidos)/(sizeof(char)*30))]);
}


void getDNI(char dni[]){
    dni[0]='\0';

    itoa((randomRango(549,1982)* randomRango(549,19801)),dni,10);
}

void getCUIT(char cuit[], char dni[]){
    cuit[0]='\0';

    strcat(cuit,"27");
    strcat(cuit,"-");
    strcat(cuit,dni);
    strcat(cuit,"-");
    strcat(cuit,"5");
}

void getEmail(char email[], char nombre[], char apellido[]){
    char nombreAux[30];
    char apellidoAux[30];
    strcpy(nombreAux, nombre);
    strcpy(apellidoAux, apellido);
    email[0]='\0';
    nombreAux[0]=tolower(nombreAux[0]);
    apellidoAux[0]=tolower(apellidoAux[0]);
    strcat(email,nombreAux);
    strcat(email,"@");
    strcat(email,apellidoAux);
    strcat(email,".com");
}

void getDomicilio(char c[]){
    char calles[][30] = {"San Juan","Funes","Gaboto","San Martin","Colon","Rivadavia", "Alsina", "Roca", "Mitre", "Belgrano",
                            "Paso", "11 de Septiembre", "3 de Febrero", "Balcarce", "Libertad", "Magallanes", "Irala", "Ayolas", "Moreno", "Brown",
                            "Bolivar", "Alberti", "Gascon", "La Rioja", "Catamarca", "Salta", "Jujuy", "XX de Septiembre", "14 de Julio", "Dorrego",
                            "Hernandarias","Don Orione","Juramento","Lanzilota","Estrada","Tierra del Fuego","Mendoza","Chubut","Rio Negro","Misiones","Edison"};

    strcpy(c,calles[randomRango(0,sizeof(calles)/(sizeof(char)*30))]);
    char nro[5];
    itoa(randomRango(50,10000),nro,10);
    strcat(c," ");
    strcat(c,nro);
}

void getTelefono(char tel[]){
    int nroTel = randomRango(635,19712)* randomRango(678,19801);
    itoa(nroTel,tel,10);
}

/// Funcion que genera un registro al azar y lo retorna
stCliente cargoRegistroArchivoRandom(){
    stCliente r;
    getApellido(r.persona.apellido);
    getNombre(r.persona.nombre);
    getDNI(r.persona.dni);
    getCUIT(r.cuit, r.persona.dni);
    getEmail(r.email, r.persona.nombre, r.persona.apellido);
    getDomicilio(r.domicilioParticular);
    getDomicilio(r.domicilioComercial);
    getTelefono(r.telefonoFijo);
    getTelefono(r.telefonoCel);

    return r;
}

/// funcion que guarda un dato de tipo stRegistroMedico en el archivo especificado
void guardaRegistroArchivo(char archivo[], stCliente e){
    FILE * pArch = fopen(archivo,"ab");
    if(pArch){
        fwrite(&e,sizeof(stCliente),1,pArch);
        fclose(pArch);
    }
}

/// Funcion que llama a las funciones anteriores y genera y guarda en el archivo la cantidad de registros deseados
void generaArchivoRandom(int cantidad){
    stCliente r;
    int i=0;
    int ultimo = cuentaRegistros(arRegistro, sizeof(stCliente))+1;
    printf("Generando archivo  ");
    while(i<cantidad){
        //(i % 100 == 0) ? espera():0;
        if(i%100 == 0)
            espera();
        r = cargoRegistroArchivoRandom();
        r.id = ultimo + i;
        int existe = buscaDNI(r.persona.dni);
        while(existe){
            getDNI(r.persona.dni);
            getCUIT(r.cuit, r.persona.dni);
            if(!buscaDNI(r.persona.dni)){
                existe = 0;
            }
        }
        guardaRegistroArchivo(arRegistro,r);
        i++;
    }
}

void espera(){
    gotoxy(whereX()-1,whereY());
    char c[]={196,47,179,92};
    static int i=0;
    i=(i > 3)?0:i;
    printf("%c",c[i]);
    i++;
}

int buscaDNI(char dni[]){
    int existe = 0;
    stCliente e;
    FILE * pArch = fopen(arRegistro,"rb");
    if(pArch){
        while(fread(&e,sizeof(stCliente),1,pArch)>0 && existe==0){
            if(strcmp(e.persona.dni, dni)==0){
                existe = 1;
            }
        }
        fclose(pArch);
    }
    return existe;
}
/*
int nivcadl (TArbol A){
    int izq = 0;
    int der = 0;
    int ret = 0;
    if(A){
        izq = 1 + nivcadl(A->izq);
        if (A->dato[0] == 'A')
           ret = izq;

    }

}
*/
