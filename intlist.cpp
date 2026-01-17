// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    head=nullptr;
    if(source.head==nullptr)
        return;
    head=new Node;
    head->info=source.head->info;
    head->next=nullptr;
    
    Node *S=source.head->next;
    Node *D=head;
    while (S!= nullptr){
        Node *N=new Node;
        N->info=S->info;
        N->next=nullptr;
        D->next=N;
        D=D->next;
        S=S->next;
    }
}

// destructor deletes all nodes
IntList::~IntList() {
     Node* cur = head;
    while (cur != nullptr) {
        Node* nextNode = cur->next;
        delete cur;
        cur = nextNode;
    }
    head = nullptr;
}


// return sum of values in list
int IntList::sum() const {
   int sum=0;
   Node *n= head;
   while(n != nullptr){
       sum=sum+n->info;
       n=n->next;
}
   return sum;
}
// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
   Node *n=head;
    while(n!=nullptr){
        if(n->info==value)
            return true;
        else
            n=n->next;
}
   return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
   Node *n =head;
    if (n==nullptr)
        return 0;
    int max=n->info;
    while(n!=nullptr)
        {
            if(n->info > max)
                max=n->info;
            n=n->next;
        }
    return max;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if (count()==0)
        return 0.0
    return (double)sum()/count();
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node *n=head;
    Node *m= new Node;
    m->info=value;
    head=m;
    m->next=n;
}

// append value at end of list
void IntList::push_back(int value) {
    Node *n=new Node;
    n->info=value;
    n->next=nullptr;
    Node *t=head;
    if (head == nullptr) {
    head = n;
    return;
    }
    while (t->next != nullptr){
        t=t->next;
    }
    t->next=n;
}

// return count of values
int IntList::count() const {
  Node *n=head;
    int count=0;
    while (n!= nullptr){
        count=count+1;
        n=n->next;
    }
     return count;   
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
 if (this == &source) {
        return *this;
    }
    Node* cur = head;
    while (cur != nullptr) {
        Node* nextNode = cur->next;
        delete cur;
        cur = nextNode;
    }
    head = nullptr;

    if (source.head == nullptr) {
        return *this;
    }


    head = new Node;
    head->info = source.head->info;
    head->next = nullptr;


    Node* dest = head;
    Node* src = source.head->next;

    while (src != nullptr) {
        dest->next = new Node;
        dest = dest->next;

        dest->info = src->info;
        dest->next = nullptr;

        src = src->next;
    }

    return *this;
}

// constructor sets up empty list
IntList::IntList(){ 
  head=nullptr;
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

