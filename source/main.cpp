#include <iostream>
#include "Worker.h"

int main() {
    Worker Homer;
    srand(time(NULL));
    int dc;
    int i = 1;
    int j = 1;
    int kilowatts;

    int rodcount;
    int powercount;
    int pelletcount;

    std::cout << "Simulating nuclear reactor\nHow many fuel cells would you like in the reactor?" << std::endl;
    std::cin >> rodcount;
    std::cout << "\nHow much power does each fuel rod produce?" << std::endl;
    std::cin >> powercount;
    std::cout << "\nHow many pellets are in each fuel rod?" << std::endl;
    std::cin >> pelletcount;

    Reactor test = Reactor(rodcount, pelletcount, powercount);
    int power = test.assembly[0].rod.at(0).PowerOut();

    test.assembly.push_back(FuelCell());
    while (true) {
        if (test.assembly[0].rod.empty() == true) {
            std::cout << "Your reactor ran out of fuel" << std::endl;
            break;
        }
        else if (test.assembly[0].rod.size() > 0) {
            test.assembly[0].decay(i);
        }
        i++;
        j++;
        i = i % 20;
    }
    kilowatts = (power * j) / 1000;
    std::cout << "The reactor produced " << kilowatts << " kilowatts with one fuel rod" << std::endl;

    Homer.cd = 0;
    if (Homer.cd == 900) {
        std::cout << "Worker is ready" << std::endl;
        Homer.Remove_FuelCell(test);
        Homer.cd = 0;
    }
    else {
        Homer.cd += 1;
        std::cout << "Worker will be ready in " << 900 - Homer.cd << " loop iterations" << std::endl;
    }
    Homer.cd = 900;
    for (int i = 0; i < test.assembly[0].get_osize(); i++) {
        if (test.assembly[0].rod.size() > 0) {
            test.assembly[0].rod.erase(test.assembly[0].rod.begin() + i);
            std::cout << "Pellets in fuel rod: " << test.assembly[0].rod.size() << std::endl;
        }
        else {
            std::cout << "Fuel rod is empty" << std::endl;
            break;
        }
    }

    Homer.Remove_FuelCell(test);
    while (!test.assembly.empty()) {
        test.assembly.pop_back();
    }
    for (int h = 0; h < 60; h++) {
        test.Meltdown(test.assembly);
    }

    return 0;
}