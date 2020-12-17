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
    void edit(string name, string code, string startDay, long balance);
    void input();
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
}
void User::edit(string name, string code, string startDay, long balance)
{
    this->name = name;
    this->startDay = startDay;
    this->balance = balance;
    this->code = code;
}
void User::input()
{
    cout << "Code : \n"; cin >> this->code;
    cout << "Start Day : \n"; cin >> this->startDay;
    cout << "Name : \n"; cin >> this->name;
    cout << "Balance : \n"; cin >> this->balance;
}


#endif