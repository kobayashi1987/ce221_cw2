#include "Passenger.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

#include <stdexcept> // For std::runtime_error

void displaySampleData(const std::vector<Passenger>& passengers);



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



std::vector<std::string> parseCSVLine(const std::string& line) {
    std::vector<std::string> result;
    std::istringstream stream(line);
    std::string field;
    char delim = ',';

    while (stream.good()) {
        std::getline(stream, field, delim);
        size_t start_quote = field.find_first_of('"');
        if (start_quote != std::string::npos) {
            // Concatenate until we find the closing quote
            std::string temp;
            while (std::getline(stream, temp, delim)) {
                field += delim + temp;
                if (temp.find_last_of('"') != std::string::npos) break;
            }
        }
        // Remove potential quotes from the field
        size_t start_pos = field.find_first_of('"');
        while (start_pos != std::string::npos) {
            size_t end_pos = field.find_first_of('"', start_pos + 1);
            field.erase(end_pos, 1);
            field.erase(start_pos, 1);
            start_pos = field.find_first_of('"', start_pos + 1);
        }
        result.push_back(field);
    }
    return result;
}

std::vector<Passenger> loadPassengers(const std::string& filename) {
    std::vector<Passenger> passengers;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    // Skip the header
    std::getline(file, line);

    while (std::getline(file, line)) {
        auto fields = parseCSVLine(line);

        if (fields.size() < 12) {
            // Handle error or incomplete line
            continue;
        }

        int passengerId = std::stoi(fields[0]);
        bool survived = std::stoi(fields[1]) == 1;
        int pclass = std::stoi(fields[2]);
        std::string name = fields[3];
        std::string sex = fields[4];
        int age = fields[5].empty() ? -1 : std::stoi(fields[5]); // Assuming -1 for unknown ages
        int sibSp = std::stoi(fields[6]);
        int parch = std::stoi(fields[7]);
        std::string ticket = fields[8];
        double fare = std::stod(fields[9]);
        std::string cabin = fields[10];
        std::string embarked = fields[11];

        passengers.emplace_back(passengerId, survived, pclass, name, sex, age,
                                sibSp, parch, ticket, fare, cabin, embarked);
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
