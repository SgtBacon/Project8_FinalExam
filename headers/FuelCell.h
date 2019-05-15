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
            if (dc == 1 || dc == 20) {
                rod.pop_back();
                return 0;           //Decayed Pellet produces no Power
            }
            else {
                return rod.at(rod.size() - 1).PowerOut();    //Return Power Output
            }
        }
        operator<(FuelCell fc) {
            if (rod.size() > fc.rod.size())
                return true;
            else
                return false;
        }
        operator>(FuelCell fc) {
            if (rod.size() < fc.rod.size())
                return true;
            else
                return false;
        }
        operator=(FuelCell fc) {
            if (rod.size() == fc.rod.size())
                return true;
            else
                return false;
        }
        FuelCell() {
            o_size = 10;
            rod = std::vector<Pellet>(10);
            for (int i = 0; i < 10; i++) {
                rod.at(i) = Pellet();
            }
        }
        FuelCell(int num, int pwr) {
            if (num < 0) {
                o_size = 10;
                for (int i = 0; i < 10; i++) {
                    rod.at(i) = Pellet(pwr);
                }
            }
            else {
                o_size = num;
                for (int i = 0; i < num; i++) {
                    rod.at(i) = Pellet(pwr);
                }
            }
        }
};