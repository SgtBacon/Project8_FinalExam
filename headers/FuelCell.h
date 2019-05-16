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
        int decay(int dc) {         //Each pellet has a 10% chance to decay, removing it from the rod vector
            int check = rand() % 19;
            std::cout << check << std::endl;
            std::cout << dc << std::endl;
            if (check == dc && this->rod.empty() == false) {
                //std::cout << "Calling pop_back()" << std::endl;
                rod.pop_back();
            }
            //std::cout << "The size of the rod is: " << this->rod.size() << std::endl;
            if (this->rod.size() > 0)
                return rod.at(0).PowerOut();    //Return Power Output
            else
                return 0;
        }
        bool operator<(FuelCell fc) {
            if (rod.size() > fc.rod.size())
                return true;
            else
                return false;
        }
        bool operator>(FuelCell fc) {
            if (rod.size() < fc.rod.size())
                return true;
            else
                return false;
        }
        bool operator=(FuelCell fc) {
            if (rod.size() == fc.rod.size())
                return true;
            else
                return false;
        }
        FuelCell() {
            o_size = 10;
            for (int i = 0; i < 10; i++) {
                rod.push_back(Pellet());
            }
        }
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