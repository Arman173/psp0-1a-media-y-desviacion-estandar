#ifndef _HPP_DISPLAYS
#define _HPP_DISPLAYS

// estados de pantallas o procesos del programa.
#define SUCCESS_STATE 0
#define ERROR_STATE 1
#define NONE_STATE 2
// macro para no tener que escribir '\t' en los tabs.
#define tab '\t'

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "../modules/float_list.h"
#include "../modules/validators.h"
#include "../modules/stadistic.h"

// declaramos la funcion que contiene la pantalla de inicio.
void starting_display();
// declaramos la funcion que contiene la pantalla del menu principal.
void main_menu();
// declaramos la funcion que contiene la pantalla de opcion invalida.
void error_option();
// declaramos la funcion que contiene la pantalla de carga de datos desde un archivo.
int data_from_file(float_list *);
// declaramos la funcion que contiene la pantalla de carga de datos manualmente.
int manually_data(float_list *);
// declaramos la funcion que contiene la pantalla de los resultados.
void show_results(float_list *);
// declaramos la funcion que contiene la pantalla de error al obtener datos.
void error_getting_data();

#endif