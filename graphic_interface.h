//
// Created by mazastya on 4/9/23.
//

#ifndef LAB10_2SEM_C___GRAPHIC_INTERFACE_H
#define LAB10_2SEM_C___GRAPHIC_INTERFACE_H

#endif //LAB10_2SEM_C___GRAPHIC_INTERFACE_H

#include <nlohmann/json.hpp>

using json = nlohmann::json;
void print(json time, json weather, json temperature_min, json temperature_max,
           json sunrise, json sunset, json windspeed);
