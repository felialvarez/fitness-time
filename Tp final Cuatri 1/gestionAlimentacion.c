#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "gestionAlimentacion.h"
#include "menu.h"

stAlimento* alimentosDispo;
float proteinaDiaria;
float grasasDiarias;
float carbohidratosDiarios;
float caloriasDiarias;
int cantidadAlimentos = 0;
int posicionDesayuno = 0;
int posicionAlmuerzo = 0;
int posicionCena = 0;
int posicionMerienda = 0;


void menuAlimentacion(int pos)
{
    int opcion = 0;

    printf("\n======================== ALIMENTACION ========================");
    printf("                                                                                          ");
    printf("                                                                                          ");
    printf("\n\t\t<1> Agregar Alimento/s");
    printf("\n\t\t<2> Modificar/Quitar Alimento/s del dia");
    printf("\n\t\t<3> Ver Informacion Nutricional Diaria:");
    printf("\n\t\t<4> Volver al Menu Usuario\n");
    printf("\n\n\t\tIngrese una opcion[1-4]");
    scanf("%i", &opcion);

    system("cls");

    switch(opcion)
    {
    case 1:
        agregarAlimento(pos);
        break;
    case 2:
        modificarQuitarAlimento(pos);
        break;
    case 3:
        verAlimentosDelDia(pos);
        break;
    case 4:
        menu(pos);
        break;
    }
}

void modificarQuitarAlimento(int pos)
{
    int opcion = 0;

    printf("\n======================== ALIMENTACION ========================");
    printf("                                                                                          ");
    printf("                                                                                          ");
    printf("\n\t\t<1> Modificar Alimento/s del dia");
    printf("\n\t\t<2> Quitar Alimento/s del dia");
    printf("\n\t\t<3> Volver al Menu Alimentacion\n");
    printf("\n\n\t\tIngrese una opcion[1-3]");
    scanf("%i", &opcion);

    system("cls");

    switch(opcion)
    {
    case 1:
        modificarAlimento(pos);
        break;
    case 2:
        quitarAlimento(pos);
        break;
    case 3:
        menuAlimentacion(pos);

        break;
    }
}

void modificarAlimento(int pos)
{
    int eleccion = 0;
    int eleccion2 = 0;
    int seleccion = 0;
    int i;

    printf("\n======================== MODIFICAR ALIMENTO ========================\n");
    printf("                                                                                          \n");
    printf("                                                                                          \n");

    if(usuarios[pos].dias.cantAlimentosAgregados == 0)
    {
        printf("\t\tAun no hay alimentos cargados\n\n\n");
    }
    else
    {
        for(i = 0; i < usuarios[pos].dias.cantAlimentosAgregados; i++)
        {
            printf("\t\t<%d> - %s\n", i + 1, usuarios[pos].dias.todos[i].nombre);
            printf("\t\t Gramos consumidos: %.2f gr\n", usuarios[pos].dias.todos[i].gramosAlimento);
            printf("\t\t------------------------------------------\n");
        }

        printf("\n");
        do
        {
            printf("\t\tIngrese el numero del alimento que quiere modificar\n");
            scanf("\t\t%d", &eleccion);

            if(eleccion > usuarios[pos].dias.cantAlimentosAgregados || eleccion < 1)
            {
                printf("\t\tIngrese un numero de alimento valido\n");
                printf("\n");
            }
        }
        while(eleccion > usuarios[pos].dias.cantAlimentosAgregados || eleccion < 1);

        printf("\n");

        do
        {
            printf("\t\tEn que momento desea ser modificado? \n");
            printf("                                                                                          \n");
            printf("\t\t<1> - DESAYUNO\n");
            printf("\t\t<2> - ALMUERZO\n");
            printf("\t\t<3> - CENA\n");
            printf("\t\t<4> - MERIENDA/OTROS\n");
            scanf("\t\t%d", &seleccion);

            if(seleccion < 1 || seleccion > 5)
            {
                printf("\t\tIngrese un momento valido\n");
            }
        }
        while(seleccion < 1 || seleccion > 4);

        printf("\n");
        do
        {
            printf("\n\t\t<1> Cambiar gramaje");
            printf("\n\t\t<2> Seleccionar otro alimento");
            scanf("\t\t%d", &eleccion2);

            if(eleccion2 < 1 || eleccion2 > 2)
            {
                printf("\t\tIngrese una opcion valida\n");
            }
        }
        while(eleccion2 < 1 || eleccion2 > 2);
        system("cls");

        switch(eleccion2)
        {
        case 1:
            cambiarGramaje(eleccion, seleccion, pos);
            break;
        case 2:
            seleccionarOtroAlimento(eleccion, seleccion, pos);
            break;
        }
    }
    system("pause");
    system("cls");
    modificarQuitarAlimento(pos);
}

void cambiarGramaje(int eleccion, int seleccion, int pos)
{
    float gramos = 0;
    int i = 0;

    printf("\n======================== CAMBIAR GRAMAJE ========================");
    printf("                                                                                          ");
    printf("                                                                                          ");
    printf("\t\tCuantos gramos desea consumir de %s?\n", usuarios[pos].dias.todos[eleccion - 1].nombre);
    scanf("\t\t%f", &gramos);

    usuarios[pos].dias.todos[eleccion - 1].gramosAlimento = gramos;

    if(seleccion == 1)
    {
        while(strcmp(usuarios[pos].dias.todos[eleccion - 1].nombre, usuarios[pos].dias.desayuno[i].nombre) != 0)
        {
            i++;
        }
        usuarios[pos].dias.desayuno[i].proteina = (gramos/usuarios[pos].dias.desayuno[i].gramosAlimento)*usuarios[pos].dias.desayuno[i].proteina;
        usuarios[pos].dias.desayuno[i].calorias = (gramos/usuarios[pos].dias.desayuno[i].gramosAlimento)*usuarios[pos].dias.desayuno[i].calorias;
        usuarios[pos].dias.desayuno[i].grasas = (gramos/usuarios[pos].dias.desayuno[i].gramosAlimento)*usuarios[pos].dias.desayuno[i].grasas;
        usuarios[pos].dias.desayuno[i].carbohidratos = (gramos/usuarios[pos].dias.desayuno[i].gramosAlimento)*usuarios[pos].dias.desayuno[i].carbohidratos;
        usuarios[pos].dias.desayuno[i].gramosAlimento = gramos;
    }
    else if(seleccion == 2)
    {
        while(strcmp(usuarios[pos].dias.todos[eleccion - 1].nombre, usuarios[pos].dias.almuerzo[i].nombre) != 0)
        {
            i++;
        }
        usuarios[pos].dias.almuerzo[i].proteina = (gramos/usuarios[pos].dias.almuerzo[i].gramosAlimento)*usuarios[pos].dias.almuerzo[i].proteina;
        usuarios[pos].dias.almuerzo[i].calorias = (gramos/usuarios[pos].dias.almuerzo[i].gramosAlimento)*usuarios[pos].dias.almuerzo[i].calorias;
        usuarios[pos].dias.almuerzo[i].grasas = (gramos/usuarios[pos].dias.almuerzo[i].gramosAlimento)*usuarios[pos].dias.almuerzo[i].grasas;
        usuarios[pos].dias.almuerzo[i].carbohidratos = (gramos/usuarios[pos].dias.almuerzo[i].gramosAlimento)*usuarios[pos].dias.almuerzo[i].carbohidratos;
        usuarios[pos].dias.almuerzo[i].gramosAlimento = gramos;
        usuarios[pos].dias.almuerzo[i].gramosAlimento = gramos;
    }
    else if(seleccion == 3)
    {
        while(strcmp(usuarios[pos].dias.todos[eleccion - 1].nombre, usuarios[pos].dias.cena[i].nombre) != 0)
        {
            i++;
        }
        usuarios[pos].dias.cena[i].proteina = (gramos/usuarios[pos].dias.cena[i].gramosAlimento)*usuarios[pos].dias.cena[i].proteina;
        usuarios[pos].dias.cena[i].calorias = (gramos/usuarios[pos].dias.cena[i].gramosAlimento)*usuarios[pos].dias.cena[i].calorias;
        usuarios[pos].dias.cena[i].grasas = (gramos/usuarios[pos].dias.cena[i].gramosAlimento)*usuarios[pos].dias.cena[i].grasas;
        usuarios[pos].dias.cena[i].carbohidratos = (gramos/usuarios[pos].dias.cena[i].gramosAlimento)*usuarios[pos].dias.cena[i].carbohidratos;
        usuarios[pos].dias.cena[i].gramosAlimento = gramos;
        usuarios[pos].dias.cena[i].gramosAlimento = gramos;
    }
    else if(seleccion == 4)
    {
        while(strcmp(usuarios[pos].dias.todos[eleccion - 1].nombre, usuarios[pos].dias.otros[i].nombre) != 0)
        {
            i++;
        }
        usuarios[pos].dias.otros[i].proteina = (gramos/usuarios[pos].dias.otros[i].gramosAlimento)*usuarios[pos].dias.otros[i].proteina;
        usuarios[pos].dias.otros[i].calorias = (gramos/usuarios[pos].dias.otros[i].gramosAlimento)*usuarios[pos].dias.otros[i].calorias;
        usuarios[pos].dias.otros[i].grasas = (gramos/usuarios[pos].dias.otros[i].gramosAlimento)*usuarios[pos].dias.otros[i].grasas;
        usuarios[pos].dias.otros[i].carbohidratos = (gramos/usuarios[pos].dias.otros[i].gramosAlimento)*usuarios[pos].dias.otros[i].carbohidratos;
        usuarios[pos].dias.otros[i].gramosAlimento = gramos;
        usuarios[pos].dias.otros[i].gramosAlimento = gramos;
    }

    printf("\t\tGramaje de %s modificado", usuarios[pos].dias.todos[eleccion -1].nombre);
    getchar();
    system("cls");
    modificarQuitarAlimento(pos);
}

void seleccionarOtroAlimento(int eleccion, int seleccion, int pos)
{
    int eleccion2;
    float gramos = 0;
    int i = 0;
    int j;

    printf("\n======================== SELECCIONAR OTRO ALIMENTO ========================");
    printf("                                                                                          ");
    printf("                                                                                          ");

    for(j = 0; j < cantidadAlimentos; j++)
    {
        printf("\t\t<%d> - %s\n", j + 1, alimentosDispo[j].nombre);
    }
    printf("\n");

    do
    {
        printf("\n\t\tPor que numero de alimento desea modificarlo?");
        scanf("\n\t\t%d", &eleccion2);

        if(eleccion2 < 1 || eleccion2 > j + 1)
        {
            printf("\t\tIngrese una opcion valida\n");
        }
    }
    while(eleccion2 < 1 || eleccion2 > j + 1);

    printf("\n\t\tCuantos gramos desea consumir?");
    scanf("\n\t\t%f", &gramos);


    if(seleccion == 1)
    {
        while(strcmp(usuarios[pos].dias.todos[eleccion - 1].nombre, usuarios[pos].dias.desayuno[i].nombre) != 0)
        {
            i++;
        }
        usuarios[pos].dias.desayuno[i].proteina = (gramos/porcion)*alimentosDispo[eleccion2 - 1].proteina;
        usuarios[pos].dias.desayuno[i].calorias = (gramos/porcion)*alimentosDispo[eleccion2 - 1].calorias;
        usuarios[pos].dias.desayuno[i].grasas = (gramos/porcion)*alimentosDispo[eleccion2 - 1].grasas;
        usuarios[pos].dias.desayuno[i].carbohidratos = (gramos/porcion)*alimentosDispo[eleccion2 - 1].carbohidratos;
        usuarios[pos].dias.desayuno[i].gramosAlimento = gramos;
        strcpy(usuarios[pos].dias.desayuno[i].nombre,alimentosDispo[eleccion2 - 1].nombre);
    }
    else if(seleccion == 2)
    {
        while(strcmp(usuarios[pos].dias.todos[eleccion - 1].nombre, usuarios[pos].dias.almuerzo[i].nombre) != 0)
        {
            i++;
        }
        usuarios[pos].dias.almuerzo[i].proteina = (gramos/porcion)*alimentosDispo[eleccion2 - 1].proteina;
        usuarios[pos].dias.almuerzo[i].calorias = (gramos/porcion)*alimentosDispo[eleccion2 - 1].calorias;
        usuarios[pos].dias.almuerzo[i].grasas = (gramos/porcion)*alimentosDispo[eleccion2 - 1].grasas;
        usuarios[pos].dias.almuerzo[i].carbohidratos = (gramos/porcion)*alimentosDispo[eleccion2 - 1].carbohidratos;
        usuarios[pos].dias.almuerzo[i].gramosAlimento = gramos;
        strcpy(usuarios[pos].dias.almuerzo[i].nombre,alimentosDispo[eleccion2 - 1].nombre);
    }
    else if(seleccion == 3)
    {
        while(strcmp(usuarios[pos].dias.todos[eleccion - 1].nombre, usuarios[pos].dias.cena[i].nombre) != 0)
        {
            i++;
        }
        usuarios[pos].dias.cena[i].proteina = (gramos/porcion)*alimentosDispo[eleccion2 - 1].proteina;
        usuarios[pos].dias.cena[i].calorias = (gramos/porcion)*alimentosDispo[eleccion2 - 1].calorias;
        usuarios[pos].dias.cena[i].grasas = (gramos/porcion)*alimentosDispo[eleccion2 - 1].grasas;
        usuarios[pos].dias.cena[i].carbohidratos = (gramos/porcion)*alimentosDispo[eleccion2 - 1].carbohidratos;
        usuarios[pos].dias.cena[i].gramosAlimento = gramos;
        strcpy(usuarios[pos].dias.cena[i].nombre,alimentosDispo[eleccion2 - 1].nombre);
    }
    else if(seleccion == 4)
    {
        while(strcmp(usuarios[pos].dias.todos[eleccion - 1].nombre, usuarios[pos].dias.otros[i].nombre) != 0)
        {
            i++;
        }
        usuarios[pos].dias.otros[i].proteina = (gramos/porcion)*alimentosDispo[eleccion2 - 1].proteina;
        usuarios[pos].dias.otros[i].calorias = (gramos/porcion)*alimentosDispo[eleccion2 - 1].calorias;
        usuarios[pos].dias.otros[i].grasas = (gramos/porcion)*alimentosDispo[eleccion2 - 1].grasas;
        usuarios[pos].dias.otros[i].carbohidratos = (gramos/porcion)*alimentosDispo[eleccion - 1].carbohidratos;
        usuarios[pos].dias.otros[i].gramosAlimento = gramos;
        strcpy(usuarios[pos].dias.otros[i].nombre,alimentosDispo[eleccion2 - 1].nombre);
    }
    strcpy(usuarios[pos].dias.todos[eleccion - 1].nombre, alimentosDispo[eleccion2 - 1].nombre);
    usuarios[pos].dias.todos[eleccion - 1].gramosAlimento = gramos;
    printf("\n");
    printf("\nAlimento modificado");
    getchar();
    system("cls");
    modificarQuitarAlimento(pos);
}

void quitarAlimento(int pos)
{
    int eleccion;
    int seleccion;
    int i;
    printf("\n======================== QUITAR ALIMENTO ========================\n");
    printf("                                                                                          \n");
    printf("                                                                                          \n");

    if(usuarios[pos].dias.cantAlimentosAgregados == 0)
    {
        printf("\t\tAun no hay alimentos cargados\n\n\n");
    }
    else
    {
        for(i = 0; i < usuarios[pos].dias.cantAlimentosAgregados; i++)
        {
            printf("\t\t<%d> - %s\n", i + 1, usuarios[pos].dias.todos[i].nombre);
            printf("\t\t Gramos consumidos: %.2fgr\n", usuarios[pos].dias.todos[i].gramosAlimento);
            printf("\t\t------------------------------------------\n");
        }
        printf("\n");

        do
        {
            printf("\t\t Ingrese el numero del alimento que quiere modificar\n");
            scanf("%d", &eleccion);

            if(eleccion < 1 || eleccion > usuarios[pos].dias.cantAlimentosAgregados)
            {
                printf("\t\tIngrese una opcion valida\n");
            }
        }
        while(eleccion < 1 || eleccion > usuarios[pos].dias.cantAlimentosAgregados);

        do
        {
            printf("\t\tEn que momento desea ser modificado?\n");
            printf("                                                                                          \n");
            printf("\t\t<1> - DESAYUNO\n");
            printf("\t\t<2> - ALMUERZO\n");
            printf("\t\t<3> - CENA\n");
            printf("\t\t<4> - MERIENDA/OTROS\n");
            scanf("%d", &seleccion);

            if(seleccion < 1 || seleccion > 4)
            {
                printf("\t\tIngrese una opcion valida\n");
            }
        }
        while(seleccion < 1 || seleccion > 4);

        eliminarAlimento(pos, eleccion - 1, seleccion);

        printf("                                                                                          \n");
        printf("\n");
        printf("\t\tAlimento eliminado\n");
    }

    system("pause");
    system("cls");
    modificarQuitarAlimento(pos);
}

void eliminarAlimento(int pos, int eleccion, int seleccion)
{
    int indice = 0;
    int j;

    switch(seleccion)
    {
    case 1:
        while(strcmpi(usuarios[pos].dias.todos[eleccion].nombre, usuarios[pos].dias.desayuno[indice].nombre)!= 0 && usuarios[pos].dias.todos[eleccion].gramosAlimento != usuarios[pos].dias.desayuno[indice].gramosAlimento)
        {
            indice++;
        }
        for(j = indice - 1; j < usuarios[pos].dias.cantidadAlimentosDesayuno - 1; j++)
        {
            usuarios[pos].dias.desayuno[j] = usuarios[pos].dias.desayuno[j + 1];
        }
        usuarios[pos].dias.cantidadAlimentosDesayuno--;
        break;
    case 2:
        while(strcmpi(usuarios[pos].dias.todos[eleccion].nombre, usuarios[pos].dias.almuerzo[indice].nombre)!= 0 && usuarios[pos].dias.todos[eleccion].gramosAlimento != usuarios[pos].dias.almuerzo[indice].gramosAlimento)
        {
            indice++;
        }
        for(j = indice - 1; j < usuarios[pos].dias.cantidadAlimentosAlmuerzo - 1; j++)
        {
            usuarios[pos].dias.almuerzo[j] = usuarios[pos].dias.almuerzo[j + 1];
        }
        usuarios[pos].dias.cantidadAlimentosAlmuerzo--;
        break;
    case 3:
        while(strcmpi(usuarios[pos].dias.todos[eleccion].nombre, usuarios[pos].dias.cena[indice].nombre)!= 0 && usuarios[pos].dias.todos[eleccion].gramosAlimento != usuarios[pos].dias.cena[indice].gramosAlimento)
        {
            indice++;
        }
        for(j = indice - 1; j < usuarios[pos].dias.cantidadAlimentosCena - 1; j++)
        {
            usuarios[pos].dias.cena[j] = usuarios[pos].dias.cena[j + 1];
        }
        usuarios[pos].dias.cantidadAlimentosCena--;
        break;
    case 4:
        while(strcmpi(usuarios[pos].dias.todos[eleccion].nombre, usuarios[pos].dias.otros[indice].nombre)!= 0 && usuarios[pos].dias.todos[eleccion].gramosAlimento != usuarios[pos].dias.otros[indice].gramosAlimento)
        {
            indice++;
        }
        for(j = indice - 1; j < usuarios[pos].dias.cantidadAlimentosMerienda - 1; j++)
        {
            usuarios[pos].dias.otros[j] = usuarios[pos].dias.otros[j + 1];
        }
        usuarios[pos].dias.cantidadAlimentosMerienda--;
        break;
    }
    proteinaDiaria -= usuarios[pos].dias.todos[eleccion].proteina;
    caloriasDiarias -= usuarios[pos].dias.todos[eleccion].calorias;
    grasasDiarias -= usuarios[pos].dias.todos[eleccion].grasas;
    carbohidratosDiarios -= usuarios[pos].dias.todos[eleccion].carbohidratos;

    for(int i = eleccion; i < usuarios[pos].dias.cantAlimentosAgregados - 1; i++)
    {
        usuarios[pos].dias.todos[i] = usuarios[pos].dias.todos[i + 1];
    }

    usuarios[pos].dias.cantAlimentosAgregados--;
}

void agregarAlimento(int pos)
{
    stAlimento A;
    int seleccion = 0;
    int seleccion2 = 0;
    int eleccion = 1;
    float gramos = 0;

    if(cantidadAlimentos == 0)
    {
        FILE* buffer;
        buffer=fopen("Alimentos", "rb");
        if(buffer != NULL)
        {
            while(fread(&A,sizeof(stAlimento),1,buffer)>0)
            {
                cantidadAlimentos++;
            }
            fclose(buffer);
        }
        alimentosDispo = (stAlimento*)malloc(sizeof(stAlimento)*cantidadAlimentos);
    }


    printf("\n======================== AGREGAR ALIMENTOS ========================");

    printf("                                                                                          ");
    printf("                                                                                          ");

    while(eleccion == 1)
    {
        mostrarAlimentosDispoRecursivo(alimentosDispo, cantidadAlimentos, 0);

        do
        {
            printf("\t\tIngrese el numero del alimento a consumir \n");
            printf("                                                                                          \n");
            scanf("\t\t%d", &seleccion);

            if(seleccion > cantidadAlimentos)
            {
                printf("\t\tIngrese un alimento valido\n");
            }
        }
        while(seleccion > cantidadAlimentos);

        printf("\t\tCuantos gramos desea consmir?");
        printf("                                                                                          \n");
        scanf("\t\t%f", &gramos);

        do
        {
            printf("\t\tEn que momento desea ser consumido? \n");
            printf("                                                                                          \n");
            printf("\t\t<1> - DESAYUNO\n");
            printf("\t\t<2> - ALMUERZO\n");
            printf("\t\t<3> - CENA\n");
            printf("\t\t<4> - MERIENDA/OTROS\n");
            scanf("\t\t%d", &seleccion2);

            if(seleccion2 < 1 || seleccion2 > 4)
            {
                printf("\t\tIngrese un momento valido\n");
            }
        }
        while(seleccion2 < 1 || seleccion2 > 4);


        usuarios[pos].dias.todos[usuarios[pos].dias.cantAlimentosAgregados].proteina = (gramos/porcion)*alimentosDispo[seleccion - 1].proteina;
        usuarios[pos].dias.todos[usuarios[pos].dias.cantAlimentosAgregados].calorias = (gramos/porcion)*alimentosDispo[seleccion - 1].calorias;
        usuarios[pos].dias.todos[usuarios[pos].dias.cantAlimentosAgregados].grasas = (gramos/porcion)*alimentosDispo[seleccion - 1].grasas;
        usuarios[pos].dias.todos[usuarios[pos].dias.cantAlimentosAgregados].carbohidratos = (gramos/porcion)*alimentosDispo[seleccion - 1].carbohidratos;
        usuarios[pos].dias.todos[usuarios[pos].dias.cantAlimentosAgregados].gramosAlimento = gramos;
        strcpy(usuarios[pos].dias.todos[usuarios[pos].dias.cantAlimentosAgregados].nombre,alimentosDispo[seleccion - 1].nombre);
        usuarios[pos].dias.cantAlimentosAgregados++;
        switch(seleccion2)
        {
        case 1:
            usuarios[pos].dias.desayuno[usuarios[pos].dias.cantidadAlimentosDesayuno].proteina = (gramos/porcion)*alimentosDispo[seleccion - 1].proteina;
            usuarios[pos].dias.desayuno[usuarios[pos].dias.cantidadAlimentosDesayuno].calorias = (gramos/porcion)*alimentosDispo[seleccion - 1].calorias;
            usuarios[pos].dias.desayuno[usuarios[pos].dias.cantidadAlimentosDesayuno].grasas = (gramos/porcion)*alimentosDispo[seleccion - 1].grasas;
            usuarios[pos].dias.desayuno[usuarios[pos].dias.cantidadAlimentosDesayuno].carbohidratos = (gramos/porcion)*alimentosDispo[seleccion - 1].carbohidratos;
            usuarios[pos].dias.desayuno[usuarios[pos].dias.cantidadAlimentosDesayuno].gramosAlimento = gramos;
            strcpy(usuarios[pos].dias.desayuno[usuarios[pos].dias.cantidadAlimentosDesayuno].nombre,alimentosDispo[seleccion - 1].nombre);
            usuarios[pos].dias.cantidadAlimentosDesayuno++;
            break;
        case 2:
            usuarios[pos].dias.almuerzo[usuarios[pos].dias.cantidadAlimentosAlmuerzo].proteina = (gramos/porcion)*alimentosDispo[seleccion - 1].proteina;
            usuarios[pos].dias.almuerzo[usuarios[pos].dias.cantidadAlimentosAlmuerzo].calorias = (gramos/porcion)*alimentosDispo[seleccion - 1].calorias;
            usuarios[pos].dias.almuerzo[usuarios[pos].dias.cantidadAlimentosAlmuerzo].grasas = (gramos/porcion)*alimentosDispo[seleccion - 1].grasas;
            usuarios[pos].dias.almuerzo[usuarios[pos].dias.cantidadAlimentosAlmuerzo].carbohidratos = (gramos/porcion)*alimentosDispo[seleccion - 1].carbohidratos;
            usuarios[pos].dias.almuerzo[usuarios[pos].dias.cantidadAlimentosAlmuerzo].gramosAlimento = gramos;
            strcpy(usuarios[pos].dias.almuerzo[usuarios[pos].dias.cantidadAlimentosAlmuerzo].nombre,alimentosDispo[seleccion - 1].nombre);
            usuarios[pos].dias.cantidadAlimentosAlmuerzo++;
            break;
        case 3:
            usuarios[pos].dias.cena[usuarios[pos].dias.cantidadAlimentosCena].proteina = (gramos/porcion)*alimentosDispo[seleccion - 1].proteina;
            usuarios[pos].dias.cena[usuarios[pos].dias.cantidadAlimentosCena].calorias = (gramos/porcion)*alimentosDispo[seleccion - 1].calorias;
            usuarios[pos].dias.cena[usuarios[pos].dias.cantidadAlimentosCena].grasas = (gramos/porcion)*alimentosDispo[seleccion - 1].grasas;
            usuarios[pos].dias.cena[usuarios[pos].dias.cantidadAlimentosCena].carbohidratos = (gramos/porcion)*alimentosDispo[seleccion - 1].carbohidratos;
            usuarios[pos].dias.cena[usuarios[pos].dias.cantidadAlimentosCena].gramosAlimento = gramos;
            strcpy(usuarios[pos].dias.cena[usuarios[pos].dias.cantidadAlimentosCena].nombre,alimentosDispo[seleccion - 1].nombre);
            usuarios[pos].dias.cantidadAlimentosCena++;
            break;
        case 4:
            usuarios[pos].dias.otros[usuarios[pos].dias.cantidadAlimentosMerienda].proteina = (gramos/porcion)*alimentosDispo[seleccion - 1].proteina;
            usuarios[pos].dias.otros[usuarios[pos].dias.cantidadAlimentosMerienda].calorias = (gramos/porcion)*alimentosDispo[seleccion - 1].calorias;
            usuarios[pos].dias.otros[usuarios[pos].dias.cantidadAlimentosMerienda].grasas = (gramos/porcion)*alimentosDispo[seleccion - 1].grasas;
            usuarios[pos].dias.otros[usuarios[pos].dias.cantidadAlimentosMerienda].carbohidratos = (gramos/porcion)*alimentosDispo[seleccion - 1].carbohidratos;
            usuarios[pos].dias.otros[usuarios[pos].dias.cantidadAlimentosMerienda].gramosAlimento = gramos;
            strcpy(usuarios[pos].dias.otros[usuarios[pos].dias.cantidadAlimentosMerienda].nombre,alimentosDispo[seleccion - 1].nombre);
            usuarios[pos].dias.cantidadAlimentosMerienda++;
            break;
        }

        printf("                                                                                          \n");
        printf("                                                                                          \n");
        printf("\t\tDesea seguir cargando alimentos? (1/2)");
        scanf("\t\t%d", &eleccion);
        system("cls");
    }
    menuAlimentacion(pos);
}


void mostrarAlimentosDispoRecursivo(stAlimento *alimentosDispo, int cantidadAlimentos,int posicion)
{
    if(posicion == cantidadAlimentos - 1)
    {
        printf("\t\t<%d> - %s\n", posicion + 1, alimentosDispo[posicion].nombre);
    }
    else
    {
        printf("\t\t<%d> - %s\n", posicion + 1, alimentosDispo[posicion].nombre);
        mostrarAlimentosDispoRecursivo(alimentosDispo, cantidadAlimentos, posicion + 1);
    }
}

void verAlimentosDelDia(int pos)
{
    proteinaDiaria = calcularProteinaDiaria(pos);
    grasasDiarias = calcularGrasaDiaria(pos);
    carbohidratosDiarios = calcularCarbohidratosDiarios(pos);
    caloriasDiarias = calcularCaloriasDiaria(pos);

    printf("\n");

    printf("Calorias: %.2f  Proteinas: %.2f  Carbohidratos: %.2f  Grasas: %.2f\n", caloriasDiarias, proteinaDiaria, carbohidratosDiarios, grasasDiarias);

    printf("\n");

    printf("\t\t////// DESAYUNO //////\n");

    mostrarAlimentoenDesayuno(pos);

    printf("\n");
    printf("\t\t////// ALMUERZO //////\n");

    mostrarAlimentoenAlmuerzo(pos);

    printf("\n");
    printf("\t\t//////// CENA ////////\n");

    mostrarAlimentoenCena(pos);
    printf("\n");

    printf("\t\t/////// OTROS ///////\n");

    mostrarAlimentoenMerienda(pos);
    printf("\n");

    printf("Pulsa una tecla para volver al Menu de Alimentacion\n");
    getchar();
    system("cls");
    menuAlimentacion(pos);
}

void mostrarAlimentoenDesayuno(int pos)
{
    int i;

    for(i = 0; i< usuarios[pos].dias.cantidadAlimentosDesayuno; i++)
    {
        printf("\t\t%s\n", usuarios[pos].dias.desayuno[i].nombre);
        printf("\t\t------------------------------------------\n");
        printf("\t\tGramos: %.2f\n", usuarios[pos].dias.desayuno[i].gramosAlimento);
        printf("\t\tProteinas: %.2f\n", usuarios[pos].dias.desayuno[i].proteina);
        printf("\t\tGrasas: %.2f\n", usuarios[pos].dias.desayuno[i].grasas);
        printf("\t\tCarbohidratos: %.2f\n", usuarios[pos].dias.desayuno[i].carbohidratos);
        printf("\t\tCalorias: %.2f\n", usuarios[pos].dias.desayuno[i].calorias);
        printf("\t\t------------------------------------------\n");
    }
}

void mostrarAlimentoenAlmuerzo(int pos)
{
    int i;

    for(i = 0; i< usuarios[pos].dias.cantidadAlimentosAlmuerzo; i++)
    {
        printf("\t\t%s\n", usuarios[pos].dias.almuerzo[i].nombre);
        printf("\t\t------------------------------------------\n");
        printf("\t\tGramos: %.2f\n", usuarios[pos].dias.almuerzo[i].gramosAlimento);
        printf("\t\tProteinas: %.2f\n", usuarios[pos].dias.almuerzo[i].proteina);
        printf("\t\tGrasas: %.2f\n", usuarios[pos].dias.almuerzo[i].grasas);
        printf("\t\tCarbohidratos: %.2f\n", usuarios[pos].dias.almuerzo[i].carbohidratos);
        printf("\t\tCalorias: %.2f\n", usuarios[pos].dias.almuerzo[i].calorias);
        printf("\t\t------------------------------------------\n");
    }
}

void mostrarAlimentoenCena(int pos)
{
    int i;

    for(i = 0; i< usuarios[pos].dias.cantidadAlimentosCena; i++)
    {
        printf("\t\t%s\n", usuarios[pos].dias.cena[i].nombre);
        printf("\t\t------------------------------------------\n");
        printf("\t\tGramos: %.2f\n", usuarios[pos].dias.cena[i].gramosAlimento);
        printf("\t\tProteinas: %.2f\n", usuarios[pos].dias.cena[i].proteina);
        printf("\t\tGrasas: %.2f\n", usuarios[pos].dias.cena[i].grasas);
        printf("\t\tCarbohidratos: %.2f\n", usuarios[pos].dias.cena[i].carbohidratos);
        printf("\t\tCalorias: %.2f\n", usuarios[pos].dias.cena[i].calorias);
        printf("\t\t------------------------------------------\n");
    }
}

void mostrarAlimentoenMerienda(int pos)
{
    int i;

    for(i = 0; i< usuarios[pos].dias.cantidadAlimentosMerienda; i++)
    {
        printf("\t\t%s\n", usuarios[pos].dias.otros[i].nombre);
        printf("\t\t------------------------------------------\n");
        printf("\t\tGramos: %.2f\n", usuarios[pos].dias.otros[i].gramosAlimento);
        printf("\t\tProteinas: %.2f\n", usuarios[pos].dias.otros[i].proteina);
        printf("\t\tGrasas: %.2f\n", usuarios[pos].dias.otros[i].grasas);
        printf("\t\tCarbohidratos: %.2f\n", usuarios[pos].dias.otros[i].carbohidratos);
        printf("\t\tCalorias: %.2f\n", usuarios[pos].dias.otros[i].calorias);
        printf("\t\t------------------------------------------\n");
    }
}

float calcularProteinaDiaria(int pos)
{
    float proteina = 0;

    for (int i = 0; i < usuarios[pos].dias.cantidadAlimentosDesayuno; i++)
    {
        proteina += usuarios[pos].dias.desayuno[i].proteina;
    }

    for (int i = 0; i < usuarios[pos].dias.cantidadAlimentosAlmuerzo; i++)
    {
        proteina += usuarios[pos].dias.almuerzo[i].proteina;
    }

    for (int i = 0; i < usuarios[pos].dias.cantidadAlimentosCena; i++)
    {
        proteina += usuarios[pos].dias.cena[i].proteina;
    }

    for (int i = 0; i < usuarios[pos].dias.cantidadAlimentosMerienda; i++)
    {
        proteina += usuarios[pos].dias.otros[i].proteina;
    }

    return proteina;
}

float calcularCaloriasDiaria(int pos)
{
    float calorias = 0;

    for (int i = 0; i < usuarios[pos].dias.cantidadAlimentosDesayuno; i++)
    {
        calorias += usuarios[pos].dias.desayuno[i].calorias;
    }

    for (int i = 0; i < usuarios[pos].dias.cantidadAlimentosAlmuerzo; i++)
    {
        calorias += usuarios[pos].dias.almuerzo[i].calorias;
    }

    for (int i = 0; i < usuarios[pos].dias.cantidadAlimentosCena; i++)
    {
        calorias += usuarios[pos].dias.cena[i].calorias;
    }

    for (int i = 0; i < usuarios[pos].dias.cantidadAlimentosMerienda; i++)
    {
        calorias += usuarios[pos].dias.otros[i].calorias;
    }

    return calorias;
}

float calcularGrasaDiaria(int pos)
{
    float grasa = 0;

    for (int i = 0; i < usuarios[pos].dias.cantidadAlimentosDesayuno; i++)
    {
        grasa += usuarios[pos].dias.desayuno[i].grasas;
    }

    for (int i = 0; i < usuarios[pos].dias.cantidadAlimentosAlmuerzo; i++)
    {
        grasa += usuarios[pos].dias.almuerzo[i].grasas;
    }

    for (int i = 0; i <usuarios[pos].dias.cantidadAlimentosCena; i++)
    {
        grasa += usuarios[pos].dias.cena[i].grasas;
    }

    for (int i = 0; i < usuarios[pos].dias.cantidadAlimentosMerienda; i++)
    {
        grasa += usuarios[pos].dias.otros[i].grasas;
    }
    return grasa;
}

float calcularCarbohidratosDiarios(int pos)
{
    float carbohidratos = 0;

    for (int i = 0; i < usuarios[pos].dias.cantidadAlimentosDesayuno; i++)
    {
        carbohidratos += usuarios[pos].dias.desayuno[i].carbohidratos;
    }

    for (int i = 0; i < usuarios[pos].dias.cantidadAlimentosAlmuerzo; i++)
    {
        carbohidratos += usuarios[pos].dias.almuerzo[i].carbohidratos;
    }

    for (int i = 0; i < usuarios[pos].dias.cantidadAlimentosCena; i++)
    {
        carbohidratos += usuarios[pos].dias.cena[i].carbohidratos;
    }

    for (int i = 0; i < usuarios[pos].dias.cantidadAlimentosMerienda; i++)
    {
        carbohidratos += usuarios[pos].dias.otros[i].carbohidratos;
    }

    return carbohidratos;
}
