//
// Created by Andy on 11/18/2018.
//

#include <iostream>
#include "GeneticAlgorithm.hpp"

void GeneticAlgorithm::run(int iterations, int populationSize, std::vector<City> cities) {
    Population population(populationSize, cities);

    std::cout << "Initial Distance: " << population.getFittest().getDistance() << std::endl;

    for (int i = 0; i < iterations; ++i) {
        population = evolve(population);
    }

    std::cout << "Final Distance: " << population.getFittest().getDistance() << std::endl;
}

Population GeneticAlgorithm::evolve(Population& population) {
    Population newPopulation;

    int eliteOffset = 1;
    newPopulation.addTour(population.getFittest());

    for (int i = eliteOffset; i < population.populationSize(); ++i) {
        Tour t1 = tournament(population);
        Tour t2 = tournament(population);

        Tour child = crossover(t1, t2);

        newPopulation.addTour(child);
    }

    for (int i = eliteOffset; i < newPopulation.populationSize(); ++i) {
        newPopulation.setTour(i, mutate(newPopulation.getTour(i)));
    }

    return newPopulation;
}

Tour GeneticAlgorithm::crossover(Tour p1, Tour p2) {
    Tour child;

    int start = Random::randomInt(0, p1.tourSize());
    int end = Random::randomInt(0, p1.tourSize());

    if (end < start) {
        std::swap(start, end);
    }

    for (int i = start; i < end; ++i) {
        child.addCity(p1.getCity(i));
    }

    for (int i = 0; i < p2.tourSize(); ++i) {
        if (!child.contains(p2.getCity(i))) {
            child.addCity(p2.getCity(i));
        }
    }

    return child;
}

Tour GeneticAlgorithm::mutate(Tour tour) {
    for (int i = 0; i < tour.tourSize(); ++i) {
        if (Random::randomDouble(0, 1) < MUTATION_RATE) {
            int j = Random::randomInt(0, tour.tourSize() - 1);

            City c1 = tour.getCity(i);
            City c2 = tour.getCity(j);

            tour.setCity(j, c1);
            tour.setCity(i, c2);
        }
    }

    return tour;
}

Tour GeneticAlgorithm::tournament(Population population) {
    Population match;

    for (int i = 0; i < POOL_SIZE; ++i) {
        int randomIndex = Random::randomInt(0, population.populationSize() - 1);
        match.addTour(population.getTour(randomIndex));
    }

    Tour fittest = match.getFittest();

    return fittest;
}