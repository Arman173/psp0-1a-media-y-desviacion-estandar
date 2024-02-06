#include "stadistic.h"

// funcion que calcula la media de una lista de datos flotantes.
float average(float_list *data)
{
    float sum = 0;
    for (int i = 0; i < data->size(); i++)
        sum += data->element(i);
    return sum / (float)(data->size());
}

// funcion que calcula la desviacion estandar de una lista de datos flotantes.
float standard_deviation(float_list *data)
{
    float data_average = average(data);
    float sum = 0;
    for (int i = 0; i < data->size(); i++)
    {
        float x = data->element(i);
        sum += pow((x - data_average), 2.0);
    }
    return sqrt(sum / ((float)data->size() - 1.0));
}