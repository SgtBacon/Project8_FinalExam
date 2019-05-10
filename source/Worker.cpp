#include "Worker.h"
#include "Reactor.h"
Worker::Worker(){
    name = "Captain Price";
    jobTitle = "Vault-Tech Representative";
}
Worker::Worker(string n, string jobT){
    name = n;                         
    jobTitle = jobT;
}
void Worker::Remove_FuelCell(FuelCell FC){      //A worker can remove a fuel cell, taking in the empty fuel cell as it's parameter so it 
                                                //knows which one to remove
}
void Worker::Add_FuelCell(){         //A worker can add a fuel cell, creating one within the function, and then adding it to the vector of 
    //FuelCell NewCell;                //fuel cells within the reactor
    //Reactor.FuelVector.push_back(NewCell);

}