cmake_minimum_required(VERSION 3.27)
project(assignment02)

set(CMAKE_CXX_STANDARD 17)

add_executable(assignment02 main.cpp
        Passenger.h
        passenger.cpp
        selectPassengersByAgeAndSurvival.h
        selectPassengersByAgeAndSurvival.cpp
        searchPassengerByNameWithCaseOption.h
        searchPassengerByNameWithCaseOption.cpp
        displaySurvivalByGenderAndAge.h
        displaySurvivalByGenderAndAge.cpp
        displaySampleData.h
        displaySampleData.cpp
        showPassengersByEmbarkedType.h
        showPassengersByEmbarkedType.cpp
        displaySurvivalStatistics.h
        displaySurvivalStatistics.cpp
        searchPassengerByName.h
        searchPassengerByName.cpp
        selectPassengersByAgeRange.h
        selectPassengersByAgeRange.cpp
        loadPassengers.h
        loadPassengers.cpp)
