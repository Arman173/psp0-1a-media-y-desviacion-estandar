#ifndef _HPP_DISPLAYS
#define _HPP_DISPLAYS

#define SUCCESS_STATE 0
#define ERROR_STATE 1
#define NONE_STATE 2
#define tab '\t'

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "../modules/float_list.h"

// declaramos la funcion que contiene la pantalla de inicio.
void starting_display();
// declaramos la funcion que contiene la pantalla del menu principal.
void main_menu();
// declaramos la funcion que contiene la pantalla de opcion invalida.
void error_option();
// declaramos la funcion que contiene la pantalla de opcion invalida.
int data_from_file(float_list *);
// declaramos la funcion que contiene la pantalla de opcion invalida.
int manually_data(float_list *);
// declaramos la funcion que contiene la pantalla de opcion invalida.
int show_results(float_list *);
// declaramos la funcion que contiene la pantalla de opcion invalida.
int error_getting_data();

#endif