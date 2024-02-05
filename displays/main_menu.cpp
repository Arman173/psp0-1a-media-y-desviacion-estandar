#include "displays.h"
using namespace std;

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
     cout << "Introduzca la opcion deseada:";
}