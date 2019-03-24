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
}

void LinkedList :: create_inital_node(int value){
    // inital values to be declared
    Node *temp;
    temp = new Node();
    
    // assign values to temp variables
    temp->data = value;
    temp->next = NULL;
    temp->prev = NULL;
    
    // assign the value of temp node to head node 
    this->head = temp;
}

void LinkedList::add_to_single_list(int value){
    // create a inital node 
    if (this->head == NULL){
        create_inital_node(value);
    }
    else{
        // intial values for the node 
        Node *temp = new Node();
        Node *s = this->head;

        // assign the values of temp 
        temp->data = value;
        temp->next = NULL;
        // loop to traverse to last empty state
        while(s->next != NULL){
            // update condition for the loop
            s = s->next;
        }
        // assign the value of temp to next node
        s->next = temp;
    }
}

void LinkedList::print_list(){
    // initialize print instance of the node.
    Node *print = this->head;

    // traverse all the nodes 
    while(print->next != NULL){
        // print all the available nodes.
        cout<<"The value of node is "<<print->data<<endl;
        print = print->next;
    }
    // print the last traversed node.
    cout<<"The value of node is "<<print->data<<endl;
}

// function to count nodes in the linkedlist 
int LinkedList::countNodes(){
    
    // initalize a counter 
    int count = 0;

    // create an alias for the linked list
    Node *countNodes = this->head;

    // loop in all the nodes of list till end
    while(countNodes->next != NULL){
        count++; // increase the counter
        countNodes = countNodes->next; // update the list 
    }
    return count +1; // return th value of the nodes. 
}