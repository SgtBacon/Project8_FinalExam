#include <FuelCell.h>

class Reactor {
    private:
        int countdown = 60;
    public:
        std::vector<FuelCell> assembly; //Vector is public so that the Worker class can modify the contents
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
        Reactor() {
            assembly = std::vector<FuelCell>(5);
            for (int i = 0; i < 5; i++) {
                assembly.at(i) = FuelCell();
            }
        }
        Reactor(int rods, int num, int pwr) {
            for (int i = 0; i < rods; i++) {
                assembly.at(i) = FuelCell(num, pwr);
            }
        }

};