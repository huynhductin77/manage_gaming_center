#ifndef STAFF_H
#define STAFF_H
#include "People.h"
#include "str.h"
#include <iostream>
#include <string>
#include <ctype.h>
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
    string getStartDay();
    string getShift();
    long getSalary();
    void setCode(string code);
    void setName(string name);
    void setStartDay(string startDay);
    void setShift(string shift);
    void setSalary(long salary);
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
    getline(cin, code);
    cout << "Code : \n"; getline(cin, code);
    cout << "Start Day : \n"; getline(cin, startDay);
    cout << "Name : \n"; 
    string name; getline(cin, name);
    formatStr(name);
    this->name = name;
    cout << "Salary : \n"; cin >> this->salary;
    cout << "Shift : \n"; getline(cin, shift);
    getline(cin, shift);
}
string Staff::getCode()
{
    return this->code;
}
string Staff::getName()
{
    return this->name;
}
string Staff::getStartDay() {
    return this->startDay;
};
string Staff::getShift() {
    return this->shift;
};
long Staff::getSalary() {
    return this->salary;
};
void Staff::setCode(string code) {
    this->code = code;
};
void Staff::setName(string name) {
    this->name = name;
};
void Staff::setStartDay(string startDay) {
    this->startDay = startDay;
};
void Staff::setShift(string shift) {
    this->shift = shift;
};
void Staff::setSalary(long salary) {
    this->salary = salary;
};
#endif
