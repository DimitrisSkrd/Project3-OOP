#ifndef PASSENGERCOMPARTMENT_H
#define PASSENGERCOMPARTMENT_H
#include <string>
#include "planecomponent.cpp"
#include "typesofemps.h"

using namespace std;

class Cleaning_Employee;
class Security_Employee;

class PassengerCompartment : public PlaneComponent
{
private:
    int numin;  
public:
    PassengerCompartment* inner;  
    void readycheck();
    int getnumin();
    void setnumin(int);
    void setid(int);
    void setready(int);
    void process(Cleaning_Employee*);
    //void process(Security_Employee*);
    PassengerCompartment* clone();
    String* toString();
    PassengerCompartment();
    PassengerCompartment(int);
    PassengerCompartment(int,int,int);
    ~PassengerCompartment();    
};

#endif