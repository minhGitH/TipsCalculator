// Tips calculator for Server Assistants
// Minh Nguyen in Nov, 2023
// A test input file is included in test1_input.txt
// To test this, type ./td test1_input.txt on the terminal after complying all the files

#include <iostream>
#include <iomanip>
#include <string>
#include <ios>
#include "Profile.h"
#include "MyADT.h"

using std::cout;
using std::cin;
using std::endl;
using std::fixed;
using std::setprecision;


void add(MyADT & theMembers) {

    string userName;
    double hourWorked;

    if (theMembers.getElementCount()>=theMembers.getElementsNumber())
    {
        cout<<"The number of SA is max, modify the number of SAs to add more SA"<<endl;
        return;
    }
    cout<<"Enter username: ";
    cin.ignore();
    getline(cin,userName);
    
    cout<<"Enter hour worked: ";
    cin>>hourWorked;


   Profile newMember(userName,hourWorked);//create new element for adt
   
   if (!(theMembers.insert(newMember)))
   {
      cout<<"\nFail to add"<<endl;
      return;
   }
   cout<<"\nSucceed to add"<<endl;
   return; 

}

void remove(MyADT & theMembers) {

    if (theMembers.getElementCount()==0)
    {
        cout<<"There is no SA to remove."<<endl;
        return;
    }
   string userName;
   cout<<"Enter username: ";
   cin.ignore();
   getline(cin,userName);

   Profile memberTobeRomoved(userName);

   if (!(theMembers.remove(memberTobeRomoved)))
   {
      cout<<"Fail to remove the member"<<endl;
      return;
   }
   cout<<"Succeed to remove the member"<<endl;
   return;

}

void search(MyADT & theMembers) {

   string userName;
   cout<<"Enter username: ";
   getline(cin,userName);
   

   Profile member(userName);

   cout<<"\n";
   if (theMembers.search(member)==nullptr)
   {
      cout<<"The member can not be found"<<endl;
      return;
   }
   cout<<"The member is found"<<endl;

}

void modify(MyADT & theMembers) {
    char input = 0;
    bool done= false;
    while (!done && cin)
    {
        cout << endl << "Enter ..." << endl;
        cout << "m -> to modify the total money collected." << endl;
        cout << "n -> to increase the numbers of Server Assistants." << endl;
        cout << "h -> to modify the hour worked of a Server Assistant."<<endl;
        cout << "x -> to exit the modification." << endl << endl;
        cout << "Your choice: ";
        cin >> input;
        cout << endl;
        input = tolower(input);

        switch (input)
        {
        case 'h':
            {
                string userName;
                double hourWorked;
                cout<<"Enter username: ";
                cin.ignore();
                getline(cin,userName);
                Profile * memberPtr=theMembers.search(userName);
                if (memberPtr==nullptr)
                {
                    cout<<"The member can not be found"<<endl;
                    return;
                }
                cout<<"The member is found"<<endl;
                cout<<"What is the hour of this Server Assistant? ";
                cin>>hourWorked;
                memberPtr->setHour(hourWorked);
                break;
            }
        case 'm':
        {
            double moneyTotal=0;
            cout<<"How much money collected? ";
            cin>>moneyTotal;
            theMembers.setMoneyTotal(moneyTotal);
            break;
        }
        case 'n':
        {
            unsigned int numSA=0;
            cout<<"How many Server Assistants you have? (new number must be greater than old number) ";
            cin >> numSA;
            if (numSA<theMembers.getElementCount())
                cout<<"Invalid input."<<endl;
            else
                theMembers.setElements_number(numSA);
            break;
        }
        case 'x': cout<<"Exit the modification."<<endl;
                done=true; break;
        default: cout << "Not sure what you mean! Please, try again!" << endl;
        }
    }
}

void print(MyADT & theMembers) {
    cout<<fixed;
    cout<<setprecision(2);
    theMembers.print();

}

void calculate(MyADT & theMembers) {
    theMembers.calculate();
}

int main() {

    // Variables declaration
    MyADT members = MyADT();  // Object MyADT on the stack, its arrays on the heap
    bool done = false;
    char input = 0;
    unsigned int numSA=0;
    double moneyTotal=0;
    cout<<"How many Server Assistants you have? ";
    cin >> numSA;
    members.setElements_number(numSA);
    cout<<"How much money collected? ";
    cin>>moneyTotal;
    members.setMoneyTotal(moneyTotal);
    // Keep going until the user exits
    while (!done && cin) {
        // Print menu to stdout
        cout << endl << "Enter ..." << endl;
        cout << "a -> to add a Server Assistant by creating a profile." << endl;
        cout << "r -> to remove a Server Assistant off the tips calculator." << endl;
        cout << "s -> to search for a Server Assistant on tips calculator." << endl;
        cout << "m -> to modify your profile on tips calculator." << endl;
        cout << "p -> to print all members on the tips calculator." << endl;
        cout << "c -> to calculate all the tips for all Server Assistant." <<endl;
        cout << "x -> to exit the tips calculator." << endl << endl;


        cout << "Your choice: ";
        cin >> input;
        cout << endl;
        input = tolower(input);
        switch(input) {
            case 'a': add(members); break;
            case 'r': remove(members); break;
            case 's': search(members); break;
            case 'm': modify(members); break;
            case 'p': print(members); break;
            case 'c': calculate(members); break;
            case 'x': cout << "\n----Bye!\n" << endl; 
                      done = true; break;
            default: cout << "Not sure what you mean! Please, try again!" << endl;
        }
    }
    return 0;
}
