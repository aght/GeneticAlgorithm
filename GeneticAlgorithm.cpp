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
    Population newPopulation(population.getPopulationSize());

    int eliteOffset = 1;
    // Elite is the first one
    newPopulation.setTour(0, population.getFittest());

    for (int i = eliteOffset; i < newPopulation.getPopulationSize(); ++i) {
        Tour p1 = selection(population);
        Tour p2 = selection(population);

        Tour child = crossover(p1, p1);

        newPopulation.setTour(i, child);
    }

    for (int i = eliteOffset; i < newPopulation.getPopulationSize(); ++i) {
        mutate(newPopulation.getTour(i));
    }

    return newPopulation;
}

Tour GeneticAlgorithm::crossover(Tour p1, Tour p2) {
    Tour child(p1.tourSize());

    int start = Random::randomInt(0, p1.tourSize());
    int end = Random::randomInt(0, p1.tourSize());

    if (start < end) {
        std::swap(start, end);
    }

    std::vector<int> usedIndices;

    for (int i = start; i < end; ++i) {
        child.setCity(i, p1.getCity(i));
        usedIndices.push_back(i);
    }

    for (int i = 0; i < p2.tourSize(); ++i) {
        if (!child.contains(p2.getCity(i))) {
            for (int j = 0; j < child.tourCapacity(); ++j) {
                if (std::find(usedIndices.begin(), usedIndices.end(), j) == usedIndices.end()) {
                    child.setCity(j, p2.getCity(i));
                    break;
                }
            }
        }
    }

    return child;
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