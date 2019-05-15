#include <iostream>
#include "Worker.h"

int main() {
    Worker Jay;
    srand(time(NULL));
    int dc;
    int i;

    std::cout << "Constructing Nuclear Reactor" << std::endl;
    Reactor test = Reactor();
    std::cout << "Reactor built." << std::endl;
    Jay.Add_FuelCell(test);
    std::cout << "Reactor contains " << test.assembly.size() << " Fuel Cells." << std::endl;
    test.assembly.pop_back();
    std::cout << "Fuel Cell 5 compromised\n" << "Reactor contains " << test.assembly.size() << " Fuel Cells." << std::endl;

    std::cout << "\nFuel Cell 1 contains " << test.assembly.at(0).rod.size() << " Pellets." << std::endl;
    for (i = 0; test.assembly.at(0).rod.empty() != true; i++) {
        dc = rand() % 20 + 1;
        if (i < 5) {
            test.assembly.at(i).decay(dc);
            std::cout << dc << std::endl;
        }
        else
            break;
    }
    std::cout << "It took " << i << " calls of decay() to empty Fuel Cell 1.\nThis produced " << 45 * i << " watts.\n" << std::endl;
    while (!test.assembly.empty()) {
        test.assembly.pop_back();
    }
    std::cout << test.assembly.size() << std::endl;
    for (int h = 0; h < 60; h++) {
        test.Meltdown(test.assembly);
    }

    return 0;
}