// // // main.cpp

// #include <iostream>
// #include "MyADT.h"
// #include "Profile.h"

// int main() {
//     // Test MyADT default constructor
//     MyADT myADT;
//     std::cout << "Element Count: " << myADT.getElementCount() << std::endl;
//     std::cout << "Hours Total: " << myADT.getHoursTotal() << std::endl;
//     std::cout << "Money Total: " << myADT.getMoneyTotal() << std::endl;

//     // Test Profile default constructor
//     Profile profile1;
//     std::cout << "Profile 1: " << profile1 << std::endl;

//     // Test insertion
//     Profile profile2("JohnDoe", 20.5);
//     Profile profile3("JaneDoe", 30.0);
//     Profile profile4("BobSmith", 15.5);
//     Profile profile5("AliceJohnson", 25.0);

//     myADT.setElements_number(3);
//     std::cout << "Current Element Number: " << myADT.getElementsNumber()<< std::endl;

//     myADT.insert(profile2);
//     myADT.insert(profile3);
//     myADT.insert(profile4);
//     myADT.insert(profile5);

//     std::cout << "After Insertion:" << std::endl;
//     myADT.print();

//     // Test search
//     Profile searchTarget("JaneDoe");
//     Profile* searchResult = myADT.search(searchTarget);
//     if (searchResult != nullptr) {
//         std::cout << "Search Result: " << *searchResult << std::endl;
//     } else {
//         std::cout << "Profile not found." << std::endl;
//     }

//     // Test removal
//     Profile toBeRemoved("JohnDoe");
//     bool removalResult = myADT.remove(toBeRemoved);
//     std::cout << "Removal Result: " << (removalResult ? "Success" : "Failed") << std::endl;

//     std::cout << "After Removal:" << std::endl;
//     myADT.print();
//     myADT.setElements_number(6);
//     std::cout << "Current Element Number: " << myADT.getElementsNumber()<< std::endl;


//     // Test inserting more profiles after remove all
//     myADT.insert(Profile("NewUser1", 10.0));
//     myADT.insert(Profile("NewUser2", 15.0));

//     std::cout << "After Insertion (Again):" << myADT.getElementCount() <<std::endl;
//     myADT.print();

//     // Test remove all
//     myADT.removeAll();
//     std::cout << "After Remove All:" << std::endl;
//     myADT.print();

//     return 0;
// }

// // return as expected

// // Element Count: 0
// // Hours Total: 0
// // Money Total: 0
// // Profile 1: TBD, 0, 0.

// // Current Element Number: 3
// // After Insertion:
// // JohnDoe, 20.5, 0.
// // JaneDoe, 30, 0.
// // BobSmith, 15.5, 0.
// // Search Result: JaneDoe, 30, 0.

// // Removal Result: Success
// // After Removal:
// // JaneDoe, 30, 0.
// // BobSmith, 15.5, 0.
// // Current Element Number: 6
// // After Insertion (Again):4
// // JaneDoe, 30, 0.
// // BobSmith, 15.5, 0.
// // NewUser1, 10, 0.
// // NewUser2, 15, 0.
// // After Remove All: