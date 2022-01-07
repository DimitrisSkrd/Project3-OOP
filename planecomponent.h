#ifndef PLANECOMPONENT_H
#define PLANECOMPONENT_H
#include <string>
#include "string.cpp"
using namespace std;

class Employee;

class PlaneComponent : public Object
{
protected:
    int ready;
public:
    //int ready;
    virtual void readycheck(){};
    void worked();
    virtual void process(Employee*){};
    int getready();
    void setready(int);
    virtual String* toString(){return 0;};
    virtual Object* clone(){return 0;};
    PlaneComponent();
    virtual ~PlaneComponent();    
}; 

#endif