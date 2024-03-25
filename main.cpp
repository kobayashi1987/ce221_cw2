#include "Passenger.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

void displaySampleData(const std::vector<Passenger>& passengers);



void showPassengersByEmbarkedType(const std::vector<Passenger>& passengers) {
    char type;
    std::cout << "Enter embarked type (C = Cherbourg; Q = Queenstown; S = Southampton): ";
    std::cin >> type;
    for (const auto& passenger : passengers) {
        if (passenger.getEmbarked()[0] == type) { // Simple check; adjust as necessary
            std::cout << passenger.getName() << " - " << passenger.getEmbarked() << std::endl;
        }
    }
}

void displaySurvivalStatistics(const std::vector<Passenger>& passengers) {
    int survived[2] = {0, 0}; // Index 0 for males, 1 for females
    for (const auto& passenger : passengers) {
        if (passenger.getSurvived()) {
            if (passenger.getSex() == "male") survived[0]++;
            else if (passenger.getSex() == "female") survived[1]++;
        }
    }
    std::cout << "Survived: Males = " << survived[0] << ", Females = " << survived[1] << std::endl;
}

void searchPassengerByName(const std::vector<Passenger>& passengers) {
    std::string searchTerm;
    std::cout << "Enter name or part of name to search: ";
    std::cin.ignore(); // To clear the newline character from the stream
    std::getline(std::cin, searchTerm);

    for (const auto& passenger : passengers) {
        if (passenger.getName().find(searchTerm) != std::string::npos) {
            std::cout << passenger.getName() << std::endl;
        }
    }
}

void selectPassengersByAgeRange(const std::vector<Passenger>& passengers) {
    int startAge, endAge;
    std::cout << "Enter start age: ";
    std::cin >> startAge;
    std::cout << "Enter end age: ";
    std::cin >> endAge;

    for (const auto& passenger : passengers) {
        if (passenger.getAge() >= startAge && passenger.getAge() <= endAge) {
            std::cout << passenger.getName() << " - Age: " << passenger.getAge() << std::endl;
        }
    }
}







//std::vector<Passenger> loadPassengers(const std::string& filename) {
//    std::vector<Passenger> passengers;
//    std::ifstream file(filename);
//
//    if (!file) {
//        std::cerr << "Failed to open " << filename << std::endl;
//        return passengers; // Early return if file cannot be opened
//    }
//
//
//    std::string line;
//
//    // Skip the header
//    std::getline(file, line);
//
//    while (std::getline(file, line)) {
//        std::istringstream s(line);
//        std::string field, name, sex, embarked;
//        int age;
//        bool survived;
//        // Assuming CSV format: name,sex,age,survived,embarked
//        std::getline(s, name, ',');
//        std::getline(s, sex, ',');
//        std::getline(s, field, ',');
//        age = std::stoi(field);
//        std::getline(s, field, ',');
//        survived = field == "1";
//        std::getline(s, embarked, ',');
//
//        passengers.emplace_back(name, sex, age, survived, embarked);
//    }
//
//    return passengers;
//
//}




std::vector<Passenger> loadPassengers(const std::string& filename) {
    std::vector<Passenger> passengers;
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return passengers; // Early exit if file cannot be opened
    }

    std::string line;
    // Skip the header line
    if (!std::getline(file, line)) {
        std::cerr << "Error or empty file: " << filename << std::endl;
        return passengers; // Handle empty file or error during header read
    }

    while (std::getline(file, line)) {
        if (line.empty()) continue; // Skip any empty lines

        std::istringstream s(line);
        std::string field, name, sex, embarked;
        int age = 0;
        bool survived = false;

        try {
            std::getline(s, name, ',');
            std::getline(s, sex, ',');

            std::getline(s, field, ',');
            age = std::stoi(field); // Convert age from string to int

            std::getline(s, field, ',');
            survived = (field == "1"); // Convert survived status to bool

            std::getline(s, embarked, ',');

            passengers.emplace_back(name, sex, age, survived, embarked);
        } catch (const std::exception& e) {
            std::cerr << "Error parsing line: " << line << "\nException: " << e.what() << std::endl;
            // Optionally, handle or skip the erroneous line
        }
    }

    return passengers;
}


void displayMenu() {
    std::cout << "1. Show passengers based on selected Embarked type\n";
    std::cout << "2. Display survival / death statistics\n";
    std::cout << "3. Search a passenger\n";
    std::cout << "4. Select passengers based on ages\n";
    std::cout << "5. Exit program\n";
    std::cout << "Enter your choice: ";
}



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
                  << "5. Exit program\n"
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
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice, please try again.\n";
        }
    } while(choice != 5);

    return 0;
}

void displaySampleData(const std::vector<Passenger>& passengers) {
    std::cout << "Total passengers loaded: " << passengers.size() << std::endl;

    // Display up to the first five passengers
    int count = 0;
    for (const auto& passenger : passengers) {
        std::cout << "Passenger: " << passenger.getName()
                  << ", Sex: " << passenger.getSex()
                  << ", Age: " << passenger.getAge()
                  << ", Survived: " << (passenger.getSurvived() ? "Yes" : "No")
                  << ", Embarked: " << passenger.getEmbarked() << std::endl;
        if (++count == 5) break; // Only display the first 5
    }
}
