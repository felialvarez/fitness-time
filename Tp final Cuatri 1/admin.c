#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "const.h"
#include "menu.h"
#include "admin.h"

void modificarArregloUsuarios(int validos)
{
    int eleccion = 0;

    system("cls");

    printf("\n======================== MENU DE ADMIN ========================");
    printf("                                                                                          ");
    printf("                                                                                          ");
    printf("                                                                                          \n");
    printf("\n\t\t<1> Dar de baja usuario");
    printf("\n\t\t<2> Restaurar usuario");
    printf("\n\t\t<3> Inicio de sesion");
    printf("\n\n\t\tIngrese una opcion[1-3]");
    scanf("%d", &eleccion);
    switch(eleccion)
    {
    case 1:
        borrarUsuario(validos);
        break;
    case 2:
        restaurarUsuario(validos);
        break;
    case 3:
        registrarseOlogin();
        break;
    default:
        modificarArregloUsuarios(validos);
        break;
    }
    getchar();
}

void borrarUsuario(int validos)
{
    system("cls");
    int seleccion;
    printf("\n======================== LISTA DE USUARIOS ========================");
    printf("                                                                                          ");
    printf("                                                                                          ");
    for(int i=0; i<validos; i++)
    {
        if(usuarios[i].datosSesion.estado==1)
        {
            printf("\n\t\t%d- %s",i+1,usuarios[i].datosSesion.nombreUsuario);
        }
    }
    printf("\nIngrese numero del usuario a dar de baja: \n");
    scanf("%d", &seleccion);

    usuarios[seleccion-1].datosSesion.estado=0;
    modificarArregloUsuarios(validos);
}

void restaurarUsuario(int validos)
{
    system("cls");
    int seleccion;
    printf("\n======================== LISTA DE USUARIOS ========================");
    printf("                                                                                          ");
    printf("                                                                                          ");
    for(int i=0; i<validos; i++)
    {
        if(usuarios[i].datosSesion.estado==0)
        {
            printf("\n\t\t%d- %s",i+1,usuarios[i].datosSesion.nombreUsuario);
        }
    }
    printf("\nIngrese numero del usuario a restaurar: \n");
    scanf("%d", &seleccion);

    usuarios[seleccion-1].datosSesion.estado=1;
    modificarArregloUsuarios(validos);
}
