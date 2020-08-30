// Blinn College : COSC 2436 Fall 2020
// Lab01 - add described functionality to testLinkedList
// sample input : 22 34 56 2 89 90 0 14 56 11 43 55 -999

//Edited by Edward Cruz on 8/28/2020.

#include <iostream>

#include "unorderedLinkedList.h"

using namespace std;

int main() {
    unorderedLinkedList<int> list;

    int num;

    cout << "Enter numbers ending with -999" << endl;
    cin >> num;

    while (num != -999) {
        list.insertLast(num);
        cin >> num;
    }

    cout << endl;

    cout << "List: ";
    list.print();
    cout << endl;
    cout << "Length of the list: " << list.length() << endl;

    cout << "Enter all occurrences the number to be deleted: ";
    cin >> num;
    cout << endl;

    // lab01 - make all of the following test work correctly
    list.deleteAll(num);

    cout << "List after deleting all occurrences of " << num << endl;

    list.print();
    cout << endl;
    cout << "Length of the list: " << list.length() << endl;

    list.deleteSmallest();
    cout << "List after deleting the smallest element" << endl;

    list.print();
    cout << endl;
    cout << "Length of the list: " << list.length() << endl;

    /*int k;

    cout << "Enter the position of the item to be retrieved: " << endl;
    cin >> k;
    cout << endl;

    int temp = list.getKThElement(k);

    cout << "Item at position " << k << " = " << temp << endl;

    cout << "Enter the position of the item to be removed: " << endl;
    cin >> k;
    cout << endl;

    list.deteteKthElement(k);

    cout << "List after removing the element at position " << k << "." << endl;
    list.print();
    cout << endl;*/

    return 0;
}

// // This program tests various operation of a linked list
// // 34 62 21 90 66 53 88 24 10 -999

// #include <iostream>

// #include "unorderedLinkedList.h"

// using namespace std;

// int main() {
//     unorderedLinkedList<int> list1, list2;  // Line 1
//     int num;                                // Line 2

//     cout << "Line 3: Enter integers ending "
//          << "with -999" << endl;  // Line 3
//     cin >> num;                   // Line 4

//     while (num != -999)  // Line 5
//     {
//         list1.insertLast(num);  // Line 6
//         cin >> num;             // Line 7
//     }

//     cout << endl;  // Line 8

//     cout << "Line 9: list1: ";                                       // Line
//     9 list1.print();                                                   //
//     Line 10 cout << endl; // Line 11 cout << "Line 12: Length of list1: " <<
//     list1.length() << endl;  // Line 12

//     list2 = list1;  // test the assignment operator Line 13

//     cout << "Line 16: list2: ";                                      // Line
//     14 list2.print();                                                   //
//     Line 15 cout << endl; // Line 16 cout << "Line 17: Length of list2: " <<
//     list2.length() << endl;  // Line 17

//     cout << "Line 18: Enter the number to be "
//          << "deleted: ";  // Line 18
//     cin >> num;           // Line 19
//     cout << endl;         // Line 20

//     list2.deleteNode(num);  // Line 21

//     cout << "Line 22: After deleting " << num << " list2: " << endl;  // Line
//     22 list2.print();                                                    //
//     Line 23 cout << endl; // Line 24

//     cout << "Line 25: Length of list2: " << list2.length() << endl;  // Line
//     25

//     cout << endl
//          << "Line 26: Output list1 "
//          << "using an iterator" << endl;  // LIne 26

//     linkedListIterator<int> it;  // Line 27

//     for (it = list1.begin(); it != list1.end(); ++it)  // Line 28
//         cout << *it << " ";                            // Line 29
//     cout << endl;                                      // Line 30

//     return 0;
// }
