//
// Created by jack on 25/3/24.
//

#include <iostream>
#include "passenger.h"
#include "selectPassengersByAgeRange.h"

void selectPassengersByAgeRange(const std::vector<Passenger>& passengers) {
    int startAge, endAge;
    std::cout << "Enter start age: ";
    std::cin >> startAge;
    std::cout << "Enter end age: ";
    std::cin >> endAge;

    for (const auto& passenger : passengers) {
        if (passenger.getAge() >= startAge && passenger.getAge() <= endAge) {
            std::cout << "Passenger ID: " << passenger.getPassengerId()
                      << ", Name: " << passenger.getName()
                      << ", Age: " << passenger.getAge()
                      << ", Survived: " << (passenger.getSurvived() ? "Yes" : "No") << std::endl;
        }
    }
}