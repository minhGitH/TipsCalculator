/*
 * MyADT.h
 * 
 * Class Description: A linear data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - This is an unsorted data collection because it is not 
that many Profiles.
 *                   - Its data structure is not expandable, i.e., resizable. 
 *
 * Author: AL
 * Last modified on: Sept. 2023
 */
 
 
#ifndef MyADT_H
#define MyADT_H

/*
 * You can add more #include statements.
 */
 
#include <string>
#include "Profile.h"


class MyADT {

private:

/* 
 * You can add more attributes to this class, 
 * but you cannot remove/change the attributes below.
 */
 
    unsigned int ELEMENTS_NUMBER;
    Profile * elements;                
    unsigned int elementCount;         
    double hoursTotal;
    double moneyTotal;
    double hourRate;
  
public:

/* 
 * You cannot remove/change the public methods below.
 * Bottom line: you cannot change the ***public interface*** of this class. 
 */
    // Default constructor
    MyADT();

    // Copy constructor
    MyADT(const MyADT& rhs);
    
    // Destructor
    // Description: Destruct this object, releasing heap-allocated memory.
    ~MyADT();

    // Description: Returns the total element count currently stored in MyADT object.
    unsigned int getElementCount() const;

    double getHoursTotal() const;

    double getMoneyTotal() const;

    unsigned int getElementsNumber() const;

    // Description: Set the ELEMENTS_NUMBER to aNumber.
    void setElements_number(const unsigned int aNumber);

    void setMoneyTotal(double aNumber);

    void setHourRate(double aNumber);

    // Description: Inserts an element.
    // Precondition: newElement must not already be in data collection.  
    // Postcondition: newElement inserted and the appropriate elementCount has been incremented.
    //                Returns "true" when the insertion is successfull,
    //                otherwise "false".
    bool insert(const Profile& newElement);

    // Description: Remove an element. 
    // Postcondition: toBeRemoved (if found) is removed and the appropriate elementCount is decremented.
    //                Returns "true" when the removal is successfull,
    //                otherwise "false".    
    bool remove(const Profile& toBeRemoved);
    
    // Description: Remove all elements.
	// Postcondition: MyADT goes back to its initialization state.
    void removeAll();
   
    // Description: Search for target element.
    //              Returns a pointer to the element if found,
    //              otherwise, returns nullptr.
    Profile* search(const Profile& target);
    
    // Description: Prints all elements stored in MyADT by ascending order of search key.
    // ***For Testing Purposes - Conceptualy, it is not part of this class.***
    void print();

    void calculate();

}; // end MyADT


#endif