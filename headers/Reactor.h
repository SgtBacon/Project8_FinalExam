#include "FuelCell.h"
#include <iostream>
#include <vector>


class Reactor {
    private:
        int countdown = 60;
        double KW;
        int pwr;
        int o_size;
    public:
        std::vector<FuelCell> assembly;

        int get_cd() {
            return countdown;
        }
        //Causes the reactor to explode, calculating blast radius and square mileage of the destruction
        //Pre: int for the cooldown
        //Post: message to console describing the range of the expplosion
        void Explode(int cd) {             //Worst outcome, blast radius in a certain radius based on Power of a Reactor Pellet
            if (cd == 0) {
                double blast = blast_radius();
                std::cout << "Your Reactor exploded. That was loud.\nDays since last accident: 0\nMassive destruction in a " << (double)blast << " mile radius." << std::endl;
                blast = blast_radius() * blast_radius() * 3.14;
                std::cout << "That covers " << (double)blast << " square miles" << std::endl;
            }
        }
        //Calculates the blast radius
        //Pre: None
        //Post: blast radius
        double blast_radius() {
            double radius;
            double pi = 3.14;
            radius = assembly[0].rod[0].PowerOut() / 700;
            radius = radius * o_size;
            return radius;
        }
        //Counts down to reactor explosion
        //Pre: Assembly vector from a Reactor
        //Post: Messages to console telling user the countdown to detonation or that the reactor stabilizes
        void Meltdown(std::vector<FuelCell> asmbly) {
            if (asmbly.empty()) {
                countdown--;
                std::cout << "Counting down: " << countdown << std::endl;
            }
            else {
                countdown = 60;
                std::cout << "Reactor stabilized" << std::endl;
            }
            Explode(get_cd());
        }
        //Adds a new fuelcell to the reactor
        //Pre: FuelCell
        //Post: FuelCell at the end of the vector
        void addCell(FuelCell fc) {
            assembly.push_back(fc);
        }
        //No-arg Constructor
        //Pre: None
        //Post: New reactor object with 5 default fuelcells
        Reactor() {
            o_size = 5;
            assembly = std::vector<FuelCell>(5);
            pwr = 1000;
            for (int i = 0; i < 5; i++) {
                assembly.push_back(FuelCell());
            }
        }
        //Alternate Constructor
        //Pre: int RodCount, int PelletCount, int PowerLevel
        //Post: Reactor object with a number of fuelcells equal to RodCount, a number of pellets in each fuelcell equal to PelletCount, and a power potential per pellet equal to PowerLevel
        Reactor(int rods, int num, int pr) {
            pwr = pr;
            o_size = rods;
            FuelCell fc = FuelCell(num, pr);
            assembly = std::vector<FuelCell>(rods);
            for (int i = 0; i < rods; i++) {
                assembly.push_back(fc);
            }
        }
        //Removes the last cell from the assembly
        //Pre: Reactor to remove from
        //Post: removed fuelcell from vector
        void removeCell(Reactor newReactor){
            for(int i = 0; i < newReactor.assembly[0].get_osize(); i++){
                if(newReactor.assembly[i].rod.empty()){
                    std::vector<Pellet> temp = std::vector<Pellet>(newReactor.assembly[i].rod.size());
                    temp.swap(newReactor.assembly[i].rod);
                    newReactor.assembly[newReactor.assembly.size() - 1].rod.swap(temp); //pushes empty cell to end of assembly vector
                    newReactor.assembly.pop_back(); //pops off empty cell
                    std::cout << "removed an empty cell" << std::endl;
                    break;
                    }
                else {
                    std::cout << "no empty cells" << std::endl;
                    return;
                    }
            }
        }
        //Returns the total power potential in the fuelcell
        //Pre: fuelcell
        //Post: powerpotential returned
    int PowerOutput(int fc){
        int PowerOutput = fc * pwr;
        return PowerOutput;
}

};




