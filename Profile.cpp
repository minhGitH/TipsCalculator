/*
 * Profile.cpp
 * 
 * Class Description: Models the profile of a user of the social network FriendsBook.
 *                    This profile contains the following characteristics:
 *                    userName, name (first and last name), email address and birthday.
 *       
 * Class Invariant: The "userName" of a user is a valid string (it is not an empty string)
 *                  and it starts with a letter (a to z or A to Z). 
 *                  This is to say that "userName" can be used as a unique identifier (i.e. a search key).
 *
 * Author: AL
 * Last modified: Oct. 2023
 */

#include <iostream>
#include <string>
#include <locale>         // std::locale, std::isalpha
#include "Profile.h"

using std::cout;
using std::endl;
using std::locale;
using std::ostream;


// Default Constructor
// Description: Create a profile. 
// Postcondition: userName, name, email and birthday set to "TBD".        
Profile::Profile() : userName("TBD"), hour(0), money(0) {

   //cout << "Profile::default constructor" << endl;   // For testing purposes ... and curiosity
               
}

// Parameterized Constructor
// Description: Create a profile with the given userName.
// Postcondition: If userName starts with a letter, then it is set to this given string.
//                Otherwise, it is set to "TBD".
//                All other member attributes are set to "TBD".           
Profile::Profile(string aUserName) : hour(0), money(0) {

    this->setUserName(aUserName); 
               
}

// Parameterized Constructor
// Description: Create a member with the given userName, name, email and birthday.
// Postcondition: If aUserName is not valid, then it set to "TBD".
Profile::Profile(string aUserName, double hourWorked) : 
                 hour(hourWorked) {
    this->setMoney(0);
    this->setUserName(aUserName);                 
}    
    
// Getters and setters
// Description: Returns profile's userName.
string Profile::getUserName() const {
    return userName;
}

// Description: Returns profile's hour.
double Profile::getHour() const {
    return hour;
}

// Description: Returns profile's birthday.
double Profile::getMoney() const {
    return money;
}

// Description: Sets the profile's userName.
// Postcondition: userName is set to aUserName if aUserName 
//                is valid, otherwise it is set to "TBD".
void Profile::setUserName(const string aUserName) {
    locale loc;
    if ( !aUserName.empty() && (isalpha(aUserName[0], loc) ) )
        userName.assign(aUserName);
    else
        userName.assign("TBD");                   
}

// Description: Sets the profile's hour.
// Postcondition: hour is set to hourWorked. No need to validate hourWorked.
void Profile::setHour(const double hourWorked) {
    this->hour=hourWorked;
}

// Description: Sets the profile's money.
// Postcondition: money is set to moneyMade. No need to validate moneyMade.
void Profile::setMoney(const double moneyMade) {
    this->money=moneyMade;
}

// Overloaded Operators
// Description: Comparison (equality) operator. Compares "this" Profile object with "rhs" Profile object.
//              Returns true if both Profile objects have the same userName.
bool Profile::operator==(const Profile & rhs) {
    
    // Compare both Profile objects
    return ( this->userName == rhs.getUserName() ); 

} // end of operator==


// Description: Greater than operator. Compares "this" Profile object with "rhs" Profile object.
//              Returns true if the userName of "this" Profile object is > the userName of "rhs" 
//              Profile object, i.e., the userName of "this" Profile object goes after 
//              the userName of "rhs" Profile object when ordered in ascending alpha order.
bool Profile::operator > (const Profile & rhs) {

   return ( this->userName > rhs.getUserName() ); 
} 

// Description: Lesser than operator. Compares "this" Profile object with "rhs" Profile object.
//              Returns true if the userName of "this" Profile object is < the userName of "rhs" 
//              Profile object, i.e., the userName of "this" Profile object goes before 
//              the userName of "rhs" Profile object when ordered in ascending alpha order.
bool Profile::operator < (const Profile & rhs) {
    
   return ( this->userName < rhs.getUserName() ); 
} 


// Description: Prints the content of "this" as follows:
//              <userName>, <name>, <email>, born on <birthday>
ostream & operator<<(ostream & os, const Profile & p) {

    os <<"Name: "<<p.userName << ", " << p.hour << " hours, $" << p.money <<endl;    
    return os;
    
} // end of operator<<

// end of Profile.cpp
