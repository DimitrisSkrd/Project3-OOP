#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "typesofemps.h"
using namespace std;

Security_Employee::Security_Employee()
{
    cout<<"Security_Employee just created"<<endl;
}

Security_Employee::~Security_Employee()
{
    cout<<"Security_Employee to be destroyed"<<endl;
}

Security_Employee* Security_Employee::clone()
{
    Security_Employee* se1 = new Security_Employee();
    se1->id=id;
    se1->name=name;
    return se1; 
}

String* Security_Employee::toString()
{
    std::string str = std::to_string(id);
    str = str + name;   
    String *s1 = new String(str);
    return s1;
}

void Security_Employee::workon(EquipmentCompartment* ec)
{
    ec->worked();
    this->report(ec);
}

void Security_Employee::report(EquipmentCompartment* ec)
{
    cout<<"Security Employee working an Equiepment Compartment with id: "<< ec->getid()<< endl;
    cout<<"OK"<<endl;
}

void Security_Employee::workon(CargoBay* cb)
{
    cb->worked();
    this->report(cb);
}

void Security_Employee::report(CargoBay* cb)
{
    cout<<"Security Employee working a Cargo Bay with id: "<< cb->getid()<< endl;
    cout<<"OK"<<endl;
}

void Security_Employee::workon(PassengerCompartment* pc)
{
    pc->worked();
    this->report(pc);
}

void Security_Employee::report(PassengerCompartment* pc)
{
    cout<<"Security Employee working a Passenger Compartment with id: "<< pc->getid()<< endl;
    cout<<"OK"<<endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////->

Maintenance_Employee::Maintenance_Employee()
{
    cout<<"Maintenance_Employee just created"<<endl;
}

Maintenance_Employee::~Maintenance_Employee()
{
    cout<<"Maintenance_Employee to be destroyed"<<endl;
}

Maintenance_Employee* Maintenance_Employee::clone()
{
    Maintenance_Employee* me1 = new Maintenance_Employee();
    me1->id=id;
    me1->name=name;
    return me1; 
}

String* Maintenance_Employee::toString()
{
    std::string str = std::to_string(id);
    str = str + name;   
    String *s1 = new String(str);
    return s1;
}

void Maintenance_Employee::workon(EquipmentCompartment* ec)
{
    ec->worked();
    this->report(ec);
}

void Maintenance_Employee::report(EquipmentCompartment* ec)
{
    cout<<"Maintenance Employee working an Equiepment Compartment with id: "<< ec->getid()<< endl;
    cout<<"OK"<<endl;
}

void Maintenance_Employee::workon(CargoBay* cb)
{
    cb->worked();
    this->report(cb);
}

void Maintenance_Employee::report(CargoBay* cb)
{
    cout<<"Maintenance Employee working a Cargo Bay with id: "<< cb->getid()<< endl;
    cout<<"OK"<<endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////->

Cleaning_Employee::Cleaning_Employee()
{
    cout<<"Cleaning_Employee just created"<<endl;
}

Cleaning_Employee::~Cleaning_Employee()
{
    cout<<"Cleaning_Employee to be destroyed"<<endl;
}

Cleaning_Employee* Cleaning_Employee::clone()
{
    Cleaning_Employee* ce1 = new Cleaning_Employee();
    ce1->id=id;
    ce1->name=name;
    return ce1; 
}

String* Cleaning_Employee::toString()
{
    std::string str = std::to_string(id);
    str = str + name;   
    String *s1 = new String(str);
    return s1;
}

void Cleaning_Employee::workon(CargoBay* cb)
{
    cb->worked();
    this->report(cb);
}

void Cleaning_Employee::report(CargoBay* cb)
{
    cout<<"Cleaning Employee working a Cargo Bay with id: "<< cb->getid()<< endl;
    cout<<"OK"<<endl;
}

void Cleaning_Employee::workon(PassengerCompartment* pc)
{
    pc->worked();
    this->report(pc);
}

void Cleaning_Employee::report(PassengerCompartment* pc)
{
    cout<<"Cleaning Employee working a Passenger Compartment with id: "<< pc->getid()<< endl;
    cout<<"OK"<<endl;
}