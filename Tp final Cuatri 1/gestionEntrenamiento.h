#ifndef GESTIONENTRENAMIENTO_H_INCLUDED
#define GESTIONENTRENAMIENTO_H_INCLUDED
#include "menu.h"

void menuEntrenamiento(int pos);
void agregarEjercicio(int pos);
stEjercicio cargarEjercicio();
void modificarQuitarEjercicio(int pos);
void modificarEjercicio(int pos);
void quitarEjercicio(int pos);
void eliminarEjercicio(int pos, int eleccion, int seleccion);
void verEntrenamientoDelDia(int pos);
void mostrarEjercicioPecho(int pos);
void mostrarEjercicioEspalda(int pos);
void mostrarEjercicioBrazo(int pos);
void mostrarEjercicioPierna(int pos);

#endif // GESTIONENTRENAMIENTO_H_INCLUDED
