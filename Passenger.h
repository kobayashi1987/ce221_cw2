//
// Created by jack on 25/3/24.
//

#ifndef _PASSENGER_H_
#define _PASSENGER_H_

#include <string>

class Passenger {
public:
    Passenger(std::string name, std::string sex, int age, bool survived, std::string embarked);

    std::string getName() const;
    std::string getSex() const;
    int getAge() const;
    bool getSurvived() const;
    std::string getEmbarked() const;

    void setName(const std::string& newName);
    void setSex(const std::string& newSex);
    void setAge(int newAge);
    void setSurvived(bool newSurvived);
    void setEmbarked(const std::string& newEmbarked);

    void displayInfo() const;
    bool isOlderThan(const Passenger& other) const;

private:
    std::string name;
    std::string sex;
    int age;
    bool survived;
    std::string embarked;
};

#endif // _PASSENGER_H_
