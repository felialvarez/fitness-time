#ifndef GESTIONALIMENTACION_H_INCLUDED
#define GESTIONALIMENTACION_H_INCLUDED
#include "const.h"
#include "menu.h"

/////////////////PROTOTIPADO//////////////////////
void menuAlimentacion(int pos);//muestra el menu de alimentacion y da la opcion a elegir
void agregarAlimento(int pos);//agrega alimento deseado a su consumo diario
float gramos();//gramos a consumir del alimento
void verAlimentosDelDia(int pos);//muestra alimentos del dia
void mostrarAlimentoenDesayuno(int pos);
void mostrarAlimentoenAlmuerzo(int pos);
void mostrarAlimentoenCena(int pos);
void mostrarAlimentoenMerienda(int pos);
float calcularProteinaDiaria(int pos);
float calcularCaloriasDiaria(int pos);
float calcularGrasaDiaria(int pos);
float calcularCarbohidratosDiarios(int pos);
void modificarAlimento(int pos);//modifica el alimento deseado
void quitarAlimento(int pos);//quita el alimento deseado
void modificarQuitarAlimento(int pos);//da a elegir si modificar o quitar
void cambiarGramaje(int eleccion, int seleccion, int pos);// si elige cambiar gramaje, se cambia
void seleccionarOtroAlimento(int eleccion, int seleccion, int pos);//se reemplaza ese alimento por otro alimento
void eliminarAlimento(int pos, int eleccion, int seleccion);//elimina alimento
void mostrarAlimentosDispoRecursivo(stAlimento *alimentosDispo, int cantidadAlimentos ,int posicion);//muestra alimentos disponubles recursivamente

#endif // GESTIONALIMENTACION_H_INCLUDED
