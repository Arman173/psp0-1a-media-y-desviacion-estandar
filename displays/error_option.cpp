#include "displays.h"
using namespace std;

// definimos la funcion que despliega la pantalla inicial del programa.
void error_option()
{
     system("cls");
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
     cout << "Presione cualquier tecla para continuar...";
     getchar();
}