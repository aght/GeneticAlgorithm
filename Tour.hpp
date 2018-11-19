//
// Created by Andy on 11/18/2018.
//

#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP

#include <iostream>
#include <vector>
#include <algorithm>

#include "City.hpp"
#include "Random.hpp"

class Tour {
private:
    static constexpr int SHUFFLE_ITERATIONS = 64;

    std::vector<City> cities;
    double fitness;
    double distance;
    int size;

public:
    Tour();

    Tour(const std::vector<City> &cities);

    Tour(const Tour &t);

    double getFitness();

    double getDistance();

    City getCity(int index) const;

    void setCity(int index, const City &city);

    void addCity(const City &city);

    int tourSize() const;

    bool contains(const City &city);

    Tour &operator=(Tour other);

    friend std::ostream& operator<<(std::ostream& os, const Tour& tour);
};

inline std::ostream& operator<<(std::ostream& os, const Tour& tour) {
    for (City city : tour.cities) {
        os << city << std::endl;
    }

    return os;
}


#endif //GENETICALGORITHM_TOUR_HPP
