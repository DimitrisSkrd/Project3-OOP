#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "string.h"
using namespace std;

String::String(string des,int num)
{
    cout<<"String just created"<<endl;
    description=des;
    id=num;
}

String::String(string des)
{
    cout<<"String just created"<<endl;
    description=des;
}

String::~String()
{
    cout<<"String to be destroyed"<<endl;
}

int String::getid()
{
    return id;
}

string String::getdes()
{
    cout<<"lel"<<endl;
    return description;
}

int String::length()
{
    return description.length();
}

void String::clear()
{
    description.clear();
}

void String::print()
{
    cout<<description<<endl;
}

char String::at(int pos)
{
    return description.at(pos-1);
}

void String::concat(String added)
{
    description = description + added.description;
}

void String::updateAt(int pos, string change)
{
    description.replace(pos-1,1,change);
}

String* String::clone()
{
    return new String(description,id);
}

String* String::toString()
{
    String *s1 = new String(description);
    std::string str = std::to_string(id);
    s1->description = s1->description + str;
    return s1;
}

int String::equal(String diff)
{
    if ((id==diff.id) && (description==diff.description))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void String::destroy(String* str)
{
    delete str;
}