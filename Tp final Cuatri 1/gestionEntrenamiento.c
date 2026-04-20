#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "const.h"
#include "gestionEntrenamiento.h"
#include "menu.h"

stEjercicio ejerciciosDispo[100];
int cantidadEjercicios = 0;


void menuEntrenamiento(int pos)
{
    int opcion = 0;

    printf("\n======================== ENTRENAMIENTO ========================");
    printf("                                                                                          ");
    printf("                                                                                          ");
    printf("\n\t\t<1> Agregar Ejercicio/s");
    printf("\n\t\t<2> Modificar/Quitar ejercicio/s del dia");
    printf("\n\t\t<3> Ver lista de entrenamiento del dia");
    printf("\n\t\t<4> Volver al Menu Usuario\n");
    printf("\n\n\t\tIngrese una opcion[1-4]");
    scanf("%i", &opcion);

    system("cls");

    switch(opcion)
    {
    case 1:
        agregarEjercicio(pos);
        break;
    case 2:
        modificarQuitarEjercicio(pos);
        break;
    case 3:
        verEntrenamientoDelDia(pos);
        break;
    case 4:
        menu(pos);
        break;
    }
}

void agregarEjercicio(int pos)
{
    stEjercicio A;
    int seleccion = 0;
    char eleccion = 's';

    if(cantidadEjercicios == 0)
    {
        FILE* buffer;
        buffer=fopen("Ejercicios", "rb");
        if(buffer != NULL)
        {
            while(fread(&A,sizeof(stEjercicio),1,buffer)>0)
            {
                ejerciciosDispo[cantidadEjercicios] = A;
                cantidadEjercicios++;
            }
            fclose(buffer);
        }
    }
    printf("\n======================== AGREGAR EJERCICIOS ========================");

    printf("                                                                                          ");
    printf("                                                                                          ");

    while(eleccion == 's')
    {
        do
        {
            printf("\t\t A que grupo muscular pertenece? \n");
            printf("                                                                                          \n");
            printf("\t\t<1> - PECHO\n");
            printf("\t\t<2> - ESPALDA\n");
            printf("\t\t<3> - BRAZOS\n");
            printf("\t\t<4> - PIERNAS\n");
            scanf("\t\t%d", &seleccion);

            if(seleccion < 1 || seleccion > 4)
            {
                printf("\t\tIngrese un grupo valido\n");
            }
        }
        while(seleccion < 1 || seleccion > 4);

        usuarios[pos].treino.cantidadEjerciciosTotal++;

        switch(seleccion)
        {
        case 1:
            usuarios[pos].treino.pecho[usuarios[pos].treino.cantidadEjerciciosPecho]=cargarEjercicio();
            usuarios[pos].treino.cantidadEjerciciosPecho++;
            break;
        case 2:
            usuarios[pos].treino.espalda[usuarios[pos].treino.cantidadEjerciciosEspalda]=cargarEjercicio();
            usuarios[pos].treino.cantidadEjerciciosEspalda++;
            break;
        case 3:
            usuarios[pos].treino.brazo[usuarios[pos].treino.cantidadEjerciciosBrazos]=cargarEjercicio();
            usuarios[pos].treino.cantidadEjerciciosBrazos++;
            break;
        case 4:
            usuarios[pos].treino.piernas[usuarios[pos].treino.cantidadEjerciciosPiernas]=cargarEjercicio();
            usuarios[pos].treino.cantidadEjerciciosPiernas++;
            break;
        }

        printf("                                                                                          \n");
        printf("                                                                                          \n");
        printf("\t\tDesea seguir cargando ejercicios? (s/n)");
        scanf("\t\t%c", &eleccion);
        system("cls");
    }
    menuEntrenamiento(pos);
}

stEjercicio cargarEjercicio()
{
    stEjercicio A;
    printf("\t\tIngrese el nombre del ejercicio \n");
    fflush(stdin);
    gets(A.nombre);
    printf("\t\tIngrese la cantidad de series \n");
    scanf("%d", &A.series);
    printf("\t\tIngrese la cantidad de repeticiones \n");
    scanf("%d", &A.repeticiones);

    return A;

}

void modificarQuitarEjercicio(int pos)
{
    int opcion = 0;

    do
    {
        printf("\n======================== ALIMENTACION ========================");
        printf("                                                                                          ");
        printf("                                                                                          ");
        printf("\n\t\t<1> Modificar Ejercicio/s del dia");
        printf("\n\t\t<2> Quitar Ejercicio/s del dia");
        printf("\n\t\t<3> Volver al Menu de Entrenamiento\n");
        printf("\n\n\t\tIngrese una opcion[1-3]");
        scanf("%i", &opcion);

        system("cls");

        switch(opcion)
        {
        case 1:
            modificarEjercicio(pos);
            break;
        case 2:
            quitarEjercicio(pos);
            break;
        case 3:
            menuEntrenamiento(pos);
            break;
        }
    }
    while(opcion < 1 || opcion > 3);
}

void modificarEjercicio(int pos)
{
    int eleccion = 0;
    int seleccion = 0;

    printf("\n======================== MODIFICAR EJERCICIO ========================\n");
    printf("                                                                                          \n");
    printf("                                                                                          \n");

    if(usuarios[pos].treino.cantidadEjerciciosTotal == 0)
    {
        printf("\t\tAun no hay ejercicios cargados\n");
    }
    else
    {
        do
        {
            printf("\t\tElija grupo de ejercicios a modificar \n");
            printf("                                                                                          \n");
            printf("\t\t<1> - PECHO\n");
            printf("\t\t<2> - ESPALDA\n");
            printf("\t\t<3> - BRAZO\n");
            printf("\t\t<4> - PIERNA\n");
            scanf("\t\t%d", &seleccion);

            if(seleccion < 1 || seleccion > 4)
            {
                printf("\t\tIngrese un grupo valido\n");
            }

            switch(seleccion)
            {
            case 1:
                mostrarEjercicioPecho(pos);
                printf("\t\tIngrese el numero del ejercicio que quiere modificar\n");
                scanf("\t\t%d", &eleccion);
                usuarios[pos].treino.pecho[eleccion-1]=cargarEjercicio();

                if(eleccion > usuarios[pos].treino.cantidadEjerciciosPecho || eleccion < 1)
                {
                    printf("\t\tIngrese un numero de ejercicio valido\n");
                    printf("\n");
                }
                break;
            case 2:
                mostrarEjercicioEspalda(pos);
                printf("\t\tIngrese el numero del ejercicio que quiere modificar\n");
                scanf("\t\t%d", &eleccion);
                usuarios[pos].treino.espalda[eleccion-1]=cargarEjercicio();

                if(eleccion > usuarios[pos].treino.cantidadEjerciciosEspalda || eleccion < 1)
                {
                    printf("\t\tIngrese un numero de ejercicio valido\n");
                    printf("\n");
                }
                break;
            case 3:
                mostrarEjercicioBrazo(pos);
                printf("\t\tIngrese el numero del ejercicio que quiere modificar\n");
                scanf("\t\t%d", &eleccion);
                usuarios[pos].treino.brazo[eleccion-1]=cargarEjercicio();

                if(eleccion > usuarios[pos].treino.cantidadEjerciciosBrazos || eleccion < 1)
                {
                    printf("\t\tIngrese un numero de ejercicio valido\n");
                    printf("\n");
                }
                break;
            case 4:
                mostrarEjercicioPierna(pos);
                printf("\t\tIngrese el numero del ejercicio que quiere modificar\n");
                scanf("\t\t%d", &eleccion);
                usuarios[pos].treino.piernas[eleccion-1]=cargarEjercicio();

                if(eleccion > usuarios[pos].treino.cantidadEjerciciosPiernas || eleccion < 1)
                {
                    printf("\t\tIngrese un numero de ejercicio valido\n");
                    printf("\n");
                }
                break;
            }

        }
        while(seleccion < 1 || seleccion > 4);
        printf("\n");



        printf("\n");

        //system("cls");

    }
    system("pause");
    system("cls");
    modificarQuitarEjercicio(pos);
}


void quitarEjercicio(int pos)
{
    int eleccion;
    int seleccion;

    printf("\n======================== QUITAR EJERCICIO ========================\n");
    printf("                                                                                          \n");
    printf("                                                                                          \n");

    if(usuarios[pos].treino.cantidadEjerciciosTotal == 0)
    {
        printf("\t\tAun no hay ejercicios cargados\n");
    }
    else
    {
        do
        {
            printf("\t\tElija grupo de ejercicios a eliminar \n");
            printf("                                                                                          \n");
            printf("\t\t<1> - PECHO\n");
            printf("\t\t<2> - ESPALDA\n");
            printf("\t\t<3> - BRAZO\n");
            printf("\t\t<4> - PIERNA\n");
            scanf("\t\t%d", &seleccion);

            if(seleccion < 1 || seleccion > 4)
            {
                printf("\t\tIngrese un grupo valido\n");
            }

            switch(seleccion)
            {
            case 1:
                mostrarEjercicioPecho(pos);
                printf("\t\tIngrese el numero del ejercicio que quiere eliminar\n");
                scanf("\t\t%d", &eleccion);
                eliminarEjercicio(pos,eleccion-1,seleccion);

                if(eleccion > usuarios[pos].treino.cantidadEjerciciosPecho || eleccion < 1)
                {
                    printf("\t\tIngrese un numero de ejercicio valido\n");
                    printf("\n");
                }
                break;
            case 2:
                mostrarEjercicioEspalda(pos);
                printf("\t\tIngrese el numero del ejercicio que quiere eliminar\n");
                scanf("\t\t%d", &eleccion);
                eliminarEjercicio(pos,eleccion-1,seleccion);

                if(eleccion > usuarios[pos].treino.cantidadEjerciciosEspalda || eleccion < 1)
                {
                    printf("\t\tIngrese un numero de ejercicio valido\n");
                    printf("\n");
                }
                break;
            case 3:
                mostrarEjercicioBrazo(pos);
                printf("\t\tIngrese el numero del ejercicio que quiere eliminar\n");
                scanf("\t\t%d", &eleccion);
                eliminarEjercicio(pos,eleccion-1,seleccion);

                if(eleccion > usuarios[pos].treino.cantidadEjerciciosBrazos || eleccion < 1)
                {
                    printf("\t\tIngrese un numero de ejercicio valido\n");
                    printf("\n");
                }
                break;
            case 4:
                mostrarEjercicioPierna(pos);
                printf("\t\tIngrese el numero del ejercicio que quiere eliminar\n");
                scanf("\t\t%d", &eleccion);
                eliminarEjercicio(pos,eleccion-1,seleccion);

                if(eleccion > usuarios[pos].treino.cantidadEjerciciosPiernas || eleccion < 1)
                {
                    printf("\t\tIngrese un numero de ejercicio valido\n");
                    printf("\n");
                }
                break;
            }

        }
        while(seleccion < 1 || seleccion > 4);
    }

    getchar();
    system("cls");
    modificarQuitarEjercicio(pos);
}

void eliminarEjercicio(int pos, int eleccion, int seleccion)
{
    int indice = 0;
    int j;

    switch(seleccion)
    {
    case 1:
        while(strcmpi(usuarios[pos].treino.pecho[eleccion].nombre, usuarios[pos].treino.pecho[indice].nombre)!= 0)
        {
            indice++;
        }
        for(j = indice - 1; j < usuarios[pos].treino.cantidadEjerciciosPecho - 1; j++)
        {
            usuarios[pos].treino.pecho[j] = usuarios[pos].treino.pecho[j + 1];
        }
        usuarios[pos].treino.cantidadEjerciciosPecho--;
        break;
    case 2:
        while(strcmpi(usuarios[pos].treino.espalda[eleccion].nombre, usuarios[pos].treino.espalda[indice].nombre)!= 0)
        {
            indice++;
        }
        for(j = indice - 1; j < usuarios[pos].treino.cantidadEjerciciosEspalda - 1; j++)
        {
            usuarios[pos].treino.espalda[j] = usuarios[pos].treino.espalda[j + 1];
        }
        usuarios[pos].treino.cantidadEjerciciosEspalda--;
        break;
    case 3:
        while(strcmpi(usuarios[pos].treino.brazo[eleccion].nombre, usuarios[pos].treino.brazo[indice].nombre)!= 0)
        {
            indice++;
        }
        for(j = indice - 1; j < usuarios[pos].treino.cantidadEjerciciosBrazos - 1; j++)
        {
            usuarios[pos].dias.cena[j] = usuarios[pos].dias.cena[j + 1];
        }
        usuarios[pos].treino.cantidadEjerciciosBrazos--;
        break;
    case 4:
        while(strcmpi(usuarios[pos].treino.piernas[eleccion].nombre, usuarios[pos].treino.piernas[indice].nombre)!= 0)
        {
            indice++;
        }
        for(j = indice - 1; j < usuarios[pos].treino.cantidadEjerciciosPiernas - 1; j++)
        {
            usuarios[pos].treino.piernas[j] = usuarios[pos].treino.piernas[j + 1];
        }
        usuarios[pos].treino.cantidadEjerciciosPiernas--;
        break;
    }

    usuarios[pos].treino.cantidadEjerciciosTotal--;
}


void verEntrenamientoDelDia(int pos)
{
    printf("\t\t////// PECHO //////\n");

    mostrarEjercicioPecho(pos);

    printf("\n");
    printf("\t\t////// ESPALDA //////\n");

    mostrarEjercicioEspalda(pos);

    printf("\n");
    printf("\t\t//////// BRAZO ////////\n");

    mostrarEjercicioBrazo(pos);
    printf("\n");

    printf("\t\t/////// PIERNA ///////\n");

    mostrarEjercicioPierna(pos);
    printf("\n");

    printf("Pulsa una tecla para volver al Menu de Entrenamiento\n");
    getchar();
    system("cls");
    menuEntrenamiento(pos);
}

void mostrarEjercicioPecho(int pos)
{
    int i;

    for(i = 0; i< usuarios[pos].treino.cantidadEjerciciosPecho; i++)
    {
        printf("\t\t<%i>%s (%d X %d)\n", i+1, usuarios[pos].treino.pecho[i].nombre, usuarios[pos].treino.pecho[i].series, usuarios[pos].treino.pecho[i].repeticiones);

    }
}

void mostrarEjercicioEspalda(int pos)
{
    int i;

    for(i = 0; i< usuarios[pos].treino.cantidadEjerciciosEspalda; i++)
    {
        printf("\t\t<%i>%s (%d X %d)\n", i+1,usuarios[pos].treino.espalda[i].nombre, usuarios[pos].treino.espalda[i].series, usuarios[pos].treino.espalda[i].repeticiones);
    }
}

void mostrarEjercicioBrazo(int pos)
{
    int i;

    for(i = 0; i< usuarios[pos].treino.cantidadEjerciciosBrazos; i++)
    {
        printf("\t\t<%i>%s (%d X %d)\n", i+1,usuarios[pos].treino.brazo[i].nombre, usuarios[pos].treino.brazo[i].series, usuarios[pos].treino.brazo[i].repeticiones);
    }
}

void mostrarEjercicioPierna(int pos)
{
    int i;

    for(i = 0; i< usuarios[pos].treino.cantidadEjerciciosPiernas; i++)
    {
        printf("\t\t<%i>%s (%d X %d)\n", i+1,usuarios[pos].treino.piernas[i].nombre, usuarios[pos].treino.piernas[i].series, usuarios[pos].treino.piernas[i].repeticiones);
    }
}


