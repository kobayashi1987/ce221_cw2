//
// Created by jack on 25/3/24.
//

#include <iostream>
#include "passenger.h"
#include "displaySampleData.h"

void displaySampleData(const std::vector<Passenger>& passengers) {
    std::cout << "Total passengers loaded: " << passengers.size() << std::endl;

    // Display up to the first five passengers
    int count = 0;
    for (const auto& passenger : passengers) {
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
        if (++count == 5) break; // Only display the first 5
    }
}
