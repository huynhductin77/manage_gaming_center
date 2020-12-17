#ifndef COMPUTER_H
#define COMPUTER_H
#include<iostream>
#include<string>
using namespace std;

class Computer
{
private:
    string free;
    string startDay;
    string code;
public:
    Computer(string free, string startDay, string code);
    Computer(const Computer* cpt);
    ~Computer();
    void display();
    void edit(string free, string startDay, string code);
    void input();
};

Computer::Computer(string free = "none", string startDay = "none", string code = "none")
{
    this->code = code;
    this->free = free;
    this->startDay = startDay;
}
Computer::Computer(const Computer* cpt)
{
    this->free = cpt->free;
    this->startDay = cpt->startDay;
    this->code = cpt->code;
}
Computer::~Computer(){}
void Computer::display()
{
    cout << "COMPUTER : " << endl;
    cout << "                   Free : " << free << endl;
    cout << "                   Start Day : " << startDay << endl;
    cout << "                   Code : " << code << endl;
}
void Computer::edit(string free = "none", string startDay = "none", string code = "none")
{
    this->free = free;
    this->startDay = startDay;
    this->code = code;
}
void Computer::input()
{
    string free;
    string startDay;
    string code;
    cout << "Code : \n"; cin >> code;
    cout << "Start Day : \n"; cin >> startDay;
    cout << "Status : \n"; cin >> free;
    this->code = code;
    this->free = free;
    this->startDay = startDay;
}

#endif