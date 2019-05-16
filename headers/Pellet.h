#include <stdlib.h>
#include <time.h>

class Pellet {
    private:
        int Power;  //Measured in Watt. Reactor produces Kilowatt/Hours = (Watts * Hours)/1000
                    //Also used to determine size of reactor explosion
    public:
        int PowerOut() {
            return Power;
        }
        Pellet() {
            Power = 1000;
        }
        Pellet(int pwr) {
            if (pwr < 0) {
                Power = 1000;
            }
            Power = pwr;
        }
};