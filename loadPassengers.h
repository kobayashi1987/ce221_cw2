//
// Created by jack on 25/3/24.
//

#ifndef ASSIGNMENT02_LOADPASSENGERS_H
#define ASSIGNMENT02_LOADPASSENGERS_H

#include <vector>
#include "Passenger.h"

std::vector<std::string> parseCSVLine(const std::string& line);
std::vector<Passenger> loadPassengers(const std::string& filename);


#endif //ASSIGNMENT02_LOADPASSENGERS_H
