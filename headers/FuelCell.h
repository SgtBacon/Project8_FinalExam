#include "Pellet.h"
#include <vector>

class FuelCell {
    private:
        int dc;
        int o_size;
    public:
        std::vector<Pellet> rod;
        int get_osize() {
            return o_size;
        }
        //Decay takes in an integer and compares it against a random number to determine whether or not the pellet decays beyond use and leaves the fuel rod
        //Preconditions: integer dc
        //Postconditions: Power value stored in Pellet 
        int decay(int dc) {
            int check = rand() % 19;
            if (check == dc && this->rod.empty() == false) {
                rod.pop_back();
            }
            if (this->rod.size() > 0)
                return rod.at(0).PowerOut();    //Return Power Output
            else
                return 0;
        }
        //Overloaded LessThan operator
        //Fuel Rods with more pellets are considered smaller, so that the cells closer to empty, and causing destruction, are "larger"
        bool operator<(FuelCell fc) {
            if (rod.size() > fc.rod.size())
                return true;
            else
                return false;
        }
        //Overloaded GreaterThan operator
        //Same as LessThan operator
        bool operator>(FuelCell fc) {
            if (rod.size() < fc.rod.size())
                return true;
            else
                return false;
        }
        //Overloaded EqualTo operator
        //Same as LessThan operator
        bool operator=(FuelCell fc) {
            if (rod.size() == fc.rod.size())
                return true;
            else
                return false;
        }
        //No-Arg constructor
        //Initializes a FuelCell object that contains 10 Pellets, which are what generate power
        FuelCell() {
            o_size = 10;
            for (int i = 0; i < 10; i++) {
                rod.push_back(Pellet());
            }
        }
        //Alternate Constructor
        //Initializes a FuelCell object that contains a number of pellets determined by the user, which have a power potential as determined by the user
        FuelCell(int num, int pr) {
            if (num < 0) {
                o_size = 10;
                for (int i = 0; i < 10; i++) {
                    rod.push_back(Pellet(pr));
                }
            }
            else {
                o_size = num;
                for (int i = 0; i < num; i++) {
                    rod.push_back(Pellet(pr));
                }
            }
        }
};