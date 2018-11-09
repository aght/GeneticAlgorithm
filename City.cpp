//
// Created by Andy Tang on 11/9/2018.
//

#include "City.hpp"

City::City(std::string name, double x, double y) : name(name), x(x), y(y) {
    if (x > MAX_RANGE) {
        x = MAX_RANGE;
    } else if (x < MIN_RANGE) {
        x = MIN_RANGE;
    }

    if (y > MAX_RANGE) {
        y = MAX_RANGE;
    } else if (y < MIN_RANGE) {
        y = MIN_RANGE;
    }
}

std::string City::getName() const {
    return name;
}

double City::getX() const {
    return x;
}

double City::getY() const {
    return y;
}