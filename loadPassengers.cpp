//
// Created by jack on 25/3/24.
//

#include <iostream>
#include <vector>
#include "Passenger.h"
#include "loadPassengers.h"

#include <fstream>
#include <sstream>

#include <string>
#include <algorithm>


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
