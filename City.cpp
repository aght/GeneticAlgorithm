//
// Created by Andy Tang on 11/9/2018.
//

#include "City.hpp"

long City::UID = 0;

City::City() : name(std::to_string(++UID)), x(Random::randomInt(MIN_RANGE, MAX_RANGE)),
               y(Random::randomInt(MIN_RANGE, MAX_RANGE)) {}

City::City(double x, double y) : name(std::to_string(++UID)), x(x), y(y) {
    this->x = x > MAX_RANGE ? MAX_RANGE : x < MIN_RANGE ? MIN_RANGE : x;
    this->y = y > MAX_RANGE ? MAX_RANGE : y < MIN_RANGE ? MIN_RANGE : y;
}

City::City(std::string name, double x, double y) : name(name), x(), y() {
    this->x = x > MAX_RANGE ? MAX_RANGE : x < MIN_RANGE ? MIN_RANGE : x;
    this->y = y > MAX_RANGE ? MAX_RANGE : y < MIN_RANGE ? MIN_RANGE : y;
}

City::City(const City &city) {
    this->name = city.name;
    this->x = city.x;
    this->y = city.y;
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

double City::distanceTo(const City &city) const {
    return hypot(this->x - city.x, this->y - city.y);
}

City &City::operator=(City city) {
    std::swap(this->name, city.name);
    std::swap(this->x, city.x);
    std::swap(this->y, city.y);

    return *this;
}