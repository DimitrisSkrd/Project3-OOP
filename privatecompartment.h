#ifndef PRIVETCOMPARTMENT_H
#define PRIVETCOMPARTMENT_H
#include <string>
//#include "passengercompartment.cpp"
#include "planecomponent.cpp"
using namespace std;

class PrivateCompartment : public PlaneComponent
{
private:  
public:
    virtual String* toString(){return 0;};
    virtual Object* clone(){return 0;};
    virtual void readycheck();
    virtual void process(Employee*){};
    PrivateCompartment();
    virtual ~PrivateCompartment();    
};

#endif 