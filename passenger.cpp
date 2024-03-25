//
// Created by jack on 25/3/24.
//

#include "passenger.h"

Passenger::Passenger(int id, bool survived, int pclass, const std::string& name, const std::string& sex, int age,
                     int sibSp, int parch, const std::string& ticket, double fare, const std::string& cabin, const std::string& embarked)
        : passengerId(id), survived(survived), pclass(pclass), name(name), sex(sex), age(age),
          sibSp(sibSp), parch(parch), ticket(ticket), fare(fare), cabin(cabin), embarked(embarked) {}

int Passenger::getPassengerId() const { return passengerId; }
bool Passenger::getSurvived() const { return survived; }
int Passenger::getPclass() const { return pclass; }
std::string Passenger::getName() const { return name; }
std::string Passenger::getSex() const { return sex; }
int Passenger::getAge() const { return age; }
int Passenger::getSibSp() const { return sibSp; }
int Passenger::getParch() const { return parch; }
std::string Passenger::getTicket() const { return ticket; }
double Passenger::getFare() const { return fare; }
std::string Passenger::getCabin() const { return cabin; }
std::string Passenger::getEmbarked() const { return embarked; }
