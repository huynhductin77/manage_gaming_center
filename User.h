#ifndef USER_H
#define USER_H
#include <iostream>
#include "People.h"
#include <string>
using namespace std;

class User : public People
{
private:
    long balance;
public:
    User(string name, string code, string startDay, long balance);
    User(const User* us);
    ~User();
    void display();
    void edit();
    void input();
    string getCode();
    string getName();
};

User::User(string name = "none", string code = "none", string startDay = "1/1/1990", long balance = 0)
: People(name, startDay, code)
{
    this->balance = balance;
}
User::User(const User* us)
{
    this->code = us->code;
    this->name = us->name;
    this->balance = us->balance;
    this->startDay = us->startDay;
}
User::~User(){}
void User::display()
{
    cout << "USER : " << endl;
    cout << "                   Name : " << this->name << endl;
    cout << "                   Start Day : " << this->startDay << endl;
    cout << "                   Balance : " << this->balance << endl;
    cout << "                   Code : " << this->code << endl;
}
void User::input()
{
    cout << "Code : \n"; cin >> this->code;
    cout << "Start Day : \n"; cin >> this->startDay;
    cout << "Name : \n"; cin >> this->name;
    cout << "Balance : \n"; cin >> this->balance;
}
string User::getCode()
{
    return this->code;
}
string User::getName()
{
    return this->name;
}
void User::edit()
{
    cout << "Name : \n"; cin >> this->name;
    cout << "Code : \n"; cin >> this->code;
    cout << "Start Day : \n"; cin >> this->startDay;
    cout << "Balance : \n"; cin >> this->balance;
}

#endif