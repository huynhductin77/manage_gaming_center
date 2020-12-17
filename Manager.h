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
    User** listUser;
    Staff** listStaff;
    Computer** listComputer;
public:
    Manager(int numOfStaff, int numOfUser, int numOfComputer);
    ~Manager();
    void menu();
    void loop();
    void display();
    void add();
    void remove();
    void search();
    void edit();
};

Manager::Manager(int numOfStaff = 0, int numOfUser = 0, int numOfComputer = 0)
{
    this->numOfComputer = numOfComputer;
    this->numOfUser = numOfUser;
    this->numOfStaff = numOfStaff;
    this->listComputer = new Computer*[numOfComputer];
    this->listUser = new User*[numOfUser];
    this->listStaff = new Staff*[numOfStaff];
}
Manager::~Manager()
{
    delete[] this->listComputer;
    delete[] this->listStaff;
    delete[] this->listUser;
}
void Manager::menu()
{
    cout << "------MENU----------" << endl;
    cout << "1. display" << endl;
    cout << "2. add " << endl;
    cout << "3. remove " << endl;
    cout << "4. search " << endl;
    cout << "5. edit " << endl;
    cout << "0. exit " << endl;
    cout << "+ choose your option : " << endl;
}
void Manager::loop()
{
    bool check = true;
    while(check)
    {
        int choose;
        menu();
        cin >> choose;
        switch (choose)
        {
        case 1:
            display();
            break;
        case 2:
            add();
            break;
        case 3:
            remove();
            break;
        case 4:
            search();
            break;
        case 5:
            edit();
            break;
        case 0:
            check = false;
            break;
        default:
            system("cls");
            cout << "wrong option !!" << endl;
            break;
        }
    }
}
void Manager::display()
{
    system("cls");
    cout << "COMPUTER : " << numOfComputer << endl;
    for(int i = 0; i < numOfComputer; i++)
        {
            cout << "\t";
            listComputer[i]->display();
        }
    cout << "USER : " << numOfUser << endl;
    for(int i = 0; i < numOfUser; i++)
    {
        cout << "\t";
        listUser[i]->display();
    }
    cout << "STAFF : " << numOfStaff << endl;
    for(int i = 0; i < numOfStaff; i++)
    {
        cout << "\t";
        listStaff[i]->display();
    }
    system("pause");
    system("cls");
}
void Manager::add()
{
    system("cls");
    cout << "1. Computer\n";
    cout << "2. User\n";
    cout << "3. Staff\n";
    int choose;
    cin >> choose;
    if(choose == 1) // add computer
    {
        this->numOfComputer += 1;
        this->listComputer[this->numOfComputer - 1] = new Computer();
        this->listComputer[this->numOfComputer - 1]->input();
    }
    else if(choose == 2)
    {
        this->numOfUser += 1;
        this->listUser[this->numOfUser - 1] = new User();
        this->listUser[this->numOfUser - 1]->input();
    }
    else if(choose == 3)
    {
        this->numOfStaff += 1;
        this->listStaff[this->numOfStaff - 1] = new Staff();
        this->listStaff[this->numOfStaff - 1]->input();
    }
    else
        cout << "wrong option!\n";
}
void Manager::remove()
{
    system("cls");
}
void Manager::search()
{
    system("cls");
}
void Manager::edit()
{
    system("cls");
}

#endif
