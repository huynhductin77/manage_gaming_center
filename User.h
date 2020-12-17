#ifndef USER_H
#define USER_H
#include <iostream>
#include "People.h"
#include <string>
using namespace std;

class User : public People
{
private:
    int balance;
public:
    User(string name, string code, string startDay, int balance);
    ~User();
    void display();
    void edit(string name, string code, string startDay, int balance);
};

User::User(string name = "none", string code = "none", string startDay = "1/1/1990", int balance = 0)
: People(name, startDay)
{
    this->balance = balance;
}
User::~User(){}
void User::display()
{
    cout << "USER : " << endl;
    cout << "   Name : " << this->name << endl;
    cout << "   Start Day : " << this->startDay << endl;
    cout << "   Balance : " << this->balance << endl;
}
void User::edit(string name, string code, string startDay, int balance)
{
    this->name = name;
    this->startDay = startDay;
    this->balance = balance;
}

#endif