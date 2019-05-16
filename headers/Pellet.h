#include <stdlib.h>
#include <time.h>

class Pellet {
    private:
        int Power;  //Measured in Watt. Reactor produces Kilowatt/Hours = (Watts * Hours)/1000
                    //Also used to determine size of reactor explosion
    public:
        int PowerOut() {    //Getter to return the Power within each Pellet
            return Power;
        }
        Pellet() {  //base constructor
            Power = 1000;   
        }
        Pellet(int pwr) { //base constructor
            Power = pwr;
        }
};