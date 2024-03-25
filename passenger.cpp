//
// Created by jack on 25/3/24.
//

#include "Passenger.h"
#include <iostream>

Passenger::Passenger(std::string name, std::string sex, int age, bool survived, std::string embarked)
        : name(name), sex(sex), age(age), survived(survived), embarked(embarked) {}

std::string Passenger::getName() const { return name; }
std::string Passenger::getSex() const { return sex; }
int Passenger::getAge() const { return age; }
bool Passenger::getSurvived() const { return survived; }
std::string Passenger::getEmbarked() const { return embarked; }

void Passenger::setName(const std::string& newName) { name = newName; }
void Passenger::setSex(const std::string& newSex) { sex = newSex; }
void Passenger::setAge(int newAge) { age = newAge; }
void Passenger::setSurvived(bool newSurvived) { survived = newSurvived; }
void Passenger::setEmbarked(const std::string& newEmbarked) { embarked = newEmbarked; }

void Passenger::displayInfo() const {
    std::cout << "Name: " << name << "\nSex: " << sex << "\nAge: " << age
              << "\nSurvived: " << (survived ? "Yes" : "No") << "\nEmbarked: " << embarked << std::endl;
}

bool Passenger::isOlderThan(const Passenger& other) const {
    return this->age > other.age;
}
