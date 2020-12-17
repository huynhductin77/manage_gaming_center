#include<iostream>
#include "Staff.h"
#include "User.h"
#include "Computer.h"
using namespace std;

int main()
{
    User st("tin","05/11/2001",1500000);
    st.display();
    st.edit("Huynh Duc Tin","05/11/2001",1500000);
    cout << "EDITED : " << endl;
    st.display();
    system("pause");
    return 0;
}