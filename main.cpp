#include <iostream>
#include "City.hpp"

int main() {
    City a{"Vancouver", 0, 0};
    City b{"Toronto", 10, 0};

    std::cout << a.distanceTo(b);

    return 0;
}