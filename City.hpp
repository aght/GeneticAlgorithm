//
// Created by Andy Tang on 11/9/2018.
//

#ifndef GENETICALGORITHM_CITY_HPP
#define GENETICALGORITHM_CITY_HPP

#include <string>
#include <cmath>
#include <ostream>
#include <random>

#include "Random.hpp"

class City {
private:
    static constexpr double MAX_RANGE = 1000.00;
    static constexpr double MIN_RANGE = 0.00;

    static long UID;

    std::string name;
    double x;
    double y;

public:
    City();

    City(double x, double y);

    City(std::string name, double x, double y);

    City(const City &city);

    std::string getName() const;

    double getX() const;

    double getY() const;

    double distanceTo(const City &city) const;

    City &operator=(City city);

    friend std::ostream &operator<<(std::ostream &os, const City &city);

    friend bool operator==(const City &a, const City &b);
};

inline std::ostream &operator<<(std::ostream &os, const City &city) {
    os << "Name: " << city.name << " Locaiton: [" << city.x << ", " << city.y << "]";

    return os;
}

inline bool operator==(const City &a, const City &b) {
    return a.name == b.name;
}


#endif //GENETICALGORITHM_CITY_HPP
