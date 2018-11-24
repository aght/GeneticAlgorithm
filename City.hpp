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

/**
 * Class representing a city
 */
class City {
private:

    /**
     * Max bounds of the city
     */
    static constexpr double MAX_RANGE = 1000.00;

    /**
     * Min bounds of the city
     */
    static constexpr double MIN_RANGE = 0.00;

    /**
     * Unique ID of the city
     */
    static long UID;

    /**
     * City name
     */
    std::string name;

    /**
     * City x coordinate
     */
    double x;

    /**
     * City y coordinate
     */
    double y;

public:

    /**
     * Default constructor
     */
    City();

    /**
     * Create a city based on a x and y, the name will be a generated UID
     *
     * @param x x coordinate
     * @param y y coordinate
     */
    City(double x, double y);

    /**
     * Creates a named city
     *
     * @param name city name
     * @param x x coordinate
     * @param y y coordinate
     */
    City(std::string name, double x, double y);

    /**
     * Copy constructor
     *
     * @param city city to copy
     */
    City(const City &city);

    /**
     * Returns the name of the city
     *
     * @return name
     */
    std::string getName() const;

    /**
     * Gets the x coordinate of the city
     *
     * @return x
     */
    double getX() const;

    /**
     * Gets the y coordinate of the city
     *
     * @return y
     */
    double getY() const;

    /**
     * Calculates the distance between this city and another city
     * @param city other city
     * @return distance between
     */
    double distanceTo(const City &city) const;

    /**
     * Assignment operator
     * @param city city to copy
     * @return this city
     */
    City &operator=(City city);

    /**
     * Output operator
     * @param os ostream
     * @param city city
     * @return ostream
     */
    friend std::ostream &operator<<(std::ostream &os, const City &city);

    /**
     * Equals operator
     * @param a city a
     * @param b city b
     * @return true if both city names are the same
     */
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
