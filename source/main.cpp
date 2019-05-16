#include <iostream>
#include "Worker.h"

int main() {
    Worker DiversityHire;
    srand(time(NULL));
    int dc;
    int i = 1;
    int kilowatts;

    std::cout << "Constructing Nuclear Reactor" << std::endl;
    Reactor test = Reactor();
    std::cout << "Reactor built." << std::endl;
    DiversityHire.Add_FuelCell(test);
    std::cout << "Reactor contains " << test.assembly.size() << " Fuel Cells." << std::endl;
    test.assembly.pop_back();
    std::cout << "Fuel Cell 5 compromised\n" << "Reactor contains " << test.assembly.size() << " Fuel Cells." << std::endl;

    std::cout << "\nFuel Cell 1 contains " << test.assembly.at(0).rod.size() << " Pellets." << std::endl;
    test.assembly.push_back(FuelCell());
    std::cout << "Reactor has " << test.assembly.size() << " fuel cells." << std::endl;
    do {
        std::cout << "Loop iteration # " << i << std::endl;
        if (test.assembly.at(0).rod.empty() == true)
            std::cout << "Your reactor ran out of fuel" << std::endl;
        test.assembly.at(0).decay(i);
        i++;
    } while (test.assembly.at(0).rod.empty() == false);
    std::cout << "It took " << i << " calls of decay() to empty Fuel Cell 1.\nThis produced " << (45 * i) / 1000 << " kilowatts.\n" << std::endl;
    while (!test.assembly.empty()) {
        test.assembly.pop_back();
    }
    std::cout << test.assembly.size() << std::endl;
    for (int h = 0; h < 60; h++) {
        test.Meltdown(test.assembly);
    }

    return 0;
}