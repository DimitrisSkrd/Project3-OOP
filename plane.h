#ifndef PLANE_H
#define PLANE_H
#include <string>
//#include "typesofemps.cpp"
#include "used.cpp"
using namespace std;

class Plane : public Object
{
private:  
    std::string title;
    int volume;
    int maxnum;
public:
    CargoBay innercb;
    EquipmentCompartment innerec[3];
    PassengerCompartment* innerpc;  
    Plane* clone();
    String* toString();
    std::string gettitle();
    void readycheck();
    int getvolume();
    int getmaxnum();
    int equal(Plane);
    void process(Cleaning_Employee*);
    void process(Security_Employee*);
    void process(Maintenance_Employee*);
    Plane();
    Plane(int);
    ~Plane();    
};

#endif