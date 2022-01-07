#ifndef PRIVCOMPS_H
#define PRIVCOMPS_H
#include <string>
#include "privatecompartment.cpp"
#include "typesofemps.h"
using namespace std;

class Cleaning_Employee;

class EquipmentCompartment : public PrivateCompartment
{
private:  
public:
    void readycheck();
    EquipmentCompartment* clone();
    String* toString();
    EquipmentCompartment();
    ~EquipmentCompartment();    
};

/////////////////////////////////////////////////////////////////////////////////////////////->

class CargoBay : public PrivateCompartment
{
private:  
public:
    EquipmentCompartment inner;
    CargoBay* clone();
    String* toString();
    void readycheck();
    CargoBay();
    ~CargoBay();    
};

#endif