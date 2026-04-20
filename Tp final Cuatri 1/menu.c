#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "menu.h"
#include "const.h"
#include "admin.h"
#include "gestionAlimentacion.h"
#include "gestionEntrenamiento.h"
#include "Progreso.h"


int validos = 0;

void inicio()

{
    time_t t;
    time(&t);
    printf("         \n");
    printf("--------------------------------------------------------------------------------\n");
    printf("\t\t\t\t%s",ctime(&t));
    printf("--------------------------------------------------------------------------------\n");
    printf("         \n");
    printf("\t\t\t==================================\n");
    printf("\t\t\t|\t   BIENVENIDO A \t |\t\t\t\t\t\t\t\t\t\t| \t\t\t\t |\n");
    printf("\t\t\t|\t   FITNESS TIME \t |\t\t\t\t\t\t\t\t\t\t| \t\t\t\t |\n");
    printf("\t\t\t==================================\n");
    printf("         \n");
    printf("Presione una tecla para continuar.........\t\t\t\t\t\t\t\t\t\t\n");
    printf("--------------------------------------------------------------------------------\n");

    getchar();
    system("cls");
}

void registrarseOlogin()
{
    int opcion = 0;
    int noValido = 0;

    while(noValido == 0)
    {
        printf("\n\t\t<1> Iniciar Sesion");
        printf("\n\t\t<2> Registrarse");
        printf("\n\n\t\tIngrese una opcion[1/2]");
        scanf("%i", &opcion);

        system("cls");

        switch(opcion)
        {
        case 1:
            login();
            noValido = 1;
            break;
        case 2:
            registrarse();
            noValido = 1;
            break;
        default:
            printf("\n\t\t   Opcion no valida\n");
            break;
        }
    }
}
void registrarse()
{
    FILE* buffer;
    buffer=fopen(archivo, "ab");
    stUsuario A;

    if(buffer != NULL)
    {
        A.datosSesion.estado=1;

        printf("\n  ========================  REGISTRARSE  ========================  ");
        printf(" \n                        NOMBRE:-");
        fflush(stdin);
        gets(A.datosSesion.nombreUsuario);
        printf(" \n                        CONTRASENA:-");
        fflush(stdin);
        gets(A.datosSesion.contrasena);
        system("cls");
        printf("\n  ========================  DATOS PERSONALES  ========================  ");

        do
        {
            printf(" \n                        EDAD:-  ");
            scanf("%d", &A.datos.edad);
            if(A.datos.edad < 0)
            {
                printf("Debes ingresar una edad valida");
            }
        }
        while(A.datos.edad < 0);

        do
        {
            printf(" \n                        GENERO (F/M):-  ");
            fflush(stdin);
            scanf("%c", &A.datos.genero);
            if(A.datos.genero != 'f' && A.datos.genero != 'F' && A.datos.genero != 'm' && A.datos.genero != 'M')
            {
                printf("Debes ingresar una genero disponible, F o M");
            }
        }
        while(A.datos.genero != 'f' && A.datos.genero != 'F' && A.datos.genero != 'm' && A.datos.genero != 'M');

        do
        {
            printf(" \n                        PESO EN KG:-");
            scanf("%f", &A.datos.peso);
            if(A.datos.peso<0)
            {
                printf("Debes ingresar un peso mayor a 0");
            }
        }
        while(A.datos.peso<0);

        do
        {
            printf(" \n                        ALTURA EN CM:-");
            scanf("%f", &A.datos.altura);
            if(A.datos.altura<0)
            {
                printf("Debes ingresar una altura mayor a 0");
            }
        }
        while(A.datos.altura<0);


        system("cls");

        printf("\n  ========================  OBJETIVOS  ========================  ");
        do
        {
            printf(" \n                        TIPO DE ENTRENAMIENTO(1/2):-   ");
            printf("\n                         1 - Hipertrofia");
            printf("\n                         2 - Fuerza\n");
            scanf("%d", &A.datos.tipoentrenamiento);
            if(A.datos.tipoentrenamiento != 1 && A.datos.tipoentrenamiento != 2)
            {
                printf("Debes ingresar un entrenamiento disponible, 1 o 2\n");
            }
        }
        while(A.datos.tipoentrenamiento != 1 && A.datos.tipoentrenamiento != 2);

        printf(" \n                        TIPO DE ALIMENTACION(1/2/3):-  ");
        do
        {
            printf("\n");
            printf("\n                         1 - Definicion");
            printf("\n                         2 - Mantenimiento");
            printf("\n                         3 - Volumen\n");
            scanf("%d", &A.datos.tipoalimentacion);
            if(A.datos.tipoalimentacion != 1 && A.datos.tipoalimentacion != 2 && A.datos.tipoalimentacion != 3)
            {
                printf("Debes ingresar una alimentacion disponible, 1, 2 o 3\n");
            }
        }
        while(A.datos.tipoalimentacion != 1 && A.datos.tipoalimentacion != 2 && A.datos.tipoalimentacion != 3);

        printf("\n");

        fwrite(&A, sizeof(stUsuario),1,buffer);
        fclose(buffer);
    }
    else
    {
        printf("No hay archivo");
    }
    system("cls");
    registrarseOlogin();
}

int loginPos()
{
    FILE* buffer;
    buffer=fopen(archivo, "rb");
    stUsuario A;

    char nombre[15];
    char contra[15];
    int flag=0;
    int pos;

    if(buffer != NULL)
    {

        while(fread(&A,sizeof(stUsuario),1,buffer)>0)
        {
            usuarios[validos]=A;
            validos++;
        }
        fclose(buffer);
    }

    while(flag == 0)
    {
        pos = 0;
        printf("\n  ========================  INICIO DE SESION   ========================  ");
        printf(" \n                        NOMBRE:-");
        fflush(stdin);
        gets(nombre);
        printf(" \n                        CONTRASENA:-");
        fflush(stdin);
        gets(contra);
        while(flag == 0 && pos < validos)
        {
            if(strcmp(nombre,"admin")==0 && strcmp(contra,"admin")==0)
            {
                printf("  \n\n\n       BIENVENIDO A FITNESS TIME !!!! INICIO DE SESION CORRECTO");
                printf("\n\n\n\t\t\t\tPresione una tecla para continuar...");
                getchar();
                modificarArregloUsuarios(validos);
                flag=1;

            }
            if(strcmp(nombre,usuarios[pos].datosSesion.nombreUsuario)==0 && strcmp(contra,usuarios[pos].datosSesion.contrasena)==0 && usuarios[pos].datosSesion.estado == 1)
            {
                printf("  \n\n\n       BIENVENIDO A FITNESS TIME !!!! INICIO DE SESION CORRECTO");
                printf("\n\n\n\t\t\t\tPresione una tecla para continuar...");
                getchar();
                flag=1;
            }
            else
            {
                pos++;
            }
        }
        if(flag == 0)
        {
            printf("\n\n\n\n\n\t\t  USUARIO Y/O CONTRASENA NO VALIDOS");
            printf("\n\n\n\t\t Presione una tecla para continuar...");
            getchar();
            system("cls");
        }
    }
    return pos;
}

void login()
{
    int pos = loginPos();

    usuarios[pos].dias.cantidadAlimentosAlmuerzo = 0;
    usuarios[pos].dias.cantidadAlimentosCena = 0;
    usuarios[pos].dias.cantidadAlimentosDesayuno = 0;
    usuarios[pos].dias.cantidadAlimentosMerienda = 0;
    usuarios[pos].dias.cantAlimentosAgregados = 0;
    usuarios[pos].treino.cantidadEjerciciosBrazos = 0;
    usuarios[pos].treino.cantidadEjerciciosPecho = 0;
    usuarios[pos].treino.cantidadEjerciciosPiernas = 0;
    usuarios[pos].treino.cantidadEjerciciosEspalda = 0;
    usuarios[pos].treino.cantidadEjerciciosTotal = 0;

    menu(pos);
}


void menu(int pos)
{
    int opcion = 0;

    system("cls");



    printf("\n======================== BIENVENIDO %s ========================", usuarios[pos].datosSesion.nombreUsuario);
    printf("                                                                                          ");
    printf("                                                                                          ");
    printf("\n\t\t<1> Alimentacion");
    printf("\n\t\t<2> Entrenamiento");
    printf("\n\t\t<3> Progreso");
    printf("\n\t\t<4> Ingresar otro usuario");
    printf("\n\t\t<5> Crear nuevo usuario");
    printf("\n\t\t<6> Salir");

    printf("\n\n\t\tIngrese una opcion[1-6]");
    scanf("%i", &opcion);

    system("cls");

    switch(opcion)
    {
    case 1:
        menuAlimentacion(pos);
        break;
    case 2:
        menuEntrenamiento(pos);
        break;
    case 3:
        menuProgreso(pos);
        break;
    case 4:
        login();
        break;
    case 5:
        registrarse();

        break;
    case 6:
        guardarCambios();
        printf("Saliendo...");
        exit(0);
        break;
    default:
        printf("Opcion incorrecta! saliendo del sistema\n");
        getchar();
        break;
    }
}

int usuarioRegistrado()
{
    FILE *buffer = fopen(archivo, "rb");
    if (buffer != NULL)
    {
        fclose(buffer);
        return 1;
    }
    else
    {
        return 0;
    }
}

void guardarCambios()
{
    FILE*buffer;
    buffer=fopen(archivo,"r+b");
    stUsuario A;

    if(buffer!= NULL)
    {
        for(int i=0; i<validos; i++)
        {
            A=usuarios[i];
            fwrite(&A,sizeof(stUsuario),1,buffer);
        }
        fclose(buffer);
    }
}
