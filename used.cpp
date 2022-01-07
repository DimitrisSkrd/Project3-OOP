#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "used.h"
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

/////////////////////////////////////////////////////////////////////////////->

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
        cout<<"EquipmentCompartment with description: "<<endl;
        String* str=this->toString();
        str->print();   
        cout<<"is OK!"<<endl;
        str->destroy(str);
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

void EquipmentCompartment::process(Security_Employee* se)
{
    se->workon(this);
}

void EquipmentCompartment::process(Maintenance_Employee* me)
{
    me->workon(this);
}

int EquipmentCompartment::equal(EquipmentCompartment diff)
{
    if ((this->getid()==diff.getid()) && ( this->getready()==diff.getready()))
    {
        return 1;
    }
    else
    {
        return 0;
    }
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
        cout<<"CargoBay with description: "<<endl;
        String* str=this->toString();
        str->print();   
        cout<<"is OK!"<<endl;
        str->destroy(str);
    }
    inner.readycheck();
}

CargoBay* CargoBay::clone()
{
    CargoBay* c1 = new CargoBay();
    c1->id=id;
    c1->ready=ready;
    c1->inner.setid(inner.getid());
    c1->inner.setready(inner.getready());
    return c1; 
}

String* CargoBay::toString()
{
    std::string str = std::to_string(id);
    str = str + std::to_string(ready);  
    str = str + std::to_string(inner.getid());
    str = str + std::to_string(inner.getready()); 
    String *s1 = new String(str);
    return s1;
}

void CargoBay::process(Cleaning_Employee* ce)
{
    ce->workon(this); 
}

void CargoBay::process(Security_Employee* se)
{
    se->workon(this);
}

void CargoBay::process(Maintenance_Employee* me)
{
    me->workon(this);
}

int CargoBay::equal(CargoBay diff)
{
    if ((this->getid()==diff.getid()) && ( this->getready()==diff.getready()))
    {
        if ((this->inner.getid()==diff.inner.getid()) && (this->inner.getready()==diff.inner.getready()))
        {
            return 1;
        }
        else
        {
            return 0;
        }
        
    }
    else
    {
        return 0;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////->

PassengerCompartment::PassengerCompartment()
{
    cout<<"PassengerCompartment just created"<<endl;
    //numin = rand() % 2;
    numin=0;
    inner = NULL;
    //if (numin==1)
    //{
    //    inner = new PassengerCompartment(0);
    //}
}

/*PassengerCompartment::PassengerCompartment(int num)
{
    cout<<"PassengerCompartment just created"<<endl;
    numin = num;   
    inner = NULL;
}

PassengerCompartment::PassengerCompartment(int num,int rd,int iden)
{
    cout<<"PassengerCompartment just created"<<endl;

    numin = num;   
    ready=rd;
    id=iden;
    inner = NULL;
}*/

void PassengerCompartment::inside()
{
    numin = rand() % 2;
    if (numin==1)
    {
        inner = new PassengerCompartment();
    }
}

void  PassengerCompartment::inside(int num)
{
    numin=num;
    if (numin==1)
    {
        inner = new PassengerCompartment();
    }
}

PassengerCompartment::~PassengerCompartment()
{

    if (numin==1)
    {
        delete inner;
    }    
    cout<<"PassengerCompartment to be destroyed"<<endl;
}

void PassengerCompartment::readycheck()
{
    if (ready==2)
    {
        cout<<"PassengerCompartment with description: "<<endl;
        String* str=this->toString();
        str->print();   
        cout<<"is OK!"<<endl;
        str->destroy(str);
    }
    if (numin==1)
    {
        inner->readycheck();
    }
}

int PassengerCompartment::getnumin()
{
    return numin;
}

void PassengerCompartment::setnumin(int i)
{
    numin=i;
}

void PassengerCompartment::setid(int i)
{
    id=i;
}

void PassengerCompartment::setready(int i)
{
    ready=i;
}

PassengerCompartment* PassengerCompartment::clone()
{
    //PassengerCompartment* p1 = new PassengerCompartment(numin);
    PassengerCompartment* p1 = new PassengerCompartment();
    p1->inside(numin);
    p1->id=id;
    //p1->numin=numin;
    p1->ready=ready;
    p1->inner=NULL;
    if (numin==1)
    {
        //p1->inner = new PassengerCompartment(0);
        //p1->inner = new PassengerCompartment();
        //p1->inner=inner->clone();
        p1->inner->inside(0);
        p1->inner->ready = inner->ready;
        p1->inner->id = inner->id;
        
    }
    return p1; 
}

String* PassengerCompartment::toString()
{
    std::string str = std::to_string(id);
    str = str + std::to_string(ready);
    str = str + std::to_string(numin);

    if (numin==1)
    {
        str = str + std::to_string(inner->id);
        str = str + std::to_string(inner->ready);
        str = str + std::to_string(inner->numin);
    }
    
    String *s1 = new String(str);
    return s1;
}

void PassengerCompartment::process(Cleaning_Employee* ce)
{
    ce->workon(this); 
}

void PassengerCompartment::process(Security_Employee* se)
{
    se->workon(this); 
}

int PassengerCompartment::equal(PassengerCompartment diff)
{
    if ((this->getid()==diff.getid()) && ( this->getready()==diff.getready()))
    {

        if (this->getnumin()== diff.getnumin())
        {
            if (this->getnumin()==1 && diff.getnumin()==1 )
            {
                cout<<"HILFE"<<endl;
                if ((this->inner->getid()==diff.inner->getid()) && (this->inner->getready()==diff.inner->getready()))
                {
                    cout<<"A"<<endl;
                    return 1;
                    cout<<"A1"<<endl;
                }
                else
                {
                    cout<<"B"<<endl;
                    return 0;
                    cout<<"B1"<<endl;
                }
            }
            else
            {
                cout<<"C"<<endl;
                return 1;
                cout<<"C1"<<endl;
            }
            
        }
        else
        {
            cout<<"D"<<endl;
            return 0;
            cout<<"D1"<<endl;
        }
    }
    else
    {
        cout<<"E"<<endl;
        return 0;
        cout<<"E1"<<endl;
    }
}