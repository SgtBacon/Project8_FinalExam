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
                std::cout << "Your Reactor exploded. That was loud.\nDays since last accident: 0\nMassive destruction in a " << 0 << " mile radius." << std::endl;
            }
        }
        double blast_radius() {
            double radius;
            double pi = 3.14;
            //
            return radius;
        }
        void Meltdown(std::vector<FuelCell> asmbly) {
            if (asmbly.empty()) {
                countdown--;
            }
            else {
                countdown = 60;
            }
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
            FuelCell fc = FuelCell(num);
            std::cout << "rods: " << rods << std::endl;
            assembly = std::vector<FuelCell>(rods);
            for (int i = 0; i < rods; i++) {
                std::cout << "i: " << i << std::endl;
                assembly.push_back(fc);
            }
            std::cout << "done\n";
        }
        void removeCell(Reactor newReactor){
            for(int i = 0; i < newReactor.assembly.size(); i++){
                if(newReactor.assembly.at(i).rod.empty()){
                    newReactor.assembly.pop_back();
                    break;
                    }
                else {
                    return;
                    }
            }
        }
    int PowerOutput(int fc){
        int PowerOutput = fc * pwr;
}

};




