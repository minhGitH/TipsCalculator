/*
 * MyADT.cpp
 * 
 * Class Description: A linear data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - This is an unsorted data collection 
 *                   - Its data structure is not expandable, i.e., resizable. 
 *
 * Author: AL
 * Last modified on: Sept. 2023
 */


#include <iostream>
#include <cctype>
#include "MyADT.h"  // Header file
#include "Profile.h"

using std::cout;
using std::endl;

// Default constructor.
MyADT::MyADT() {
    ELEMENTS_NUMBER=0;
    hoursTotal=0;
    moneyTotal=0;
    elements=nullptr;
    elementCount=0;
    hourRate=0;
}  // end default constructor


// Copy constructor - Covered in Lab 3
MyADT::MyADT(const MyADT& rhs) {
    ELEMENTS_NUMBER=0;
    hoursTotal=0;
    moneyTotal=0;
    elements=nullptr;
    elementCount=0;
    hourRate=0;
    if (rhs.elementCount>0)
    {
        this->ELEMENTS_NUMBER=rhs.ELEMENTS_NUMBER;
        this->elements=new Profile[ELEMENTS_NUMBER];
        this->elementCount=rhs.elementCount;
        this->hoursTotal=rhs.hoursTotal;
        this->moneyTotal=rhs.moneyTotal;
        this->hourRate=rhs.hourRate;
        for (unsigned int i=0;i<elementCount;i++)
        {
            this->elements[i]=rhs.elements[i];
        }
    }
}  // end copy constructor


// Destructor
// Description: Destruct this object, releasing heap-allocated memory.
MyADT::~MyADT() {

    delete[] elements;
    elements=0;

} // end destructor

//Getters

// Description: Returns the total element count of elements currently stored in MyADT.
unsigned int MyADT::getElementCount() const {
    return elementCount;
}  

// Description: Returns the HoursTotal currently stored in MyADT.
double MyADT::getHoursTotal() const {
    double hoursTotal=0;
    for (unsigned int i=0;i<elementCount;i++)
    {
        hoursTotal=hoursTotal+elements[i].getHour();
    }
    return hoursTotal;
}

// Description: Returns the moneyTotal currently stored in MyADT.
double MyADT::getMoneyTotal() const {
    return moneyTotal;
}
// Description: Returns the ELEMENTS_NUMBER currently stored in MyADT.
unsigned int MyADT::getElementsNumber() const {
    return ELEMENTS_NUMBER;
}

// Setters
void MyADT::setElements_number(const unsigned int aNumber){
    ELEMENTS_NUMBER=aNumber;
    if (elementCount == 0)
    {
        return;
    }
    Profile * temp=new Profile[ELEMENTS_NUMBER];
    for (unsigned int i=0;i<elementCount;i++)
    {
        temp[i]=elements[i];
    }
    delete[] elements;
    elements=temp;
}
void MyADT::setHourRate(double aNumber){
    hourRate=aNumber;
}

void MyADT::setMoneyTotal(double aNumber){
    moneyTotal=aNumber;
}

// Description: Inserts an element.
// Precondition: newElement must not already be in data collection.  
// Postcondition: newElement inserted and the appropriate elementCount has been incremented.
//                Returns "true" when the insertion is successfull,
//                otherwise "false".
bool MyADT::insert(const Profile& newElement) {

    if (elementCount==0 && ELEMENTS_NUMBER > 0) 
    {
        if (elements==nullptr) elements=new Profile[ELEMENTS_NUMBER];
        elements[0]=newElement;
        elementCount++;
        return true;
    }

    if (elementCount<ELEMENTS_NUMBER) 
    {
        elements[elementCount]=newElement;
        elementCount++;
        return true;
    }
    return false;

}  // end insert


// Description: Search for target element. 
//              Returns a pointer to the element if found,
//              otherwise, returns nullptr.

Profile* MyADT::search(const Profile& target) {

    Profile * targetPtr=nullptr;
    if (elementCount == 0)
    {
        return nullptr;
    }
    //linear search in a col of the "1-D" array
    else
    {
        bool done=false;
        unsigned int count=0;
        while (!done || count<elementCount)
        {
            if (elements[count]==target)
            {
                targetPtr=&elements[count];
                done=true;
            }
            count++;
        }
    }
    // in case that the target cant be found
    return targetPtr; // it should be a nullptr 
}  // end of search

// Description: Remove an element. 
// Postcondition: toBeRemoved is removed and the appropriate elementCount has been decremented.
//                Returns "true" when the removal is successfull,
//                otherwise "false".
bool MyADT::remove(const Profile& toBeRemoved) {

    Profile * removePtr=search(toBeRemoved);
    if (removePtr==nullptr) return false;
    //Otherwise find and remove the element
    unsigned int index=0;
    for (unsigned int i=0;i<elementCount;i++)
    {
        if (elements[i]==toBeRemoved)
        {
            index=i;
        }
        break;
    }
    for (unsigned int j=index;j<elementCount-1;j++)
    {
        elements[j]=elements[j+1];
    }
    elementCount--;
    return true;

}  // end remove

// Description: Remove all elements.
// Postcondition: MyADT goes back to its initialization state.
void MyADT::removeAll() {

    delete[] elements;
    elements=nullptr;
    elementCount=0;

}  // end removeAll


// Description: Prints all elements stored in MyADT by ascending order of search key.
// ***For Testing Purposes - Conceptualy, it is not part of this class.***

void MyADT::print() {
    cout<<"The number of SAs: "<<ELEMENTS_NUMBER<<endl;
    cout<<"Total money collected: $"<<moneyTotal<<endl;
    cout<<"Total hours: "<<hoursTotal<<" hours"<<endl;
    cout<<"Hour rate is: $"<<hourRate<<"/hour"<<endl;
    for (unsigned int i=0; i<elementCount;i++)
    {
        cout<<elements[i];
    }
}


void MyADT::calculate() 
{
    hoursTotal=getHoursTotal();
    hourRate=moneyTotal/hoursTotal;
    for (unsigned int i=0;i<elementCount;i++)
    {
        elements[i].setMoney(hourRate*elements[i].getHour());
    }
}



//  End of implementation file