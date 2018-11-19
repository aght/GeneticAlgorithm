//
// Created by Andy on 11/18/2018.
//

#include <iostream>
#include "GeneticAlgorithm.hpp"

void GeneticAlgorithm::run(int iterations, int populationSize, std::vector<City> cities) {
    Population population(populationSize, cities);
    std::cout << "Initial Distance: " <<  population.getFittest().getDistance() << std::endl;

    for (int i = 0; i < iterations; ++i) {
        population = evolve(population);
    }

    std::cout << "Evolved Distance: " <<  population.getFittest().getDistance() << std::endl;
}

Population GeneticAlgorithm::evolve(Population population) {

}

Tour GeneticAlgorithm::crossover(Tour p1, Tour p2) {
    Tour child;

    int start = Random::randomInt(0, p1.tourSize());
    int end = Random::randomInt(0, p1.tourSize());

}

void GeneticAlgorithm::mutate(Tour &tour) {
    for (int i = 0; i < tour.tourSize(); ++i) {
        if (Random::randomDouble(0, 1) < MUTATION_RATE) {
            int j = Random::randomInt(0, tour.tourSize());

            City c1 = tour.getCity(i);
            City c2 = tour.getCity(j);

            tour.setCity(j, c1);
            tour.setCity(i, c2);
        }
    }
}

Tour GeneticAlgorithm::selection(Population population) {
    Population selection(POOL_SIZE);

    for (int i = 0; i < POOL_SIZE; ++i) {
        int index = Random::randomInt(0, population.getPopulationSize());

        selection.setTour(i, population.getTour(index));
    }

    return selection.getFittest();
}