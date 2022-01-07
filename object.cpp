#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "object.h"
using namespace std;

Object::Object()
{
    cout<<"Object just created"<<endl;
    id = rand() % 10000;
}

Object::~Object()
{
    cout<<"Object to be destroyed"<<endl;
}

int Object::getid()
{
    return id;
}

void Object::setid(int i)
{
    id = i;
}

int Object::equal(Object diff)
{
    if (id==diff.id)
    {
        return 1;
    }
    else
    {
        return 0;
    } 
}

int Object::identical(Object& diff)
{
    //Object* check = &diff;
    //cout<<this<<endl;
    //cout<<check<<endl;
    if (this == &diff)
    {
        return 1;
    }
    else
    {
        return 0;
    }   
}