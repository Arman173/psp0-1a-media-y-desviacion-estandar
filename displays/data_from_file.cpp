#include "displays.h"
using namespace std;

// definimos la funcion que despliega la pantalla inicial del programa.
int data_from_file(float_list *list)
{
    system("cls");
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
    cout << "Introduzca el nombre:" << endl;
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