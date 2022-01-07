#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "plane.h"
using namespace std;

Plane::Plane()
{

    //ready=0;
    volume=rand() % 100 + 100;
    cout<<volume<<endl;
    int each = rand() % 10 + 30;
    cout<<each<<endl;

    maxnum=volume/each;

    if (volume%each!=0)
    {
        maxnum++;
    }

    innerpc = new PassengerCompartment[maxnum];

    for (int i=0; i<maxnum; i++)
    {
        innerpc[i].inside();
    }

    cout<<"Plane just created"<<endl;
}

Plane::Plane(int num)
{

    //ready=0;
    maxnum=num;

    //for (int i = 0; i < maxnum; i++)
    //{
    //    innerpc = new PassengerCompartment(0);
    //}
    
    innerpc = new PassengerCompartment[maxnum];

    cout<<"Plane just created"<<endl;
}

Plane::~Plane()
{
    cout<<"Plane to be destroyed"<<endl;
}

string Plane::gettitle()
{
    return title;
}

Plane* Plane::clone()
{
    Plane* pl1 = new Plane(maxnum);
    pl1->volume=volume;
    pl1->id=id;
    pl1->title=title;
    pl1->innercb.setid(innercb.getid());
    pl1->innercb.setready(innercb.getready());
    pl1->innercb.inner.setid(innercb.inner.getid());
    pl1->innercb.inner.setready(innercb.inner.getready());
    for (int i = 0; i < 3; i++)
    {
        pl1->innerec[i].setid(innerec[i].getid());
        pl1->innerec[i].setready(innerec[i].getready());
    }

    for (int i = 0; i < maxnum; i++)
    {
        pl1->innerpc[i].setid(innerpc[i].getid());
        pl1->innerpc[i].setready(innerpc[i].getready());
        //pl1->innerpc[i].setnumin(innerpc[i].getnumin());
        pl1->innerpc[i].inside(innerpc[i].getnumin()); 
        if (innerpc[i].getnumin()==1)
        {
            //pl1->innerpc[i].inner = new PassengerCompartment(0,innerpc[i].getready(),innerpc[i].getid());
            //pl1->innerpc[i].inner = new PassengerCompartment();
            //p1->inner=inner->clone();
            pl1->innerpc[i].inner->inside(0);
            pl1->innerpc[i].inner->setid(innerpc[i].inner->getid());
            pl1->innerpc[i].inner->setready(innerpc[i].inner->getready());
            cout<<"A"<<endl;
            cout<<pl1->innerpc[i].inner->getid()<<endl;
            cout<<"B"<<endl;
            cout<<pl1->innerpc[i].inner->getready()<<endl;;
            cout<<"C"<<endl;
            cout<<pl1->innerpc[i].inner->getnumin()<<endl;
        }
    }
    
    return pl1; 
}

String* Plane::toString()
{
    std::string str = std::to_string(id);
    str = str + std::to_string(volume);
    str = str + title;   
    String *s1 = new String(str);

    String *s2 = innercb.toString();
    s1->concat(*s2);
    s2->destroy(s2);
    
    for (int i = 0; i < 3; i++)
    {
        String* s3 = innerec[i].toString();
        s1->concat(*s3);
        s3->destroy(s3);
    }
    
    for (int i = 0; i < maxnum; i++)
    {

        String* s4 = innerpc[i].toString();
        s1->concat(*s4);
        s4->destroy(s4);
    }
    //s2->destroy(s2);
    return s1;
}

void Plane::process(Cleaning_Employee* ce)
{
    innercb.process(ce);

    for (int i = 0; i < maxnum; i++)
    {
        innerpc[i].process(ce);
        if (innerpc[i].getnumin()==1)
        {
            innerpc[i].inner->process(ce);
        }
        
    } 
}

void Plane::process(Security_Employee* se)
{
    innercb.process(se);
    innercb.inner.process(se);

    for (int i = 0; i < maxnum; i++)
    {
        innerpc[i].process(se);
        if (innerpc[i].getnumin()==1)
        {
            innerpc[i].inner->process(se);
        }
    } 

    for (int i = 0; i < 3; i++)
    {
        innerec[i].process(se);
    }

}

void Plane::process(Maintenance_Employee* me)
{

    innercb.process(me);
    innercb.inner.process(me);

    for (int i = 0; i < 3; i++)
    {
        innerec[i].process(me);
    }
}

int Plane::getmaxnum()
{
    return maxnum;
}

int Plane::getvolume()
{
    return volume;
}

void Plane::readycheck()
{

    int check=1;

    if (innercb.getready()!=3)
    {
        check=0;
    }

    if (innercb.inner.getready()!=2)
    {
        check=0;
    }
        

    for (int i = 0; i < 3; i++)
    {
        if (innerec[i].getready()!=2)
        {
            check=0;
        }
        
    }

    for (int i = 0; i < maxnum; i++)
    {
        if (innerpc[i].getready()!=2)
        {
            check=0;
        }
        if (innerpc[i].getnumin()==1)
        {
            if (innerpc[i].inner->getready()!=2)
            {
                check=0;
            }
        }
    }

    if (check==1)
    {
        cout<<"Plane is ready!"<<endl;
    }
    else
    {
        cout<<"Plane not ready yet"<<endl;
    }
    
}

int Plane::equal(Plane diff)
{
    cout<<"IN HERE"<<endl;
    String* s1 = this->toString();
    String* s2 = diff.toString();

    cout<<s1->getdes()<<endl;
    cout<<s2->getdes()<<endl;

    if ( s1->getdes() == s2->getdes() )
    {   
        s1->destroy(s1);
        s2->destroy(s2);
        return 1;
    }
    else
    {
        s1->destroy(s1);
        s2->destroy(s2);
        cout<<"OPA"<<endl;
        return 0;
    }


    //return 1;
}