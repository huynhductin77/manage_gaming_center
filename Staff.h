#ifndef STAFF_H
#define STAFF_H
#include "People.h"
#include <iostream>
#include <string>
using namespace std;

class Staff : public People
{
private:
    int salary;
    string shift;
public:
    Staff(string name, string code, string startDay, string shift, int salary);
    ~Staff();
    void display();
    void edit(string name, string code, string startDay, string shift, int salary);
};

Staff::Staff(string name = "none", string code = "none", string startDay = "1/1/1990", string shift = "none", int salary = 0)
: People(name, startDay, code)
{
    this->salary = salary;
    this->shift = shift;
}
Staff::~Staff(){}
void Staff::display()
{
    cout << "STAFF : " << endl;
    cout << "   Name : " << this->name << endl;
    cout << "   Start Day : " << this->startDay << endl;
    cout << "   Shift : " << this->shift << endl;
    cout << "   Salary : " << this->salary << endl;
}
void Staff::edit(string name, string code = "none", string startDay, string shift, int salary)
{
    this->name = name;
    this->startDay = startDay;
    this->shift = shift;
    this->salary = salary;
}

#endif
