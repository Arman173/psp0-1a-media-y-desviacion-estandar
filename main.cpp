#include <iostream>
#include "displays.h"
using namespace std;

int main()
{
    char decision; // decision del usuario.

    starting_display();

    do
    {
        main_menu();
        cin >> decision;
        switch (decision)
        {
        case '1':
            /* code */
            break;
        case '2':
            /* code */
            break;
        case '0':
            /* code */
            break;

        default:
            error_option();
            break;
        }
    } while (decision != '0');

    return 0;
}