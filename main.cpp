#include <iostream>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <iomanip>
#include ".\modules\float_list.h"
#include ".\modules\validators.h"
#include ".\modules\stadistic.h"

// estados de pantallas o procesos del programa.
#define SUCCESS_STATE 0
#define ERROR_STATE 1
#define NONE_STATE 2
// macro para no tener que escribir '\t' en los tabs.
#define tab '\t'

using namespace std;

// declaramos la funcion que contiene la pantalla de inicio.
void starting_display();
// declaramos la funcion que contiene la pantalla del menu principal.
void main_menu();
// declaramos la funcion que contiene la pantalla de opcion invalida.
void error_option();
// declaramos la funcion que contiene la pantalla de carga de datos desde un archivo.
int data_from_file();
// declaramos la funcion que contiene la pantalla de carga de datos manualmente.
int manually_data(float_list *);
// declaramos la funcion que contiene la pantalla de los resultados.
void show_results();
// declaramos la funcion que contiene la pantalla de error al obtener datos.
void error_getting_data();

float_list mylist; // lista donde se guardara los datos.

int main()
{
     char decision;          // decision del usuario.
     int state = NONE_STATE; // entero que guardara el estado del programa (si hubo fallos o no).

     starting_display();

     do
     {
          main_menu();
          cin >> decision;
          switch (decision)
          {
          case '1':
               state = data_from_file();
               break;
          case '2':
               state = manually_data(&mylist);
               break;
          case '0':
               // no hacemos nada...
               state = NONE_STATE;
               break;

          default:
               state = NONE_STATE;
               error_option();
               break;
          }

          if (state == SUCCESS_STATE)
               show_results();
          else if (state == ERROR_STATE)
               error_getting_data();

          cout << endl
               << endl;

          mylist.clear();

     } while (decision != '0');

     return 0;
}

// definimos la funcion que despliega la pantalla inicial del programa.
void starting_display()
{
     cout << endl
          << tab;
     cout << "PROGRAMA PSP0 1A - CALCULO MEDIA Y DESVIACION ESTANDAR";
     cout << endl
          << endl
          << tab;
     cout << "by Armando Canul";
     cout << endl
          << endl
          << endl
          << tab;
     system("pause");
}

// definimos la funcion que despliega la pantalla del menu principal.
void main_menu()
{
     system("cls"); // limpiamos pantalla.
     cout << endl
          << tab;
     cout << "CALCULO MEDIA Y DESVIACION ESTANDAR";
     cout << endl
          << endl;
     cout << tab << "1 - cargar datos desde un archivo" << endl;
     cout << tab << "2 - Introducir los datos manualmente" << endl;
     cout << tab << "0 - salir del programa";
     cout << endl
          << endl
          << endl
          << tab;
     cout << "Introduzca la opcion deseada: ";
}

// definimos la funcion que despliega la pantalla de error por opcion invalida.
void error_option()
{
     system("cls"); // limpiamos pantalla.
     cout << endl
          << tab;
     cout << "CALCULO MEDIA Y DESVIACION ESTANDAR";
     cout << endl
          << endl
          << tab;
     cout << "Opcion INVALIDA... Introduzca una opcion valida." << endl;
     cout << endl
          << tab;
     cout << "opciones:" << endl;
     cout << endl
          << tab;
     cout << tab << "1 - cargar datos desde un archivo" << endl;
     cout << tab << "2 - Introducir los datos manualmente" << endl;
     cout << tab << "0 - salir del programa";
     cout << endl
          << endl
          << endl
          << tab;
     system("pause");
}

// definimos la funcion que despliega la pantalla para cargar datos desde un archivo.
int data_from_file()
{
     system("cls");    // limpiamos pantalla.
     string file_name; // string para guardar el nombre del archivo a buscar.
     cout << endl
          << tab;
     cout << "CALCULO MEDIA Y DESVIACION ESTANDAR";
     cout << endl
          << endl;
     cout << tab << "Introduzca el nombre del archivo de los datos a usar, es" << endl;
     cout << tab << "importante escribirlo con su extencion por ejemplo:" << endl;
     cout << tab << "nombre_archivo.extension. Tambien es importante que el" << endl;
     cout << tab << "archivo se encuentre en el mismo directorio del programa." << endl;
     cout << endl
          << tab;
     cout << "Introduzca el nombre: ";
     cin >> file_name;         // capturamos el nombre del archivo.
     ifstream file(file_name); // abrimos el archivo.
     if (!file.is_open())
     {
          cout << endl
               << tab << "Error al abrir el archivo...";
          system("pause");
          return ERROR_STATE; // error al abrir el archivo.
     }
     if (!getting_data_from_file(&file, &mylist))
     {
          cout << endl
               << tab << "Error al leer algun dato del archivo...";
          file.close();
          system("pause");
          return ERROR_STATE; // error al leer algun dato del archivo.
     }
     file.close();
     cout << endl
          << endl
          << tab;
     cout << tab << "Datos cargados correctamente.";
     cout << endl
          << endl
          << endl
          << tab;
     system("pause");
     return SUCCESS_STATE;
}

// definimos la funcion que despliega la pantalla de carga manual de datos.
int manually_data(float_list *list)
{
     system("cls");   // limpiamos pantalla.
     int n;           // variable para guardar el total de datos que se desean añadir.
     string data_str; // string para guardar lo introducido en la consola.
     float data;      // flotante donde se guardara la conversion de cadena_str -> float.
     cout << endl
          << tab;
     cout << "CALCULO MEDIA Y DESVIACION ESTANDAR";
     cout << endl
          << endl;
     cout << tab << "Introduzca el total de elementos a leer, posteriormente" << endl;
     cout << tab << "vaya introduciendo los datos." << endl;
     cout << endl
          << tab;
     cout << "Introduzca el total de datos:";
     cin >> n; // capturamos el total de datos.

     if (n < 1)
     {
          return ERROR_STATE; // numero n invalido.
     }

     cout << endl;
     // leemos todos los n datos.
     int i = 0;
     while (i < n)
     {
          cout << endl
               << tab << "dato " << i + 1 << ": ";
          cin >> data_str;
          if (convertStrToFloat(data_str, &data))
          {
               mylist.push(data);
               i++;
               continue;
          }
          cout << endl
               << tab << "error al leer el dato " << i + 1 << "...";
     }
     cout << endl
          << endl
          << tab;
     cout << tab << "Datos agregados correctamente.";
     cout << endl
          << endl
          << tab;
     system("pause");
     return SUCCESS_STATE;
}

// imprime los datos de una lista en formato de tabla de 4xn.
void table_from_list()
{
     const int ROWS = 4; // # de columnas.
     const int w = 8;    // ancho de digitos para cada flotante a imprimir.

     cout << tab;
     for (int i = 0; i < mylist.size(); i++)
     {
          cout << setw(w) << fixed << setprecision(3) << mylist.element(i) << "  ";
          if ((i + 1) % ROWS == 0)
               cout << endl
                    << tab;
     }
}

// definimos la funcion que despliega la pantalla de los resultados del programa.
void show_results()
{
     cout << endl
          << tab;
     cout << "CALCULO MEDIA Y DESVIACION ESTANDAR";
     cout << endl
          << endl;
     cout << tab << "Media: " << average(&mylist) << endl
          << endl;
     cout << tab << "Desviacion Estandar: " << standard_deviation(&mylist) << endl
          << endl;
     cout << endl
          << tab << "------------------------------------------" << endl;
     cout << tab << "Lista de datos:" << endl
          << endl;

     table_from_list(); // imprimimos los datos.

     cout << endl
          << endl
          << tab;
     system("pause");
}

// definimos la funcion que despliega la pantalla de error al obtener datos.
void error_getting_data()
{
     system("cls"); // limpiamos pantalla.
     cout << endl
          << tab;
     cout << "CALCULO MEDIA Y DESVIACION ESTANDAR";
     cout << endl
          << endl;
     cout << tab << "Error al obtener los datos para calcular...";
     cout << endl
          << endl
          << tab;
     system("pause");
}