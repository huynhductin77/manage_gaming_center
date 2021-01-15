#ifndef COMPUTER_H
#define COMPUTER_H
#include<iostream>
#include<string>
using namespace std;

class Computer
{
private:
    string status;
    string startDay;
    string code;
public:
    Computer(string status, string startDay, string code);
    Computer(const Computer* cpt);
    ~Computer();
    void display();
    void edit();
    void input();
    string getCode();
    string getStartDay();
    string getStatus();
    void setCode(string code);
    void setStartDay(string startDay);
    void setStatus(string status);
};

Computer::Computer(string status = "none", string startDay = "none", string code = "none")
{
    this->code = code;
    this->status = status;
    this->startDay = startDay;
}
Computer::Computer(const Computer* cpt)
{
    this->status = cpt->status;
    this->startDay = cpt->startDay;
    this->code = cpt->code;
}
Computer::~Computer(){}
void Computer::display()
{
    cout << "COMPUTER : " << endl;
    cout << "                   status : " << status << endl;
    cout << "                   Start Day : " << startDay << endl;
    cout << "                   Code : " << code << endl;
}
void Computer::edit()
{
    cout << "Status : \n";cin >> this->status;
    cout << "Start Day : \n"; cin >> this->startDay;
    cout << "Code : \n"; cin >>this->code;
}
void Computer::input()
{
    string status;
    string startDay;
    string code;
    getline(cin, code);
    cout << "Code : \n"; getline(cin, code);
    cout << "Start Day : \n"; getline(cin, startDay);
    cout << "Status : \n"; getline(cin, status);
    this->code = code;
    this->status = status;
    this->startDay = startDay;
}
string Computer::getCode()
{
    return this->code;
}
string Computer::getStartDay() {
    return this->startDay;
}
string Computer::getStatus() {
    return this->status;
};
void Computer::setCode(string code) {
    this->code = code;
};
void Computer::setStartDay(string startDay) {
    this->startDay = startDay;
};
void Computer::setStatus(string status) {
    this->status = status;
};

#endif