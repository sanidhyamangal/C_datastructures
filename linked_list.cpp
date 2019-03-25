#include "linked_list.h"
#include<iostream>

using namespace std;

LinkedList::LinkedList(/* args */)
{
    // initalize the value of head node to null 
    this->head = new Node(); // assign a new space

    this->head = NULL; // null value to head
}

// delete the value of list on calling a destructor.
LinkedList::~LinkedList()
{
    this->head = NULL;
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

void LinkedList::add_to_list(int value){
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

// add node at starting position 
void LinkedList::add_at_start(int value){
    Node *temp = new Node();

    temp->data = value;
    temp->next = this->head;

    this->head = temp;
}

// add node at specific position 
void LinkedList::add_to_position(int pos, int value){
    // if at inital postion 
    if(pos == 0){
        add_at_start(value);
    }
    // if postion if last 
    else if (pos == countNodes()){
        add_to_list(value); // call add to list value;
    } 
    // if position in between 0 and num of nodes.
    else if (pos > 0 && pos < countNodes()) {
        // initializing some important nodes. 
        Node *add_prev, *add_next;

        Node *temp = new Node(); // memory alloc for the tempnode. 
        
        //  traversing to previous and next position.
        add_prev = traverse_to_position(pos-1);
        add_next = traverse_to_position(pos);
        
        // assign the value to temp node
        temp->data = value; 
        add_prev->next = temp; // pointing next of prev node to temp.
        temp->next = add_next; // pointing next of temp node to node at current pos.
    }
}

// update a function 
void LinkedList::update_element(int pos, int value){
    Node *temp = traverse_to_position(pos);

    // update value of the node at pos 
    temp->data = value;
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

// delete a node at specific position function 
void LinkedList::delete_at_position(int pos){

    // if position is 0 then calls delete_start_element function
    if (pos == 0) {
        delete_start_element();
    }
    // if position in between 0 and num of nodes
    else if (pos < countNodes() && pos > 0){
        // initialize some of the local variables
        Node *start, *temp;

        temp = traverse_to_position(pos-1); // iterate to pos-1 
        start = traverse_to_position(pos); // iterate to pos 
        temp->next = start->next; // delete the node in between
        cout<<"Deleted element is "<<start->data;
        free(start); 
    }
    // if node is the last element.
    else if (pos == countNodes()-1) {
        delete_end_element();
    } // if invalid position is given
    else{
        cout<<"The position is not avaiable in the list";
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
        cout<<"Deleted element is "<<elements->data;
        free(elements); // removes element from the list
    }else{
        cout<<"There are no items in the list to be deleted";
    }
}

// function to traverse at a specific position 
Node *LinkedList::traverse_to_position(int pos){
    Node *temp = this->head;
    if(pos >= 0 && pos < countNodes()){
        for (int i =0; i < pos ; i++){
            temp = temp->next;
        }
        return temp;
    }
    return 0;
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
}