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
Manager::~Manager(){}
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
    {
        cout << "wrong option!\n";
        system("pause");
    }
    system("cls");
    cout << "ADD SUCCESSFULLY! \n";
}
void Manager::remove()
{
    system("cls");
    cout << "1. remove computer \n";
    cout << "2. remove people \n";
    cout << "Enter your optioon : \n";
    int choose; cin >> choose;
    int countc = 0, counts = 0, countu = 0;
    if(choose == 1)
    {
        cout << "Enter the code : \n";
        string code; cin >> code;
        for(int i = 0; i < numOfComputer; i++)
        {
            if(this->listComputer[i]->getCode() == code)
            {
                this->numOfComputer--;
                countc++;
                for(int j = i; j < this->numOfComputer - 1; j++)
                    this->listComputer[j] = this->listComputer[j + 1];
            }   
        }
    }
    else if(choose == 2)
    {
        cout << "Enter the code : \n";
        string code; cin >> code;
        for(int i = 0; i < numOfStaff; i++)
        {
            if(this->listStaff[i]->getCode() == code)
            {
                this->numOfStaff--;
                counts++;
                for(int j = i; j < this->numOfStaff - 1; j++)
                    this->listStaff[j] = this->listStaff[j + 1];
            }   
        }
        for(int i = 0; i < numOfStaff; i++)
        {
            if(this->listUser[i]->getCode() == code)
            {
                this->numOfUser--;
                countu++;
                for(int j = i; j < this->numOfUser - 1; j++)
                    this->listUser[j] = this->listUser[j + 1];
            }   
        }
    }
    else
    {
        cout << "wrong option!\n";
        system("pause");
    }
    system("cls");
    if( countc == 0)
    {
        cout << "Remove " << counts << " staff(s), " << countu << " user(s) out of system!\n";
    }
    else
        cout << "Remove " << countc << " computer out of system!\n";    
}
void Manager::search()
{
    system("cls");
    cout << "1. computer search\n";
    cout << "2. people search\n";
    cout << "Enter your option : \n";
    int choose; cin >> choose;
    if(choose == 1)
    {
        cout << "Enter the code : \n";
        string code; cin >> code;
        for(int i = 0; i < numOfComputer; i++)
        {
            if(this->listComputer[i]->getCode() == code)
            {
                this->listComputer[i]->display();                
            }
        }
    }
    else if(choose == 2)
    {
        cout << "1. By code\n";
        cout << "2. By Name\n";
        cout << "Enter your option : \n";
        int choo; cin >> choo;
        if(choo == 1)
        {
            cout << "Enter the code : \n";
            string code; cin >> code;
            for(int i = 0; i < numOfUser; i++)
            {
                if(this->listUser[i]->getCode() == code)
                {
                    this->listUser[i]->display();       
                }
            }
            for(int i = 0; i < numOfUser; i++)
            {
                if(this->listStaff[i]->getCode() == code)
                {
                    this->listStaff[i]->display();       
                }
            }
        }
        else if(choo == 2)
        {
            cout << "Enter the name : \n";
            string name; cin >> name;
            for(int i = 0; i < numOfUser; i++)
            {
                if(listUser[i]->getCode() == name)
                    listUser[i]->display();       
            }
            for(int i = 0; i < numOfUser; i++)
            {
                if(listStaff[i]->getCode() == name)
                    listStaff[i]->display();       
            }
        }
        else
        {
            cout << "wrong option!\n";
        }
        
    }
    else{
        cout << "wrong option!\n";
        system("pause");
    }
    
    system("pause");
    system("cls");
}
void Manager::edit()
{
    system("cls");
    cout << "1. edit computer's detail \n";
    cout << "2. edit people's detail \n";
    cout << "Enter your option : \n";
    int choose, count = 0; cin >> choose;
    if(choose == 1)
    {
        string code;
        cout << "Enter code : \n"; cin >> code;
        for(int i = 0; i < numOfComputer; i++)
        {
            if(this->listComputer[i]->getCode() == code)
            {
                count++;
                cout << "Enter new detail : \n";
                this->listComputer[i]->edit();
            }
        }
    }
    else if(choose == 2)
    {
        string code;
        cout << "Enter code : \n"; cin >> code;
        for(int i = 0; i < numOfStaff; i++)
        {
            if(this->listStaff[i]->getCode() == code)
            {
                count++;
                cout << "Enter new detail : \n";
                this->listStaff[i]->edit();
            }
        }
        for(int i = 0; i < numOfStaff; i++)
        {
            if(this->listUser[i]->getCode() == code)
            {
                count++;
                cout << "Enter new detail : \n";
                this->listUser[i]->edit();
            }
        }
    }
    else
    {
        cout << "wrong option!\n";
        system("pause");
    }
    system("cls");
    if(count > 0)
        cout << "EDIT SUCCESSFULLY!\n";
    else
        cout << "NO USER MATCH !\n";
}

#endif
