//Edited by Edward Cruz on 8/28/2020.

#ifndef H_UnorderedLinkedList
#define H_UnorderedLinkedList

#include "linkedList.h"

using namespace std;

template <class Type>
class unorderedLinkedList : public linkedListType<Type>
{
public:
    bool search(const Type &searchItem) const;
    //Function to determine whether searchItem is in the list.
    //Postcondition: Returns true if searchItem is in the
    //               list, otherwise the value false is
    //               returned.

    void insertFirst(const Type &newItem);
    //Function to insert newItem at the beginning of the list.
    //Postcondition: first points to the new list, newItem is
    //               inserted at the beginning of the list,
    //               last points to the last node in the
    //               list, and count is incremented by 1.

    void insertLast(const Type &newItem);
    //Function to insert newItem at the end of the list.
    //Postcondition: first points to the new list, newItem
    //               is inserted at the end of the list,
    //               last points to the last node in the
    //               list, and count is incremented by 1.

    void deleteNode(const Type &deleteItem);
    //Function to delete deleteItem from the list.
    //Postcondition: If found, the node containing
    //               deleteItem is deleted from the list.
    //               first points to the first node, last
    //               points to the last node of the updated
    //               list, and count is decremented by 1.

    void deleteAll(const Type &givenInfo);
    //to Find and delete all occurrences of a given info from the list.
    //Postcondition: after looping through the list once,
    //              every info that matches the given is 
    //              deleted from the list.

    void deleteSmallest();
    //To find and delete the smallest info within the list.
    //Postcondition: after going through the list, the 
    //              smallest node that was found and stored
    //              gets deleted from the list.
};

template <class Type>
bool unorderedLinkedList<Type>::search(const Type &searchItem) const {
    nodeType<Type> *current; //pointer to traverse the list
    bool found = false;

    current = this->first; //set current to point to the first
                           //node in the list

    while (current != nullptr && !found) //search the list
        if (current->info == searchItem) //searchItem is found
            found = true;
        else
            current = current->link; //make current point to
                                     //the next node
    return found;
}

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type &newItem) {
    nodeType<Type> *newNode; //pointer to create the new node

    newNode = new nodeType<Type>; //create the new node

    newNode->info = newItem; //store the new item in the node
    newNode->link = this->first;   //insert newNode before first
    this->first = newNode;         //make first point to the
                             //actual first node
    this->count++;                 //increment count

    if (this->last == nullptr) {  //if the list was empty, newNode is also the last node in the list
        this->last = newNode;
    }
}

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type &newItem) {
    nodeType<Type> *newNode;                //pointer to create the new node

    newNode = new nodeType<Type>;           //create the new node

    newNode->info = newItem;                //store the new item in the node
    newNode->link = nullptr;                //set the link field of newNode to nullptr

    if (this->first == nullptr) {           //if the list is empty, newNode is both the first and last node
        this->first = newNode;
        this->last = newNode;
        this->count++;                      //increment count
    } else {                                //the list is not empty, insert newNode after last
        this->last->link = newNode;         //insert newNode after last
        this->last = newNode;               //make last point to the actual last node in the list
        this->count++;                      //increment count
    }
}

template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type &deleteItem) {
    nodeType<Type> *current;                //pointer to traverse the list
    nodeType<Type> *trailCurrent;           //pointer just before current
    bool found;

    if (this->first == nullptr) {                 //Case 1; the list is empty.
        cout << "Cannot delete from an empty list." << endl;
    } else {
        if (this->first->info == deleteItem)      //Case 2
        {
            current = this->first;
            this->first = this->first->link;
            this->count--;
            if (this->first == nullptr) //the list has only one node
                this->last = nullptr;
            delete current;
        } else {                                //search the list for the node with the given info
            found = false;
            trailCurrent = this->first;         //set trailCurrent to point to the first node
            current = this->first->link;        //set current to point to the second node

            while (current != nullptr && !found) {
                if (current->info != deleteItem) {
                    trailCurrent = current;
                    current = current->link;
                } else {
                    found = true;
                }
            }

            if (found) {                        //Case 3; if found, delete the node
                trailCurrent->link = current->link;
                this->count--;

                if (this->last == current) {          //node to be deleted was the last node
                    this->last = trailCurrent;        //update the value of last
                }
                delete current;                 //delete the node from the list
            } else {
                cout << "The item to be deleted is not in " << "the list." << endl;
            }
        }
    }
}

template <class Type>
void unorderedLinkedList<Type>::deleteAll(const Type &givenInfo) {
    nodeType<Type> *current;                //pointer to traverse the list
    nodeType<Type> *trailCurrent;           //pointer just before current
    nodeType<Type> *toBeDeleted;            //pointer to be set as deleted
    bool found = false;

    if (this->first == nullptr) {                 //Case 1; the list is empty.
        cout << "Cannot delete from an empty list." << endl;
    } else {
        if (this->first->info == givenInfo)      //Case 2 (checks the first node)
        {
            current = this->first;
            this->first = this->first->link;
            this->count--;
            if (this->first == nullptr) { //the list has only one node
                this->last = nullptr;
            }
            toBeDeleted = current;
            delete toBeDeleted;
            found = true;
        }
        // continues through the rest of the list.
        trailCurrent = this->first;         //set trailCurrent to point to the first node
        current = this->first->link;        //set current to point to the second node

        while (current != nullptr) {
            if (current->info != givenInfo) {
                    trailCurrent = current;
                    current = current->link;
            } else {
                trailCurrent->link = current->link;
                this->count--;

                if (this->last == current) {          //node to be deleted was the last node
                    this->last = trailCurrent;        //update the value of last
                }
                    
                toBeDeleted = current;              //set node to be deleted
                    
                trailCurrent = current;             //move pointers along
                current = current->link;

                delete toBeDeleted;                 //delete the node from the list (was 'current')
                found = true;
            }
        }
        if (!found) {
            cout << "The item to be deleted is not in " << "the list." << endl;
        }
    }
}

template <class Type>
void unorderedLinkedList<Type>::deleteSmallest() {
    nodeType<Type> *current;                //pointer to traverse the list
    nodeType<Type> *trailCurrent;           //pointer just before current
    nodeType<Type> *smallest;
    nodeType<Type> *saveCurrent;
    nodeType<Type> *saveTrailCurrent;

    if (this->first == nullptr) {                 //Case 1; the list is empty.
        cout << "Cannot delete from an empty list." << endl;
    } else {
        trailCurrent = this->first;         //set trailCurrent to point to the first node
        current = this->first->link;        //set current to point to the second node

        smallest = trailCurrent;

        while (current != nullptr) {
            if (current->info < smallest->info) {
                smallest = current;                 //saves the new smallest node.
                saveCurrent = current;              //saves the place location... 
                saveTrailCurrent = trailCurrent;    //of where the node is
            }
            trailCurrent = current;             //move pointers along
            current = current->link;
        }  

        saveTrailCurrent->link = saveCurrent->link; 
        this->count--;
        if (this->last == saveCurrent) {          //node to be deleted was the last node
            this->last = saveTrailCurrent;        //update the value of last
        }
        delete smallest;                          //delete the node from the list
    }
}

#endif