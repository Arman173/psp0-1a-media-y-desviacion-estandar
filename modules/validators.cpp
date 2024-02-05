#include "validators.h"
using namespace std;

bool convertStrToFloat(string str, float *number)
{
    bool converted = false;

    try
    {
        size_t pos = 0;
        *number = stof(str, &pos);

        // se verifica si la conversion tuvo exito.
        converted = (pos == str.length());
    }
    catch (std::exception const &)
    {
        // error al convertir, converted seguira siendo false.
    }

    return converted;
}

bool getting_data_from_file(ifstream file, float_list list)
{
    bool state = true; // bansera que guarda si hubo un error al leer el archivo.
    string str;        // string que sera un buffer para guardar el contenido del archivo.
    while (getline(file, str))
    {
        float n;
        if (!convertStrToFloat(str, &n))
        {
            state = false;
            break;
        }
        list.push(n);
    }
    return state;
}