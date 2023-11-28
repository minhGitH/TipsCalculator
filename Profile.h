/*
 * Profile.h
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

#ifndef PROFILE_H
#define PROFILE_H

#include <string>

using std::string;
using std::ostream;


class Profile {
    
/* You cannot change this file, i.e., the definition of this Profile class. */
     
private:

    string userName;
    double hour; 
    double money;

    // Description: Sets the profile's userName - Private method
    // Reflection: Why is this method not part of the public interface?
    void setUserName(const string aUserName);
    
    
public:

    // Default Constructor
    // Description: Create a profile. 
    // Postcondition: userName, name, email and birthday set to "TBD".        
    Profile();

    // Parameterized Constructor
    // Description: Create a profile with the given userName.
    // Postcondition: If userName starts with a letter, then it is set to this given string.
    //                Otherwise, it is set to "TBD".
    //                All other member attributes are set to "TBD".
    Profile(string aUserName);
    
    // Parameterized Constructor
    // Description: Create a member with the given userName, name, email and birthday.
    // Postcondition: If aUserName is not valid, then it set to "TBD".
    Profile(string aUserName, double hour);


    // Getters and setters
    
    // Description: Returns profile's userName.
    string getUserName() const;
    
    // Description: Returns profile's hours worked.
    double getHour() const;

    // Description: Returns profile's money.
    double getMoney() const;

    // Description: Sets profile's hour worked.
    // Postcondition: hour is set to hourWorked. No need to validate hour worked.
    void setHour(const double hourWorked);

    // Description: Sets the profile's money.    
    // Postcondition: money is set to moneyMade. No need to validate moneyMade.
    void setMoney(const double moneyMade);


    // Overloaded Operators
    // Description: Comparison (equality) operator. Compares "this" Profile object with "rhs" Profile object.
    //              Returns true if both Profile objects have the same userName.
    bool operator==(const Profile & rhs);

    // Description: Greater than operator. Compares "this" Profile object with "rhs" Profile object.
    //              Returns true if the userName of "this" Profile object is > the userName of "rhs" 
    //              Profile object, i.e., the userName of "this" Profile object goes after 
    //              the userName of "rhs" Profile object when ordered in ascending alpha order.
    bool operator > (const Profile & rhs);

    // Description: Lesser than operator. Compares "this" Profile object with "rhs" Profile object.
    //              Returns true if the userName of "this" Profile object is < the userName of "rhs" 
    //              Profile object, i.e., the userName of "this" Profile object goes before 
    //              the userName of "rhs" Profile object when ordered in ascending alpha order.
    bool operator < (const Profile & rhs);

    
    // Description: Prints the content of "this" as follows:
    //              <userName>, <name>, <email>, born on <birthday>
    friend ostream & operator<<(ostream & os, const Profile & p);

};
// end of Profile.h
#endif
