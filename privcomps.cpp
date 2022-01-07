#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "privcomps.h"
using namespace std;

class Cleaning_Employee;

EquipmentCompartment::EquipmentCompartment()
{
    cout<<"EquipmentCompartment just created"<<endl;
}

EquipmentCompartment::~EquipmentCompartment()
{ 
    cout<<"EquipmentCompartment to be destroyed"<<endl;
}

void EquipmentCompartment::readycheck()
{
    if (ready==2)
    {
        cout<<"EquipmentCompartment OK!"<<endl;
    }
}

EquipmentCompartment* EquipmentCompartment::clone()
{
    EquipmentCompartment* e1 = new EquipmentCompartment();
    e1->id=id;
    e1->ready=ready;
    Cleaning_Employee* ce;
    return e1; 
}

String* EquipmentCompartment::toString()
{
    std::string str = std::to_string(id);
    str = str + std::to_string(ready);   
    String *s1 = new String(str);
    
    return s1;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////->

CargoBay::CargoBay()
{
    cout<<"CargoBay just created"<<endl;
}

CargoBay::~CargoBay()
{ 
    cout<<"CargoBay to be destroyed"<<endl;
}

void CargoBay::readycheck()
{
    if (ready==3)
    {
        cout<<"CargoBay OK!"<<endl;
    }
}

CargoBay* CargoBay::clone()
{
    CargoBay* c1 = new CargoBay();
    c1->id=id;
    c1->ready=ready;
    c1->inner.id=inner.id;
    c1->inner.ready=inner.ready;
    return c1; 
}

String* CargoBay::toString()
{
    std::string str = std::to_string(id);
    str = str + std::to_string(ready);  
    str = str + std::to_string(inner.id);
    str = str + std::to_string(inner.ready); 
    String *s1 = new String(str);
    return s1;
}