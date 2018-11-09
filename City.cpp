//
// Created by Andy Tang on 11/9/2018.
//

#include "City.hpp"

City::City(std::string name, double x, double y) : name(name), x(), y() {
    x = x > MAX_RANGE ? MAX_RANGE : x < MIN_RANGE ? MIN_RANGE : x;
    y = y > MAX_RANGE ? MAX_RANGE : y < MIN_RANGE ? MIN_RANGE : y;
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