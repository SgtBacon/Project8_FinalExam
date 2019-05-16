#include <iostream>
#include "Worker.h"

int main() {
    Worker DiversityHire;
    srand(time(NULL));
    int dc;
    int i = 1;
    int kilowatts;

    // std::cout << "Constructing Nuclear Reactor" << std::endl;
    // Reactor test = Reactor();
    // std::cout << "Reactor built." << std::endl;
    // DiversityHire.Add_FuelCell(test);
    // std::cout << "Reactor contains " << test.assembly.size() << " Fuel Cells." << std::endl;
    // test.assembly.pop_back();
    // std::cout << "Fuel Cell 5 compromised\n" << "Reactor contains " << test.assembly.size() << " Fuel Cells." << std::endl;

    int rodcount;
    int powercount;
    int pelletcount;

    std::cout << "Simulating nuclear reactor\nHow many fuel cells would you like in the reactor?" << std::endl;
    std::cin >> rodcount;
    std::cout << "\nHow much power does each fuel rod produce?" << std::endl;
    std::cin >> powercount;
    std::cout << "\nHow many pellets are in each fuel rod?" << std::endl;
    std::cin >> pelletcount;

    std::cout << "Flag 1" << std::endl;
    Reactor test = Reactor(rodcount, pelletcount, powercount);
    std::cout << "Flag 2" << std::endl;

    //std::cout << "\nFuel Cell 1 contains " << test.assembly.at(0).rod.size() << " Pellets." << std::endl;
    test.assembly.push_back(FuelCell());
    std::cout << "Reactor has " << test.assembly.size() << " fuel cells." << std::endl;
    for (int loop = 0; loop < (test.assembly.at(0).get_osize() * 250) - 1; loop++) {
        //std::cout << "Loop iteration # " << i << std::endl;
        if (test.assembly[0].rod.empty() == true) {
            std::cout << "Your reactor ran out of fuel" << std::endl;
            break;
        }
        test.assembly[0].decay(i, 0);
        i++;
    }
    std::cout << "It took " << i << " calls of decay() to empty Fuel Cell 1.\nThis produced " << (test.assembly.at(0).rod.at(0).PowerOut() * i) / 1000 << " kilowatts.\n" << std::endl;
    // while (!test.assembly.empty()) {
    //     test.assembly.pop_back();
    // }
    DiversityHire.cd = 0;
    if (DiversityHire.cd == 900) {
        std::cout << "Worker is ready" << std::endl;
        DiversityHire.Remove_FuelCell(test);
        DiversityHire.cd = 0;
    }
    else {
        DiversityHire.cd += 1;
        std::cout << "Worker will be ready in " << 900 - DiversityHire.cd << " loop iterations" << std::endl;
    }
    DiversityHire.cd = 900;
    for (int i = 0; i < test.assembly[0].rod.size(); i++) {
        test.assembly[0].rod.pop_back();
    }
    DiversityHire.Remove_FuelCell(test);
    while (!test.assembly.empty()) {
        test.assembly.pop_back();
    }
    std::cout << test.assembly.size() << std::endl;
    for (int h = 0; h < 60; h++) {
        test.Meltdown(test.assembly);
    }

    return 0;
}