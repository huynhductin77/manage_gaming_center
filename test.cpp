#include<iostream>
#include "Staff.h"
#include "User.h"
#include "Computer.h"
using namespace std;

int main()
{
    Staff st("tin","asd","05/11/2001","asd", 1500000);
    st.display();
    st.edit("Huynh Duc Tin","asd","05/11/2001","asd",1500000);
    cout << "EDITED : " << endl;
    st.display();
    Computer cpt;

    system("pause");
    return 0;
}