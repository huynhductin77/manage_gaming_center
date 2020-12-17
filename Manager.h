#ifndef MANAGER_H
#define MANAGER_H
#include<iostream>
#include<string>
#include "Computer.h"
#include "User.h"
#include "Staff.h"
using namespace std;

class Manager
{
private:
    int numOfStaff, numOfUser, numOfComputer;
    User* listUser;
    Staff* listStaff;
    Computer* listComputer;
public:
    Manager();
    ~Manager();
    void menu();
    void loop();
    void display();
    void add();
    void remove();
    void searchPeople();
    void searchComputer();
    void edit();
};

Manager::Manager()
{
}
Manager::~Manager(){}
void Manager::menu(){return;}
void Manager::loop(){return;}
void Manager::display(){return;}
void Manager::add(){return;}
void Manager::remove(){return;}
void Manager::searchPeople(){return;}
void Manager::searchComputer(){return;}
void Manager::edit(){return;}

#endif
