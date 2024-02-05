#include "displays.h"
using namespace std;

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
    cout << "Presione cualquier tecla para continuar...";
    getchar();
}