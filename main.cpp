#include <iostream>

#include "City.hpp"
#include "GeneticAlgorithm.hpp"

int main() {
    std::vector<City> cities;

    cities.push_back(City{60, 200});
    cities.push_back(City{180, 200});
    cities.push_back(City{80, 180});
    cities.push_back(City{140, 180});
    cities.push_back(City{20, 160});
    cities.push_back(City{100, 160});
    cities.push_back(City{200, 160});
    cities.push_back(City{140, 140});
    cities.push_back(City{40, 120});
    cities.push_back(City{100, 120});
    cities.push_back(City{180, 100});
    cities.push_back(City{60, 80});
    cities.push_back(City{120, 80});
    cities.push_back(City{180, 60});
    cities.push_back(City{20, 40});
    cities.push_back(City{100, 40});
    cities.push_back(City{200, 40});
    cities.push_back(City{20, 20});
    cities.push_back(City{60, 20});
    cities.push_back(City{160, 20});

    GeneticAlgorithm::run(100, 100, cities);

    return 0;
}