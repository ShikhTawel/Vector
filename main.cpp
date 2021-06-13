#include <iostream>
#include "ManualVector.h"
#include "Students.h"

using namespace std;

int mainMenu() // Function that shows the Main Menu "Which Type of List" and Check the Input
{
    cout<<"Insert type of vector you would like to create: \n";
    cout<<"1. list of integer \n";
    cout<<"2. list of character \n";
    cout<<"3. list of string \n";
    cout<<"4. list of float \n";
    cout<<"5. list of students \n";
    cout<<"6. Exit \n";
    int choice;
    cin>>choice;
    while(choice>6 ||choice <1)
    {
        cout<<"Enter Numbers Between 1~6 only! \n";
        cin>>choice;
    }
    return choice;
}

int main() {
again:
    int choice=mainMenu();         // Displaying The Main Menu
    if(choice == 1)               // User Chose Integer
    {
        ManualVector<int> integer;
        integer.opt(integer);   //Function in the ManualVector Class that do the Operations that the user Chooses
    }
    else if(choice == 2)          // User Chose char
    {
        ManualVector<char> charr;
        charr.opt(charr);
    }
    else if(choice == 3)           // User Chose string
    {
        ManualVector<string> str;
        str.opt(str);
    }
    else if(choice == 4)            // User Chose float
    {
        ManualVector<float> flt;
        flt.opt(flt);
    }
    else if(choice == 5)            // User Chose Student
    {
        ManualVector<Students> std;
        std.opt(std);
    }
    else if(choice == 6)            // User Chose Exit
    {
        return 0;
    }
    goto again;                     // Redo The Program until the user chooses to Exit
}