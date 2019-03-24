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
// delete start element 
void LinkedList::delete_start_element(){
    // check wether more than one notes are present or not 
    if (countNodes() != 0){
        this->head = this->head->next;
    }else{
        // print error message 
        cout<<"No elements present to delete";
    }
}

// delete a node from the end of the function 
void LinkedList::delete_end_element(){
    // check wether more than one node is present or not 
    if (countNodes() != 0){
        // initialize some new temp variables 
        Node *elements = this->head, *temp;

        // traverse all the elements in the list
        while(elements->next != NULL){
            temp = elements;
            elements = elements->next;
        }
        // delete the element in the last 
        temp->next = NULL;
        cout<<"Deleted element is "<<temp->data;
    }else{
        cout<<"There are no items in the list to be deleted";
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
    if (this->head == NULL){
        return 0;
    }else{

        while(countNodes->next != NULL){
            count++; // increase the counter
            countNodes = countNodes->next; // update the list 
        }
        return count + 1;
    }
    // return count > 0 ? count+1 : 0; // return the count value of the nodes. 
}