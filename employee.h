#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
//#include "privcomps.cpp"
#include "privatecompartment.cpp"
using namespace std;

class Employee : public Object
{
protected:  
    std::string name;
public:
    //std::string name;
    virtual Object* clone(){return 0;};
    virtual String* toString(){return 0;};
    std::string getname();
    void setname(std::string);
    int equal(Employee);
    Employee();
    virtual ~Employee();    
    virtual void workon(PlaneComponent*){};
    virtual void report(PlaneComponent*){};
};

#endif