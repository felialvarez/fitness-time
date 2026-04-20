#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

typedef struct
{
    int tipoalimentacion;
    int tipoentrenamiento;
    float peso;
    float altura;
    char genero;
    int edad;
} stDatos;

typedef struct
{
    float calorias;
    float proteina;
    float carbohidratos;
    float grasas;
    float gramosAlimento;
    char nombre[40];
} stAlimento;

typedef struct
{
    stAlimento desayuno[10];
    stAlimento almuerzo[10];
    stAlimento cena[10];
    stAlimento otros[10];
    stAlimento todos[100];
    int cantAlimentosAgregados;
    int cantidadAlimentosDesayuno;
    int cantidadAlimentosCena;
    int cantidadAlimentosAlmuerzo;
    int cantidadAlimentosMerienda;
} stDia;

typedef struct
{
    char nombre[40];
    int repeticiones;
    int series;
} stEjercicio;

typedef struct
{
    stEjercicio pecho[10];
    stEjercicio espalda[10];
    stEjercicio piernas[10];
    stEjercicio brazo[10];
    int cantidadEjerciciosPecho;
    int cantidadEjerciciosEspalda;
    int cantidadEjerciciosPiernas;
    int cantidadEjerciciosBrazos;
    int cantidadEjerciciosTotal;

} stEntrenamiento;

typedef struct
{
    char contrasena[30];
    char nombreUsuario[30];
    int estado;
} stSesion;

typedef struct
{
    stDatos datos;
    stSesion datosSesion;
    stDia dias;
    stEntrenamiento treino;
} stUsuario;

extern stUsuario usuarios[20];
/////////////////PROTOTIPADO//////////////////////
void inicio(); //muestra mensaje inicio
void login(); //pasa el pos para el menu
void registrarse(); //registrar usuario
int loginPos(); //hace el login y devuelve pos
int usuarioRegistrado(); //checkea si ya hay un archivo creado
void menu(int pos); // mueseltra menu de usuario
void registrarseOlogin();// da la opcion de registrarse o logearse
void guardarCambios(); //guarda los cambios dentro del archivo(sobreEscribe)



#endif // MENU_H_INCLUDED
