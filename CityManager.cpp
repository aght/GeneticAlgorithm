//
// Created by Andy on 11/18/2018.
//

#include "CityManager.hpp"

void CityManager::addCity(const City &city) {
    cities.push_back(city);
}

City CityManager::getCity(int index) {
    return cities[index];
}
std::vector<City>& CityManager::getCities() {
    return cities;
}