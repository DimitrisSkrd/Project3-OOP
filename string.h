#ifndef STRING_H
#define STRING_H
#include <string>
#include "object.cpp"
using namespace std;

class String : public Object
{
private:
    std::string description;
public:
    void destroy(String*);
    int getid();
    std::string getdes();
    int equal(String);
    int length();
    void clear();
    void print();
    char at(int);
    void concat(String);
    void updateAt(int, std::string);
    String* clone();
    String* toString();
    String(std::string, int);
    String(std::string);
    ~String();
}; 

#endif