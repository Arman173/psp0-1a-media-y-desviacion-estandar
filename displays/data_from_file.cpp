#include "displays.h"
using namespace std;

// definimos la funcion que despliega la pantalla para cargar datos desde un archivo.
int data_from_file(float_list *list)
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
         return ERROR_STATE; // error al abrir el archivo.
    }
    if (!getting_data_from_file(&file, list))
    {
         return ERROR_STATE; // error al leer algun dato del archivo.
    }
    cout << endl
         << endl
         << tab;
    cout << tab << "Datos cargados correctamente.";
    cout << endl
         << endl
         << endl
         << tab;
    cout << "Presione cualquier tecla para continuar...";
    getchar();
}