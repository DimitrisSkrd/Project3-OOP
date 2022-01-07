#ifndef OBJECT_H
#define OBJECT_H
#include <string>
#include "string.h"
using namespace std;

class String;

class Object
{
protected:
    int id;
public:
    //int id;
    void setid(int);
    int getid();
    virtual int equal(Object);
    int identical(Object&);
    virtual String* toString(){return 0;};
    virtual Object* clone(){return 0;};
    Object();
    virtual ~Object();
};

#endif