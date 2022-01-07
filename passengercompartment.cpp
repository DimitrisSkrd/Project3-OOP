#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "passengercompartment.h"
using namespace std;



PassengerCompartment::PassengerCompartment()
{
    cout<<"PassengerCompartment just created"<<endl;
    numin = rand() % 2;
    if (numin==1)
    {
        inner = new PassengerCompartment(0);
    }
}

PassengerCompartment::PassengerCompartment(int num)
{
    cout<<"PassengerCompartment just created"<<endl;
    numin = num;   
     
}

PassengerCompartment::PassengerCompartment(int num,int rd,int iden)
{
    cout<<"PassengerCompartment just created"<<endl;

    numin = num;   
    ready=rd;
    id=iden;
}

PassengerCompartment::~PassengerCompartment()
{

    if (numin!=0)
    {
        delete inner;
    }    
    cout<<"PassengerCompartment to be destroyed"<<endl;
}

void PassengerCompartment::readycheck()
{
    if (ready==2)
    {
        cout<<"PassengerCompartment OK!"<<endl;   
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
    PassengerCompartment* p1 = new PassengerCompartment();
    p1->id=id;
    p1->numin=numin;
    p1->ready=ready;
    if (numin==1)
    {
        p1->inner = new PassengerCompartment[1];
        //p1->inner=inner->clone();
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

