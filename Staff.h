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
    void edit();
    void input();
    string getCode();
    string getName();
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
    cout << "                   Code : " << this->code << endl;
}
void Staff::edit()
{
    cout << "Name : \n"; cin >> this->name;
    cout << "Code : \n"; cin >> this->code;
    cout << "Start Day : \n"; cin >> this->startDay;
    cout << "Salary : \n"; cin >> this->salary;
    cout << "Shift : \n"; cin >> this->shift;
}
void Staff::input()
{
    cout << "Code : \n"; cin >> this->code;
    cout << "Start Day : \n"; cin >> this->startDay;
    cout << "Name : \n"; cin >> this->name;
    cout << "Salary : \n"; cin >> this->salary;
    cout << "Shift : \n"; cin >> this->shift;
}
string Staff::getCode()
{
    return this->code;
}
string Staff::getName()
{
    return this->name;
}

#endif
