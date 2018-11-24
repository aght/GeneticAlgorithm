//
// Created by Andy on 11/18/2018.
//

#include "GeneticAlgorithm.hpp"

void GeneticAlgorithm::run(double factor, int iterations, int populationSize, int numElites, std::vector<City> cities) {
    Population population(populationSize, cities);

    double baseDistance = population.getFittest().getDistance();

    int i = 0;
    double bestDistance = baseDistance;

    while (i < iterations && (1 - (bestDistance / baseDistance)) < factor) {
        population = evolve(population, numElites);

        double distance = population.getFittest().getDistance();

        std::cout << "Iteration: " << (i + 1)
                  << " Distance: " << distance
                  << " Fitness: " << population.getFittest().getFitness()
                  << " Improvement Factor: " << ((1 - (bestDistance / baseDistance)) * 100) << "%"
                  << std::endl;

        if (distance < bestDistance) {
            bestDistance = distance;
        }

        ++i;
    }

    std::cout << std::endl;

    std::cout << "Initial Distance: " << baseDistance << std::endl;
    std::cout << "Final Distance: " << population.getFittest().getDistance() << std::endl;

    std::cout << "Target: " << (factor * 100) << "%"
              << " Final: "  << ((1 - (bestDistance / baseDistance)) * 100) << "%"
              << std::endl;
}

Population GeneticAlgorithm::evolve(Population &population, int numElites) {
    Population newPopulation;

    Population tempPopulation;

    Population nElitePopulation = getNElites(numElites, population);
    for (int i = 0; i < nElitePopulation.populationSize(); ++i) {
        newPopulation.addTour(nElitePopulation.getTour(i));
    }

    for (int i = 0; i < population.populationSize(); ++i) {
        bool hasMatch = false;
        for (int j = 0; j < nElitePopulation.populationSize(); ++j) {
            if (population.getTour(i) == nElitePopulation.getTour(j)) {
                hasMatch = true;
                break;
            }
        }

        if (!hasMatch) {
            tempPopulation.addTour(population.getTour(i));
        }
    }

    for (int i = numElites; i < tempPopulation.populationSize(); ++i) {
        Tour t1 = selection(tempPopulation);
        Tour t2 = selection(tempPopulation);

        Tour child = crossover(t1, t2);

        newPopulation.addTour(child);
    }

    for (int i = numElites; i < newPopulation.populationSize(); ++i) {
        newPopulation.setTour(i, mutate(newPopulation.getTour(i)));
    }

    return newPopulation;
}

Tour GeneticAlgorithm::crossover(const Tour &p1, const Tour &p2) {
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

Tour GeneticAlgorithm::selection(const Population &population) {
    Population match;

    for (int i = 0; i < POOL_SIZE; ++i) {
        int randomIndex = Random::randomInt(0, population.populationSize() - 1);
        match.addTour(population.getTour(randomIndex));
    }

    Tour fittest = match.getFittest();

    return fittest;
}

Population GeneticAlgorithm::getNElites(int n, Population population) {
    Population elitePopulation;

    Population tempPopulation = population;

    int i = 0;
    while (i < n) {
        Tour fittest = tempPopulation.getFittest();
        elitePopulation.addTour(fittest);

        tempPopulation = Population{};
        for (int j = 0; j < population.populationSize(); ++j) {

            bool hasMatch = false;

            for (int k = 0; k < elitePopulation.populationSize(); ++k) {
                if (population.getTour(j) == elitePopulation.getTour((k))) {
                    hasMatch = true;
                    break;
                }
            }

            if (!hasMatch) {
                tempPopulation.addTour(population.getTour(j));
            }
        }

        ++i;
    }

    return elitePopulation;
}