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
    // this->head = NULL;
}

void LinkedList :: create_list(int value){
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

void LinkedList::single_list(int value){
    // intializing a temp node for the functions 
    // create a inital node 
    if (this->head == NULL){
        create_list(value);
    }
    else{
        Node *temp = new Node();
        Node *s = this->head;

        // assign the values of temp 
        temp->data = value;
        temp->next = NULL;
        
        cout<<this->head->next;
        // cout<<s->next<<endl;
        while(s->next != NULL){
            // cout<<s->next<<endl;
            s = s->next;
        }
        s->next = temp;
        // cout<<"Value of s in loop "<<s;
    }
    
}

void LinkedList::print_list(){
    Node *print;
    print = this->head;

    while(print->next != NULL){
        cout<<"The value of node is "<<print->data<<endl;
        print = print->next;
    }
    cout<<"The value of node is "<<print->data<<endl;
}