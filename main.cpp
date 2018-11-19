#include <iostream>

#include "City.hpp"
#include "Tour.hpp"

int main() {
    std::vector<City> cities;

    for (int i = 0; i < 10; i++) {
        cities.push_back(City::generateRandomCity());
    }

    Tour tour = Tour::generateRandomTour(cities);

    std::cout << tour << std::endl;

    std::cout << tour.getDistance();

    return 0;
}