//
// Created by jack on 25/3/24.
//
#include <iostream>
#include "Passenger.h"
#include "selectPassengersByAgeAndSurvival.h"

void selectPassengersByAgeAndSurvival(const std::vector<Passenger>& passengers) {
    int startAge, endAge;
    char survivedInput;
    bool survived;

    std::cout << "Enter start age: ";
    std::cin >> startAge;
    std::cout << "Enter end age: ";
    std::cin >> endAge;
    std::cout << "Survived (Y/N): ";
    std::cin >> survivedInput;

    survived = (survivedInput == 'Y' || survivedInput == 'y');

    for (const auto& passenger : passengers) {
        if (passenger.getAge() >= startAge && passenger.getAge() <= endAge && passenger.getSurvived() == survived) {
            std::cout << "Passenger ID: " << passenger.getPassengerId()
                      << ", Name: " << passenger.getName()
                      << ", Sex: " << passenger.getSex()
                      << ", Age: " << passenger.getAge()
                      << ", Survived: " << (passenger.getSurvived() ? "Yes" : "No")
                      << ", Class: " << passenger.getPclass()
                      << ", SibSp: " << passenger.getSibSp()
                      << ", Parch: " << passenger.getParch()
                      << ", Ticket: " << passenger.getTicket()
                      << ", Fare: $" << passenger.getFare()
                      << ", Cabin: " << passenger.getCabin()
                      << ", Embarked: " << passenger.getEmbarked()
                      << std::endl;
        }
    }
}
