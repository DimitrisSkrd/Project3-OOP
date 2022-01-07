#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "employee.h"
using namespace std;

Employee::Employee()
{
    cout<<"Employee just created"<<endl;
    name="Jeff";
}

Employee::~Employee()
{
    cout<<"Employee to be destroyed"<<endl;
}

string Employee::getname()
{
    return name;
}

void Employee::setname(string str)
{
    name=str;
}

int Employee::equal(Employee diff)
{
    if ((id==diff.id) && (name==diff.name))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}