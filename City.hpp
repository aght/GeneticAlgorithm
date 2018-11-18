//
// Created by Andy Tang on 11/9/2018.
//

#ifndef GENETICALGORITHM_CITY_HPP
#define GENETICALGORITHM_CITY_HPP

#include <string>
#include <cmath>
#include <ostream>

class City {
private:
    static constexpr double MAX_RANGE = 1000.00;
    static constexpr double MIN_RANGE = 0.00;

    std::string name;
    double x;
    double y;

public:
    City(std::string name, double x, double y);

    std::string getName() const;

    double getX() const;

    double getY() const;

    double distanceTo(const City &city) const;

    friend std::ostream &operator<<(std::ostream &os, const City &city);
};

inline std::ostream &operator<<(std::ostream &os, const City &city) {
    os << city.name << " [" << city.x << ", " << city.y << "]";

    return os;
}


#endif //GENETICALGORITHM_CITY_HPP
