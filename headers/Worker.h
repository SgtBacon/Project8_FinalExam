#ifndef _WORKER_H_
#define _WORKER_H_
#include <iostream>
#include <vector>
using std::vector;
#include "Reactor.h"
using std::string;

class Worker {      //A reactor must have workers to perform any action
private:            
    string name;    //A worker has a name 
    string jobTitle;    //A worker has a jobtitle
public:
    int cd = 900;   //Cooldown timer for Worker to determine when he can perform his duties
    Worker();       //base constructor
    Worker(string n, string jobT);  //base constructor
    string getName();   //getter for Worker's name
    void Remove_FuelCell(Reactor newReactor);   //Called to remove empty fuel cells from with the given Reactor
    void Add_FuelCell(Reactor& newReactor);     //Called to add a new fuel cell to the given Reactor
};

#endif