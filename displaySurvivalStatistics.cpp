//
// Created by jack on 25/3/24.
//

#include <iostream>
#include "passenger.h"
#include "displaySurvivalStatistics.h"

void displaySurvivalStatistics(const std::vector<Passenger>& passengers) {
    int survivedCount[2] = {0, 0}; // 0 for male, 1 for female
    for (const auto& passenger : passengers) {
        if (passenger.getSurvived()) {
            if (passenger.getSex() == "male") survivedCount[0]++;
            else if (passenger.getSex() == "female") survivedCount[1]++;
        }
    }
    std::cout << "Survivors: Males = " << survivedCount[0] << ", Females = " << survivedCount[1] << std::endl;
}