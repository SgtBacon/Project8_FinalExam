#ifndef _WORKER_H_
#define _WORKER_H_
#include <iostream>
#include <vector>
using std::vector;
#include "Reactor.h"
using std::string;

class Worker {      //A reactor must have workers to perform any action
private:            
    string name;
    string jobTitle;
    int cd;
public:
    Worker();
    Worker(string n, string jobT);
    string getName();
    void Remove_FuelCell(FuelCell FC, Reactor newReactor);
    void Add_FuelCell(Reactor& newReactor);
    void runCooldown();

};

#endif