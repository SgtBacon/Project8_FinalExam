#include "FuelCell.h"
#include <iostream>
#include <vector>


class Reactor {
    private:
        int countdown = 60;
        double KW;
        int pwr;
    public:
        std::vector<FuelCell> assembly;
        // std::vector<FuelCell> getAssembly() {
        //     return assembly;
        // }

        int get_cd() {
            return countdown;
        }
        void Explode(int cd) {             //Worst outcome, blast radius in a certain radius based on Power of a Reactor Pellet
            if (cd == 0) {
                double blast = blast_radius();
                std::cout << "Your Reactor exploded. That was loud.\nDays since last accident: 0\nMassive destruction in a " << blast << " mile radius." << std::endl;
                blast = blast * blast * 3.14;
                std::cout << "That covers " << blast << " square miles" << std::endl;
            }
        }
        double blast_radius() {
            double radius;
            double pi = 3.14;
            std::cout << "Radius calculation 1" << std::endl;
            radius = assembly[0].rod[0].PowerOut();
            std::cout << "Radius 1 = " << radius << "\nRadius calculation 2" << std::endl;
            radius = radius * assembly.size();
            std::cout << "Radius 2 = " << radius << std::endl;
            return radius;
        }
        void Meltdown(std::vector<FuelCell> asmbly) {
            if (asmbly.empty()) {
                countdown--;
                std::cout << "Counting down: " << countdown << std::endl;
            }
            else {
                countdown = 60;
                std::cout << "Reactor stabilized" << std::endl;
            }
            std::cout << "Calling explode()" << std::endl;
            Explode(get_cd());
        }
        void addCell(FuelCell fc) {
            assembly.push_back(fc);
        }
        Reactor() {
            assembly = std::vector<FuelCell>(5);
            pwr = 1000;
            for (int i = 0; i < 5; i++) {
                assembly.push_back(FuelCell());
            }
        }
        Reactor(int rods, int num, int pr) {
            pwr = pr;
            std::cout << "initializing fuel cell" << std::endl;
            FuelCell fc = FuelCell(num, pr);
            std::cout << "rods: " << rods << std::endl;
            assembly = std::vector<FuelCell>(rods);
            for (int i = 0; i < rods; i++) {
                std::cout << "i: " << i << std::endl;
                assembly.push_back(fc);
            }
            std::cout << "done\n";
        }
        void removeCell(Reactor newReactor){
            for(int i = 0; i < newReactor.assembly[0].get_osize(); i++){
                std::cout << "Entered loop" << std::endl;
                if(newReactor.assembly[i].rod.empty()){
                    //newReactor.assembly.erase(assembly.begin() + i);
                    std::vector<Pellet> temp = std::vector<Pellet>(newReactor.assembly[i].rod.size());
                    temp.swap(newReactor.assembly[i].rod);
                    std::cout << "removed an empty cell" << std::endl;
                    break;
                    }
                else {
                    std::cout << "no empty cells" << std::endl;
                    return;
                    }
            }
        }
    int PowerOutput(int fc){
        int PowerOutput = fc * pwr;
}

};




