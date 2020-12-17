#ifndef COMPUTER_H
#define COMPUTER_H
#include<iostream>
#include<string>
using namespace std;

class Computer
{
private:
    bool free;
    string startDay;
    string code;
public:
    Computer(bool free, string startDay, string code);
    ~Computer();
};

Computer::Computer(bool free = true, string startDay = "none", string code = "none")
{
    this->code = code;
    this->free = free;
    this->startDay = startDay;
}

Computer::~Computer(){}

#endif