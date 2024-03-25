//
// Created by jack on 25/3/24.
//
#include <map>
#include <iostream>
#include "passenger.h"
#include "displaySurvivalByGenderAndAge.h"

void displaySurvivalByGenderAndAge(const std::vector<Passenger>& passengers) {
    // Using a map to hold counts for each gender and age range
    // Key: Pair of string (gender) and int (age range)
    // Value: Pair of int (survived count) and int (died count)
    std::map<std::pair<std::string, int>, std::pair<int, int>> stats;

    for (const auto& passenger : passengers) {
        // Determine the age range
        int ageRange = passenger.getAge() / 10;

        // Increment the appropriate counter
        auto key = std::make_pair(passenger.getSex(), ageRange);
        if (passenger.getSurvived()) {
            stats[key].first++; // Increment survived count
        } else {
            stats[key].second++; // Increment died count
        }
    }

    // Display the results
    for (const auto& entry : stats) {
        std::string gender = entry.first.first;
        int ageRange = entry.first.second;
        int survivedCount = entry.second.first;
        int diedCount = entry.second.second;

        std::cout << "Gender: " << gender
                  << ", Age Range: " << ageRange * 10 << "-" << (ageRange + 1) * 10 - 1
                  << ", Survived: " << survivedCount
                  << ", Died: " << diedCount << std::endl;
    }
}
