#ifndef _HPP_VALIDATOR
#define _HPP_VALIDATOR

#include <iostream>
#include <fstream>
#include "float_list.h"

bool convertStrToFloat(std::string, float *);
bool getting_data_from_file(std::ifstream *, float_list *);

#endif