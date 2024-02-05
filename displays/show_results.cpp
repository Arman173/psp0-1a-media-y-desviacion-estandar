#include "displays.h"
using namespace std;

// imprime los datos de una lista en formato de tabla de 4xn.
void table_from_list(float_list data)
{
    const int columnasPorFila = 4;

    int filas = (data.size() + columnasPorFila - 1) / columnasPorFila;

    for (int i = 0; i < filas; ++i)
    {
        cout << tab;
        for (int j = 0; j < columnasPorFila; ++j)
        {
            int indice = i * columnasPorFila + j;

            if (indice < data.size())
            {
                // Imprimir valor limitando a 5 decimales.
                cout << fixed << setprecision(5) << data[indice] << tab;
            }
            else
            {
                // Dejar en blanco si no hay suficientes datos.
                cout << tab;
            }
        }
        cout << endl;
    }
}

// definimos la funcion que despliega la pantalla de los resultados del programa.
void show_results(float_list *data)
{
    cout << endl
         << tab;
    cout << "CALCULO MEDIA Y DESVIACION ESTANDAR";
    cout << endl
         << endl;
    cout << tab << "Media: " << average(*data) << endl
         << endl;
    cout << tab << "Desviacion Estandar: " << standard_deviation(*data) << endl
         << endl;
    cout << endl
         << tab << "------------------------------------------" << endl;
    cout << "Lista de datos:" << endl
         << endl;

    table_from_list(*data); // imprimimos los datos.

    cout << endl
         << endl;
    cout << tab << "Presione cualquier tecla para continuar...";
    getchar();
}