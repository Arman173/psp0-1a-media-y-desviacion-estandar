#include <iostream>
#include "displays.h"
using namespace std;

int main()
{
    char decision;           // decision del usuario.
    float_list *list = NULL; // lista donde se guardara los datos.
    int state = NONE_STATE;  // entero que guardara el estado del programa (si hubo fallos o no).

    starting_display();

    do
    {
        main_menu();
        cin >> decision;
        switch (decision)
        {
        case '1':
            state = data_from_file(list);
            break;
        case '2':
            state = manually_data(list);
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

        if (state = SUCCESS_STATE)
            show_results(list);
        else if (state == ERROR_STATE)
            error_getting_data();

        cout << endl
             << endl
             << '\t';
        cout << "PRESIONE CUALQUIER TECLA PARA CONTINUAR...";

        list->clear();

    } while (decision != '0');

    return 0;
}