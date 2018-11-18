#include <iostream>
#include "City.hpp"

int main() {
    City a{"Vancouver", 0, 0};
    City b{"Toronto", 10, 0};

    std::cout << a.distanceTo(b) << std::endl;

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    return 0;
}