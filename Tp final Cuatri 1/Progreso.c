#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "Progreso.h"
#include "menu.h"
#include "const.h"

const char definicion[]="Definicion";
const char mantenimiento[]="Mantenimiento";
const char volumen[]="Volumen";
const char hipertrofia[]="Hipertrofia";
const char fuerza[]="Fuerza";

void menuProgreso(int pos)
{
    int opcion = 0;

    printf("\n======================== PROGRESO ========================\n");
    printf("\n");
    printf("\t Peso : %.2f    Altura: %.2f    Edad: %d", usuarios[pos].datos.peso, usuarios[pos].datos.altura, usuarios[pos].datos.edad);
    printf("\n");
    printEntrenamiento(pos);
    printf("\n");
    printf("\n");
    printf("\n\t\t<1> Actualizar Dato/s");
    printf("\n\t\t<2> Volver al Menu Usuario");

    printf("\n\n\t\tIngrese una opcion[1-2]");
    scanf("%i", &opcion);

    system("cls");

    switch(opcion)
    {
    case 1:
        actualizarDatos(pos);
        break;
    case 2:
        menu(pos);
        break;
    }
}

void printEntrenamiento(int pos)
{
    if (usuarios[pos].datos.tipoentrenamiento==1)
    {
        printf("\t Tipo de entrenamiento: %s\n", hipertrofia);
    }
    if (usuarios[pos].datos.tipoentrenamiento==2)
    {
        printf("\t Tipo de entrenamiento: %s\n", fuerza);
    }
    if (usuarios[pos].datos.tipoalimentacion==1)
    {
        printf("\t Tipo de alimentacion: %s\n", definicion);
    }
    if (usuarios[pos].datos.tipoalimentacion==2)
    {
        printf("\t Tipo de alimentacion: %s\n", mantenimiento);
    }
    if (usuarios[pos].datos.tipoalimentacion==3)
    {
        printf("\t Tipo de alimentacion: %s\n", volumen);
    }
}

void actualizarDatos(int pos)
{
    int opcion;

    printf("\n===================== ACTUALIZAR DATOS =====================\n");
    printf("\n");

    printf("\n\t\t<1> Peso");
    printf("\n\t\t<2> Altura");
    printf("\n\t\t<3> Edad");
    printf("\n\t\t<4> Tipo de Entrenamiento");
    printf("\n\t\t<5> Tipo de Alimentacion");
    printf("\n\t\t<6> Volver al Menu Progreso");
    printf("\n\n\t\tIngrese una opcion[1-6]");
    scanf("%i", &opcion);

    system("cls");

    switch(opcion)
    {
    case 1:
        actualizarPeso(pos);
        break;
    case 2:
        actualizarAltura(pos);
        break;
    case 3:
        actualizarEdad(pos);
        break;
    case 4:
        actualizarEntrenamiento(pos);
        break;
    case 5:
        actualizarAlimentacion(pos);
        break;
    case 6:
        menuProgreso(pos);
        break;
    }
}

void actualizarPeso(int pos)
{
    printf("\t\tIngrese su peso actual: \n");
    scanf("%f", &usuarios[pos].datos.peso);

    printf("\n");
    printf("Peso modificado");
    getchar();
    system("cls");
    menuProgreso(pos);
}

void actualizarAltura(int pos)
{
    printf("\t\tIngrese su altura actual: \n");
    scanf("%f", & usuarios[pos].datos.altura);

    printf("\n");
    printf("Altura modificada");
    getchar();
    system("cls");
    menuProgreso(pos);
}

void actualizarEdad(int pos)
{
    printf("\t\tIngrese su edad actual: \n");
    scanf("%d", & usuarios[pos].datos.edad);

    printf("\n");
    printf("Edad modificada");
    getchar();
    system("cls");
    menuProgreso(pos);
}

void actualizarEntrenamiento(int pos)
{
    printf("\n\t\t<1> Hipertrofia");
    printf("\n\t\t<2> Fuerza");

    printf("\n\tSeleccione una opcion: \n");
    scanf("%d", & usuarios[pos].datos.tipoentrenamiento);

    printf("\n");
    printf("Entrenamiento modificado");
    getchar();
    system("cls");
    menuProgreso(pos);
}


void actualizarAlimentacion(int pos)
{
    printf("\n\t\t<1> Definicion");
    printf("\n\t\t<2> Mantenimiento");
    printf("\n\t\t<3> Volumen");
    printf("\n\tSeleccione una opcion: \n");
    scanf("%d", & usuarios[pos].datos.tipoalimentacion);

    printf("\n");
    printf("Alimentacion modificada");
    getchar();
    system("cls");
    menuProgreso(pos);
}

float caloriasBasal()
{
    FILE*buffer = fopen(archivo, "rb");
    stUsuario A;
    float calorias = 0;
    fread(&A,sizeof(stUsuario),1,buffer);

    if(buffer != NULL)
    {
        if(A.datos.genero == 'm' || A.datos.genero == 'M')
        {
            calorias = (10*A.datos.peso)+(6.25*A.datos.altura)-(5*A.datos.edad)+5;
        }
        else
        {
            calorias = (10*A.datos.peso)+(6.25*A.datos.altura)-(5*A.datos.edad)-161;
        }
        fclose(buffer);
    }
    return calorias;
}
