//
// Created by jack on 25/3/24.
//
#include <iostream>
#include "Passenger.h"
#include "searchPassengerByNameWithCaseOption.h"

// Utility function to convert a string to lower case for case-insensitive comparison
std::string toLowerCase(const std::string& str) {
    std::string lowerCaseStr;
    std::transform(str.begin(), str.end(), std::back_inserter(lowerCaseStr),
                   [](unsigned char c){ return std::tolower(c); });
    return lowerCaseStr;
}




void searchPassengerByNameWithCaseOption(const std::vector<Passenger>& passengers) {
    std::string searchTerm;
    char caseOption;
    std::cout << "Enter name or part of name to search: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
    std::getline(std::cin, searchTerm);

    std::cout << "Do you want to search with strict casing? (Y/N): ";
    std::cin >> caseOption;

    bool isCaseSensitive = (caseOption == 'Y' || caseOption == 'y');

    for (const auto& passenger : passengers) {
        std::string passengerName = passenger.getName();

        // If case-insensitive search is selected, convert both search term and passenger name to lower case
        if (!isCaseSensitive) {
            passengerName = toLowerCase(passengerName);
            searchTerm = toLowerCase(searchTerm);
        }

        if (passengerName.find(searchTerm) != std::string::npos) {
            std::cout << "Passenger ID: " << passenger.getPassengerId()
                      << ", Name: " << passenger.getName()
                      << ", Survived: " << (passenger.getSurvived() ? "Yes" : "No") << std::endl;
        }
    }
}