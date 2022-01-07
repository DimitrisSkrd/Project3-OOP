#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "planecomponent.h"
using namespace std;

PlaneComponent::PlaneComponent()
{
    cout<<"PlaneComponent just created"<<endl;
    ready=0;
}

PlaneComponent::~PlaneComponent()
{
    cout<<"PlaneComponent to be destroyed"<<endl;
}

int PlaneComponent::getready()
{
    return ready;
}

void PlaneComponent::setready(int i)
{
    ready=i;
}

void PlaneComponent::worked()
{
    ready++;
}