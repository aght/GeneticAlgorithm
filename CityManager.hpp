//
// Created by Andy on 11/18/2018.
//

#ifndef GENETICALGORITHM_CITYMANAGER_HPP
#define GENETICALGORITHM_CITYMANAGER_HPP

#include <vector>

#include "City.hpp"

class CityManager {
private:
    static std::vector<City> cities;

public:
    static void addCity(const City& city);

    static City getCity(int index);

    static std::vector<City>& getCities();
};


#endif //GENETICALGORITHM_CITYMANAGER_HPP
