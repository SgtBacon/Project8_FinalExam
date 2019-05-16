#include "Worker.h"


Worker::Worker(){   //Base constructor
    name = "Captain Price";
    jobTitle = "Vault-Tech Representative";
    cd = 900;
}
Worker::Worker(string n, string jobT){  //base constructor
    name = n;                         
    jobTitle = jobT;
    cd = 900;
}
void Worker::Remove_FuelCell(Reactor newReactor){      //A worker can remove a fuel cell, taking in the reactor as it's parameter so it 
    newReactor.removeCell(newReactor);                                       //knows where to remove the fuel cell from
}
void Worker::Add_FuelCell(Reactor& newReactor){         //A worker can add a fuel cell, creating one within the function, and then adding it to the vector of 
    FuelCell NewCell = FuelCell();                      //of FuelCells within the reactor, passed in through its parameter
    newReactor.addCell(NewCell);                        
    std::cout << "added fuel cell" << std::endl;
}
string Worker::getName(){                               //Getter to return Worker's name
    return name;
}
/*

*/