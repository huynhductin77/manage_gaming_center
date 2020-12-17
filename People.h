#ifndef PEOPLE_H
#define PEOPLE_H
#include <string>
using namespace std;

class People
{
protected:
    string name, startDay, code;
public:
    People(string name, string startDay, string code);
    ~People();
    virtual void display();
    virtual void edit();
};

People::People(string name = "none", string startDay = "none", string code = "none")
{
    this->name = name;
    this->startDay = startDay;
    this->code = code;
}
People::~People(){}
void People::display(){return;}
void People::edit(){return;}

#endif

