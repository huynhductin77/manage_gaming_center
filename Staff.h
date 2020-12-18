#ifndef STAFF_H
#define STAFF_H
#include "People.h"
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
};

string delSpaceChar(string& result)
{
    for(int i = result.length() - 1; i >= 0; i--) //del space character at the tail of string 
    {
        if(result.at(i) ==  ' ')
        {
            result.pop_back();
        }
        else
            break;
    }
    for(int i = 0; i < result.length(); i++) //del space character at the head of string 
    {
        if(result.at(i) ==  ' ')
        {
            i--;
            result = result.substr(1, result.length() - 1);
        }
        else
            break;
    }
    return result;
}
string formatStr(string& result)
{
    delSpaceChar(result);
    if(!isupper(result.at(0)))
    {
        result.at(0) = toupper(result.at(0));
    } // first character
    for(int i = 0; i < result.length() - 1; i++)
    {
        if(result.at(i) == ' ' && islower(result.at(i+1)))
            result.at(i+1) = toupper(result.at(i+1));
    } // " *" --> upper *
    for(int i = 0; i < result.length() - 1; i++)
    {
        if(isalpha(result.at(i)) && isupper(result.at(i+1)))
            result.at(i+1) = tolower(result.at(i+1));
    } // "**" --> lower * 2nd
    cout << result;
    return result;
}
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
    cout << "Name : \n"; 
    string name; cin >> name;
    formatStr(name);
    this->name = name;
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
