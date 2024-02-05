#include "displays.h"
using namespace std;

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
    for (int i = 0; i < n; i++)
    {
        // dejamos de pedir el dato hasta que este sea valido.
        do
        {
            cout << endl
                 << tab << "dato " << i + 1 << ": ";
            cin >> data;
            if (convertStrToFloat(data_str, &data))
                break;
            cout << endl
                 << tab << "error al leer el dato " << i + 1 << "...";
        } while (true);
    }
    cout << endl
         << endl
         << tab;
    cout << tab << "Datos agregados correctamente.";
    cout << endl
         << endl
         << tab;
    cout << "Presione cualquier tecla para continuar...";
    getchar();
    return SUCCESS_STATE;
}