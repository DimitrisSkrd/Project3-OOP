#ifndef TYPESOFEMPS_H
#define TYPESOFEMPS_H
#include <string>
#include "employee.cpp"
using namespace std;

class Security_Employee : public Employee
{
private:  
public:
    Security_Employee* clone();
    String* toString();
    Security_Employee();
    ~Security_Employee(); 
    void workon(EquipmentCompartment*);
    void report(EquipmentCompartment*);
    void workon(CargoBay*);
    void report(CargoBay*);
    void workon(PassengerCompartment*);
    void report(PassengerCompartment*);   
};

////////////////////////////////////////////////////////////////////////////////->

class Maintenance_Employee : public Employee
{
private:  
public:
    Maintenance_Employee* clone();
    String* toString();
    Maintenance_Employee();
    ~Maintenance_Employee(); 
    void workon(EquipmentCompartment*);
    void report(EquipmentCompartment*);
    void workon(CargoBay*);
    void report(CargoBay*);   
};

////////////////////////////////////////////////////////////////////////////////->

class Cleaning_Employee : public Employee
{
private:  
public:
    Cleaning_Employee* clone();
    String* toString();
    Cleaning_Employee();
    ~Cleaning_Employee();    
    void workon(CargoBay*);
    void report(CargoBay*);
    void workon(PassengerCompartment*);
    void report(PassengerCompartment*);
};
#endif