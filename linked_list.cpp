#include "linked_list.h"
#include<iostream>

using namespace std;

LinkedList::LinkedList(/* args */)
{
    // initalize the value of head node to null 
    this->head = new Node(); // assign a new space

    this->head = NULL; // null value to head
}

LinkedList::~LinkedList()
{
    cout<<"\nDestructor invoked";
}

void LinkedList :: create_list(int value){
    // inital values to be declared
    Node *temp = new Node();
    
    // assign values to temp variables
    temp->data = value;
    temp->next = NULL;
    temp->prev = NULL;
    
    // assign the value of temp node to head node 
    this->head = temp;
}
