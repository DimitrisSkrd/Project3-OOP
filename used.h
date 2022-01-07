#include <string>
#include "employee.cpp"
using namespace std;

class Security_Employee;
class Maintenance_Employee;
class Cleaning_Employee;
class EquipmentCompartment;
class CargoBay;
class PassengerCompartment;

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

////////////////////////////////////////////////////////////////////////////////->

class EquipmentCompartment : public PrivateCompartment
{
private:  
public:
    void readycheck();
    int equal(EquipmentCompartment);
    EquipmentCompartment* clone();
    String* toString();
    void process(Security_Employee*);
    void process(Maintenance_Employee*);
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
    int equal(CargoBay);
    void readycheck();
    void process(Cleaning_Employee*);
    void process(Security_Employee*);
    void process(Maintenance_Employee*);
    CargoBay();
    ~CargoBay();    
};

/////////////////////////////////////////////////////////////////////////////////////////////->

class PassengerCompartment : public PlaneComponent
{
private:
    int numin;  
public:
    PassengerCompartment* inner;  
    void readycheck();
    int getnumin();
    int equal(PassengerCompartment);
    void setnumin(int);
    void setid(int);
    void setready(int);
    void process(Cleaning_Employee*);
    void process(Security_Employee*);
    void inside();
    void inside(int);
    PassengerCompartment* clone();
    String* toString();
    PassengerCompartment();
    //PassengerCompartment(int);
    //PassengerCompartment(int,int,int);
    ~PassengerCompartment();    
};