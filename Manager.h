#ifndef MANAGER_H
#define MANAGER_H
#include<iostream>
#include<string>
#include<fstream>
#include "Computer.h"
#include "User.h"
#include "Staff.h"
using namespace std;

fstream file;

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
};                                                                                                       // class

Manager::Manager(int numOfStaff = 0, int numOfUser = 0, int numOfComputer = 0)
{
    this->numOfComputer = numOfComputer;
    this->numOfUser = numOfUser;
    this->numOfStaff = numOfStaff;
    this->listComputer = new Computer*[numOfComputer];
    this->listUser = new User*[numOfUser];
    this->listStaff = new Staff*[numOfStaff];
}                                                                                            // default constructor

Manager::~Manager(){}
void Manager::menu()
{
    system("figlet -f /mnt/d/figlet-fonts/smslant.flf \"                       CHANAS GAMING CENTER\" -w 200| lolcat --animate -d 5");
    cout << "\t\t\t\t\t\t\t\t------MENU----------" << endl;
    cout << "\t\t\t\t\t\t\t\t1. display" << endl;
    cout << "\t\t\t\t\t\t\t\t2. add " << endl;
    cout << "\t\t\t\t\t\t\t\t3. remove " << endl;
    cout << "\t\t\t\t\t\t\t\t4. search " << endl;
    cout << "\t\t\t\t\t\t\t\t5. edit " << endl;
    cout << "\t\t\t\t\t\t\t\t0. exit " << endl;
    cout << "\t\t\t\t\t\t\t\t+ choose your option : " << endl;
}                                                                                            // menu

void Manager::loop()
{
    system("clear");
    file.open("data/computer.dat", ios::in );                                      // read computer's data from file
    int i = 0;
    string com1, com2, com3, staff1, staff2, staff3, staff4, user1, user2, user3;   // temporary var
    long user0, staff0;
    if(file.peek() != -1)                                                            // check empty file
        if(file.good())                                                              // check good file
            while(!file.eof()) {                                                     // check end file
                listComputer[numOfComputer] = new Computer();
                numOfComputer++;
                getline(file, com1);
                getline(file, com2);
                getline(file, com3);  
                listComputer[i]->setCode(com1);
                listComputer[i]->setStatus(com2);
                listComputer[i]->setStartDay(com3); 
                i++;
            }
    file.close();
    file.open("data/staff.dat", ios::in );                                                       // read staff's data from file
    i = 0;
    if(file.peek() != -1)                                                                         // check empty file
        if(file.good())                                                                           // check good file
            while(!file.eof()) {                                                                  // check end file
                listStaff[numOfStaff] = new Staff;
                numOfStaff++;
                string tmp;
                getline(file, tmp);
                staff0 = atoi(tmp.c_str());
                getline(file, staff1);
                getline(file, staff2);
                getline(file, staff3);
                getline(file, staff4);
                listStaff[i]->setCode(staff2);
                listStaff[i]->setName(staff1);
                listStaff[i]->setSalary(staff0);
                listStaff[i]->setShift(staff3);
                listStaff[i]->setStartDay(staff4);
                i++;
            }
    file.close();
    file.open("data/user.dat", ios::in );                                              // read user's data from file
    i = 0;
    if(file.peek() != -1)                                                               // check empty file
        if(file.good())                                                                 // check good file 
            while(!file.eof()) {                                                        // check end file
                listUser[numOfUser] = new User;
                numOfUser++;
                string tmp;
                getline(file, tmp);
                user0 = atoi(tmp.c_str());
                getline(file, user2);
                getline(file, user1);
                getline(file, user3);
                listUser[i]->setBalance(user0);
                listUser[i]->setCode(user1);
                listUser[i]->setName(user2);
                listUser[i]->setStartDay(user3);
                i++;
            }
    file.close();
    bool check = true;
    while(check) // MAIN LOOP
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
        case 0: {
            check = false;
            string com11, com12, com13, staff11, staff12, staff13,staff14, user11, user12, user13;     // temporary var
            long staff10, user10;
            file.open("data/computer.dat", ios::out | ios::trunc );                    // write computer's data to file
            for(int i = 0; i < numOfComputer; i++) {
                com11 = listComputer[i]->getCode();
                com12 = listComputer[i]->getStatus();
                com13 = listComputer[i]->getStartDay();
                if(i != 0) file << endl;
                file << com11 << endl << com12 << endl << com13;
            }
            file.close();
            file.open("data/staff.dat", ios::out | ios::trunc);                        // write staff's data to file
            for(int i = 0; i < numOfStaff; i++) {
                staff11 = listStaff[i]->getName();
                staff12 = listStaff[i]->getCode();
                staff13 = listStaff[i]->getShift();
                staff14 = listStaff[i]->getStartDay();
                staff10 = listStaff[i]->getSalary();
                if(i != 0) file << endl;
                file << staff10 << endl << staff11 << endl << staff12 << endl << staff13 << endl<< staff14;
            }
            file.close();
            file.open("data/user.dat", ios::out | ios::trunc );                        // write user's data to file
            for(int i = 0; i < numOfUser; i++) {
                user11 = listUser[i]->getName();
                user12 = listUser[i]->getCode();
                user13 = listUser[i]->getStartDay();
                user10 = listUser[i]->getBalance();
                if(i != 0) file << endl;
                file << user10 << endl << user11 << endl << user12 << endl << user13;
            }
            file.close();
            break;
            }
        default:
            system("clear");
            cout << "\t\t\t\t\t\t\t\twrong option !!" << endl;
            break;
        }
    }
}                                                                                               // loop

void Manager::display()
{
    system("clear");
    cout << "\t\t\t\t\t\t\t\tCOMPUTER : " << numOfComputer << endl;
    for(int i = 0; i < numOfComputer; i++)
        {
            cout << "\t";
            listComputer[i]->display();
        }
    cout << "\t\t\t\t\t\t\t\tUSER : " << numOfUser << endl;
    for(int i = 0; i < numOfUser; i++)
    {
        cout << "\t";
        listUser[i]->display();
    }
    cout << "\t\t\t\t\t\t\t\tSTAFF : " << numOfStaff << endl;
    for(int i = 0; i < numOfStaff; i++)
    {
        cout << "\t";
        listStaff[i]->display();
    }
    system("sleep 2");
    system("clear");
}                                                                                                   // display

void Manager::add()
{
    system("clear");
    cout << "\t\t\t\t\t\t\t\t1. Computer\n";
    cout << "\t\t\t\t\t\t\t\t2. User\n";
    cout << "\t\t\t\t\t\t\t\t3. Staff\n";
    int choose;
    cin >> choose;
    system("clear");
    if(choose == 1)                                                                                 // add computer
    {
        bool check = true;
        int count;
        this->listComputer[this->numOfComputer] = new Computer();
        while(check) {
            count = 0;
            this->listComputer[this->numOfComputer]->input();
            for(int i = 0; i < numOfComputer; i++) {
                if(this->listComputer[this->numOfComputer]->getCode() == listComputer[i]->getCode())
                    count++;
            }
            if(count == 0) {
                this->numOfComputer += 1;
                check = false;
            }
            else
            {
                cout << "\t\t\t\t\t\t\tInvalid Code";
            }           
        }
    }
    else if(choose == 2)                                                                            // add user
    {
        bool check = true;
        int count;
        this->listUser[this->numOfUser] = new User();
        while(check) {
            count = 0;
            this->listUser[this->numOfUser]->input();
            for(int i = 0; i < numOfUser; i++) {
                if(this->listUser[this->numOfUser]->getCode() == listUser[i]->getCode())
                    count++;
            }
            if(count == 0) {
                this->numOfUser += 1;
                check = false;
            }
            else
            {
                cout << "\t\t\t\t\t\t\tInvalid Code";
            }           
        }
    }
    else if(choose == 3)                                                                            // add staff
    {
        bool check = true;
        int count;
        this->listStaff[this->numOfStaff] = new Staff();
        while(check) {
            count = 0;
            this->listStaff[this->numOfStaff]->input();
            for(int i = 0; i < numOfStaff; i++) {
                if(this->listStaff[this->numOfStaff]->getCode() == listStaff[i]->getCode())
                    count++;
            }
            if(count == 0) {
                this->numOfStaff += 1;
                check = false;
            }
            else
            {
                cout << "\t\t\t\t\t\t\tInvalid Code";
            }           
        }
    }
    else
    {
        cout << "\t\t\t\t\t\t\t\twrong option!\n";
        system("sleep 2");
    }
    system("clear");
    cout << "\t\t\t\t\t\t\t\tADD SUCCESSFULLY! \n";
}                                                                                                   // add

void Manager::remove()
{
    system("clear");
    cout << "\t\t\t\t\t\t\t\t1. remove computer \n";
    cout << "\t\t\t\t\t\t\t\t2. remove people \n";
    cout << "\t\t\t\t\t\t\t\tEnter your optioon : \n";
    int choose; cin >> choose;
    system("clear");
    int countc = 0, counts = 0, countu = 0;
    if(choose == 1)                                                                             // remove computer
    {
        cout << "\t\t\t\t\t\t\t\tEnter the code : \n";
        string code; getline(cin, code);
        getline(cin, code);
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
    else if(choose == 2)                                                                         // remove people
    {
        cout << "\t\t\t\t\t\t\t\tEnter the code : \n";
        string code;  getline(cin, code);
        getline(cin, code);
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
        for(int i = 0; i < numOfUser; i++)
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
        cout << "\t\t\t\t\t\t\t\twrong option!\n";
        system("sleep 2");
    }
    system("clear");
    if( countc == 0)
    {
        cout << "\t\t\t\t\t\t\tRemove " << counts << " staff(s), " << countu << " user(s) out of system!\n";
    }
    else
        cout << "\t\t\t\t\t\t\tRemove " << countc << " computer out of system!\n";    
}                                                                                                      // remove

void Manager::search()
{
    system("clear");
    cout << "\t\t\t\t\t\t\t\t1. computer search\n";
    cout << "\t\t\t\t\t\t\t\t2. people search\n";
    cout << "\t\t\t\t\t\t\t\tEnter your option : \n";
    int choose; cin >> choose;
    system("clear");
    if(choose == 1)
    {
        int count = 0;
        cout << "\t\t\t\t\t\t\t\tEnter the code : \n";
        string code; getline(cin, code);
        getline(cin, code);
        for(int i = 0; i < numOfComputer; i++)
        {
            if(this->listComputer[i]->getCode() == code)
            {
                this->listComputer[i]->display();   
                count++;             
            }
        }
        if(count == 0) cout << "\t\t\t\t\t\t\t\tnot found !\n";
    }
    else if(choose == 2)
    {
        int count = 0;
        cout << "\t\t\t\t\t\t\t\tEnter the code : \n";
        string code; getline(cin, code);
        getline(cin, code);
        for(int i = 0; i < numOfUser; i++)
        {
            if(this->listUser[i]->getCode() == code)
            {
                this->listUser[i]->display();  
                count++;     
            }
        }
        for(int i = 0; i < numOfStaff; i++)
        {
            if(this->listStaff[i]->getCode() == code)
            {
                this->listStaff[i]->display();      
                count++; 
            }
        }
        if(count == 0) cout << "\t\t\t\t\t\t\t\tnot found !\n";
    }
    else{
        cout << "\t\t\t\t\t\t\t\twrong option!\n";
        system("sleep 2");
    }
    system("sleep 2");
    system("clear");
}                                                                                                            // search

void Manager::edit()
{
    system("clear");
    cout << "\t\t\t\t\t\t\t\t1. edit computer's detail \n";
    cout << "\t\t\t\t\t\t\t\t2. edit people's detail \n";
    cout << "\t\t\t\t\t\t\t\tEnter your option : \n";
    int choose, count = 0; cin >> choose;
    system("clear");
    if(choose == 1)
    {
        string code;
        cout << "\t\t\t\t\t\t\t\tEnter code : \n"; getline(cin, code);
        getline(cin, code);
        for(int i = 0; i < numOfComputer; i++)
        {
            if(this->listComputer[i]->getCode() == code)
            {
                count++;
                cout << "\t\t\t\t\t\t\t\tEnter new detail : \n";
                this->listComputer[i]->edit();
            }
        }
    }
    else if(choose == 2)
    {
        string code;
        cout << "\t\t\t\t\t\t\t\tEnter code : \n"; getline(cin, code);
        getline(cin, code);
        for(int i = 0; i < numOfStaff; i++)
        {
            if(this->listStaff[i]->getCode() == code)
            {
                count++;
                cout << "\t\t\t\t\t\t\t\tEnter new detail : \n";
                this->listStaff[i]->edit();
            }
        }
        for(int i = 0; i < numOfUser; i++)
        {
            if(this->listUser[i]->getCode() == code)
            {
                count++;
                cout << "\t\t\t\t\t\t\t\tEnter new detail : \n";
                this->listUser[i]->edit();
            }
        }
    }
    else
    {
        cout << "\t\t\t\t\t\t\t\twrong option!\n";
        system("sleep 2");
    }
    system("clear");
    if(count > 0)
        cout << "\t\t\t\t\t\t\t\tEDIT SUCCESSFULLY!\n";
    else
        cout << "\t\t\t\t\t\t\t\tNO USER MATCH !\n";
}                                                                                                                // edit

#endif
