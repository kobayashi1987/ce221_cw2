//
// Created by jack on 25/3/24.
//

#include <iostream>
#include "passenger.h"
#include "searchPassengerByName.h"

void searchPassengerByName(const std::vector<Passenger>& passengers) {
    std::string searchTerm;
    std::cout << "Enter name or part of name to search: ";
    std::cin.ignore(); // Ignore the newline left in the input stream
    std::getline(std::cin, searchTerm);

    for (const auto& passenger : passengers) {
        if (passenger.getName().find(searchTerm) != std::string::npos) {
            std::cout << "Passenger ID: " << passenger.getPassengerId()
                      << ", Name: " << passenger.getName()
                      << ", Survived: " << (passenger.getSurvived() ? "Yes" : "No") << std::endl;
        }
    }
}