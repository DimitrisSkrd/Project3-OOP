#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "privatecompartment.h"
using namespace std;


PrivateCompartment::PrivateCompartment()
{
    cout<<"PrivateCompartment just created"<<endl;
}

PrivateCompartment::~PrivateCompartment()
{ 
    cout<<"PrivateCompartment to be destroyed"<<endl;
}

void PrivateCompartment::readycheck()
{
    cout<<"PrivateCompartment OK!"<<endl;
}
