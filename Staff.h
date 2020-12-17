#ifndef STAFF_H
#define STAFF_H
#include "People.h"
#include <iostream>
#include <string>
using namespace std;

class Staff : public People
{
private:
    long salary;
    string shift;
public:
    Staff(string name, string code, string startDay, string shift, long salary);
    Staff(Staff* st);
    ~Staff();
    void display();
    void edit(string name, string code, string startDay, string shift, long salary);
    void input();
};

Staff::Staff(string name = "none", string code = "none", string startDay = "1/1/1990", string shift = "none", long salary = 0)
: People(name, startDay, code)
{
    this->salary = salary;
    this->shift = shift;
}
Staff::Staff(Staff* st)
{
    this->code = st->code;
    this->name = st->name;
    this->salary = st->salary;
    this->shift = st->shift;
    this->startDay = st->startDay;
}
Staff::~Staff(){}
void Staff::display()
{
    cout << "STAFF : " << endl;
    cout << "                   Name : " << this->name << endl;
    cout << "                   Start Day : " << this->startDay << endl;
    cout << "                   Shift : " << this->shift << endl;
    cout << "                   Salary : " << this->salary << endl;
}
void Staff::edit(string name = "none", string code = "none", string startDay = "1/1/1990", string shift = "none", long salary = 0)
{
    this->name = name;
    this->startDay = startDay;
    this->shift = shift;
    this->salary = salary;
}
void Staff::input()
{
    cout << "Code : \n"; cin >> this->code;
    cout << "Start Day : \n"; cin >> this->startDay;
    cout << "Name : \n"; cin >> this->name;
    cout << "Salary : \n"; cin >> this->salary;
    cout << "Shift : \n"; cin >> this->shift;
}

#endif
