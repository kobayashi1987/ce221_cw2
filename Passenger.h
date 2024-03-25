//
// Created by jack on 25/3/24.
//

#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>

class Passenger {
public:
    Passenger(int id, bool survived, int pclass, const std::string& name, const std::string& sex, int age,
              int sibSp, int parch, const std::string& ticket, double fare, const std::string& cabin, const std::string& embarked);

    // Getters
    int getPassengerId() const;
    bool getSurvived() const;
    int getPclass() const;
    std::string getName() const;
    std::string getSex() const;
    int getAge() const;
    int getSibSp() const;
    int getParch() const;
    std::string getTicket() const;
    double getFare() const;
    std::string getCabin() const;
    std::string getEmbarked() const;

private:
    int passengerId;
    bool survived;
    int pclass;
    std::string name;
    std::string sex;
    int age;
    int sibSp;
    int parch;
    std::string ticket;
    double fare;
    std::string cabin;
    std::string embarked;
};

#endif // PASSENGER_H
