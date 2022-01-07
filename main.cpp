#include <iostream>
#include <stdlib.h>
#include <string>
#include <cmath>
#include <cfloat>
#include "cep.cpp"
using namespace std;

int main() //main function of the program
{
    srand (time(NULL)); //srand for the rand functions used in the program
    

    Plane pl1 = Plane();

    pl1.readycheck();

    Maintenance_Employee me = Maintenance_Employee();
    Security_Employee se = Security_Employee();
    Cleaning_Employee ce = Cleaning_Employee();

    pl1.process(&me);
    pl1.process(&ce);
    pl1.process(&se);

    pl1.innercb.readycheck();


    for (int i = 0; i < 3; i++)
    {
        pl1.innerec[i].readycheck();
    }

    for (int i = 0; i < pl1.getmaxnum(); i++)
    {
        pl1.innerpc[i].readycheck();
    }

    pl1.readycheck(); 


    cout<<"PHASE TWO: FIGHT"<<endl;

    copy_encrypt_and_print(pl1);

    delete[] pl1.innerpc;
    return 0;
}