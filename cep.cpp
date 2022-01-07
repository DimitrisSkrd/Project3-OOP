#include <iostream>
#include <stdlib.h>
#include <string>
#include <cmath>
#include <cfloat>
#include "plane.cpp"
using namespace std;

void copy_encrypt_and_print(Object &obj1)
{
    Object* obj2 = obj1.clone();
    if (obj1.equal(*obj2))
    {
        cout<<"Objects equal"<<endl;
    }
    else
    {
        cout<<"Objects not equal"<<endl;
    }

    if (obj1.identical(*obj2))
    {
        cout<<"Objects identical"<<endl;
    }
    else
    {
        cout<<"Objects not identical"<<endl;
    }

    String* s1 = obj1.toString();
    String* s2 = obj2->toString();

    s1->print();
    s2->print();

    for(int i=0; i<10; i++)
    {
        int p = rand() % s2->length() + 1;
        int c = rand() % 10;
        string str = std::to_string(c);
        s1->updateAt(p,str);
    }

    s1->print();
    s2->print();

    s1->concat(*s2);

    cout<<"length: "<<s1->length()<<endl;

    if ((s1->length()%2)==0)
    {
        cout<<s1->at(s1->length()/2)<<s1->at((s1->length()/2)+1)<<endl;
    }
    else
    {
        cout<<s1->at((s1->length()/2)+1)<<endl;
    }
    
    
    s1->clear();

    cout<<"length: "<<s1->length()<<endl;

    s1->destroy(s1);
    s2->destroy(s2);

    delete obj2;
}