// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    head = new Node(); 
    Node* nCurrent = head; 
    Node* oCurrent = source.head; 
    while(oCurrent != nullptr) {
        nCurrent->info = oCurrent->info; 
        nCurrent->next = new Node(); 
        oCurrent = oCurrent->next; 
        nCurrent = nCurrent->next; 
    }
    tail = nCurrent; 
    nCurrent = head; 
    head = head->next; 
    delete nCurrent; 
}

// destructor deletes all nodes
IntList::~IntList() {
    Node* clone = head; 
    while(clone != nullptr) {
        head = head->next;
        delete clone; 
        clone = head;
    }
}


// return sum of values in list
int IntList::sum() const {
    int sum = 0; 
    Node* current = head; 
    while(current!=nullptr) {
       sum+=current->info;
       current = current->next; 
    }
    return sum; 
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    bool contains = false; 
    Node* current = head; 
    while(current!=nullptr) {
       if(current->info == value) {
            contains = true;
       }
       current = current->next; 
    }
    return contains;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if(head == nullptr) {
        return 0; 
    }
    Node* current = head; 
    int max = current->info; 
    while(current!=nullptr) {
       if(current->info > max) {
            max = current->info;
       }
       current = current->next; 
    }
    return max; 
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if(head == nullptr) {
        return 0; 
    }
    double average = (double) sum() / (double) count(); 
    return average; 
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    if(head == nullptr) {
        Node* newNode = new Node(); 
        newNode->info = value; 
        head = newNode;
        tail = newNode; 
    } else {
        Node* newNode = new Node(); 
        newNode->info = value; 
        newNode->next = head; 
        head = newNode;
    }
}

// append value at end of list
void IntList::push_back(int value) {
    if(tail == nullptr) {
        Node* newNode = new Node(); 
        newNode->info = value;  
        tail = newNode;
        head = newNode; 
    } else {
        Node* newNode = new Node(); 
        newNode->info = value; 
        tail->next = newNode; 
        tail = newNode; 
    }
}

// return count of values
int IntList::count() const {
    Node* current = head; 
    int sum = 0;
    while(current!=nullptr) {
       sum++; 
       current = current->next; 
    }
    return sum;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if(head != source.head) {
        Node* clone = head; 
        while(clone != nullptr) {
            head = head->next;
            delete clone; 
            clone = head;
        }
    }
    if(source.head==nullptr){
        head = nullptr; 
        tail = nullptr; 
        return *this; 
    }
    head = new Node();
    Node* nCurrent = head; 
    Node* oCurrent = source.head; 
    while(oCurrent != nullptr) {
        nCurrent->info = oCurrent->info; 
        nCurrent->next = new Node(); 
        oCurrent = oCurrent->next; 
        nCurrent = nCurrent->next; 
    }
    tail = nCurrent; 
    tail->next = nullptr;
    return *this;
}

// constructor sets up empty list
IntList::IntList(){ 
    head = nullptr;
    tail = head; 
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

