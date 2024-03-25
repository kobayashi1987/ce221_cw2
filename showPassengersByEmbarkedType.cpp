//
// Created by jack on 25/3/24.
//

#include <iostream>
#include "passenger.h"
#include "showPassengersByEmbarkedType.h"

void showPassengersByEmbarkedType(const std::vector<Passenger>& passengers) {
    char type;
    std::cout << "Enter embarked type (C = Cherbourg; Q = Queenstown; S = Southampton): ";
    std::cin >> type;
    for (const auto& passenger : passengers) {
        if (passenger.getEmbarked()[0] == type) {
            std::cout << "Passenger ID: " << passenger.getPassengerId()
                      << ", Name: " << passenger.getName()
                      << ", Class: " << passenger.getPclass() << std::endl;
        }
    }
}
