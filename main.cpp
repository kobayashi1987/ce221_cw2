#include "Passenger.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

#include <stdexcept> // For std::runtime_error
#include <cctype>    // For std::tolower
#include <map>

// include necessary headers

#include "selectPassengersByAgeAndSurvival.h"
#include "searchPassengerByNameWithCaseOption.h"
#include "selectPassengersByAgeAndSurvival.h"
#include "displaySurvivalByGenderAndAge.h"
#include "displaySampleData.h"
#include "showPassengersByEmbarkedType.h"
#include "displaySurvivalStatistics.h"
#include "selectPassengersByAgeRange.h"
#include "searchPassengerByName.h"

#include "loadPassengers.h"


int main() {
    std::string filename = "titanic.csv";
    auto passengers = loadPassengers(filename);
    // Display sample data from the loaded passengers
    displaySampleData(passengers);
    int choice;

    do {
        std::cout << "\nMenu:\n"
                  << "1. Show passengers based on selected Embarked type\n"
                  << "2. Display survival / death statistics\n"
                  << "3. Search a passenger\n"
                  << "4. Select passengers based on ages\n"
                  << "5. Display Survival by gender and age (10 years in group)\n"
                  << "6. Search Passenger By Name With Case Option\n"
                  << "7. Select Passengers By Age And Survival\n"
                  << "8. Display sample data\n"
                  << "9. Exit program\n"
                  << "Enter your choice: ";

        std::cin >> choice;

        switch(choice) {
            case 1:
                showPassengersByEmbarkedType(passengers);
                break;
            case 2:
                displaySurvivalStatistics(passengers);
                break;
            case 3:
                searchPassengerByName(passengers);
                break;
            case 4:
                selectPassengersByAgeRange(passengers);
                break;
            case 5:
                displaySurvivalByGenderAndAge(passengers);
                break;
            case 6:
                searchPassengerByNameWithCaseOption(passengers);
                break;
            case 7:
                selectPassengersByAgeAndSurvival(passengers);
                break;
            case 8:
                displaySampleData(passengers);
                break;
            case 9:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice, please try again.\n";
        }
    } while(choice != 9);

    return 0;
}

