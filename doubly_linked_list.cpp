#include<iostream> // std lib for io 
#include "doubly_linked_list.h" // header file for double linked list to handdle

using namespace std; // using a std namespace for current file

DoubleLinkedList::DoubleLinkedList(){
}

DoubleLinkedList::~DoubleLinkedList(){}

void DoubleLinkedList::add_to_list(int value){
    // check if it need to inital node or not. 
    if(this->head == NULL){
        create_inital_node(value);
    }else{
        // initialize the temp value and s value
        Node *temp = new Node(), *s=this->head;
        // assign values to the temp value
        temp->data = value;
        temp->next = NULL;
        
        // traverse till the end of the list 
        while(s->next !=NULL){
            s = s->next;
        }

        // assign previous node value to current node
        temp->prev = s;

        // finally add a new node at the between
        s->next = temp;
    }
}

// function to add at starting position of node. 
void DoubleLinkedList::add_at_start(int value){
    // initialize and allocate memory to temp node.
    Node *temp = new Node();

    // assign the values to temp node.
    temp->data = value;
    temp->next = this->head;
    temp->prev = NULL;

    // point prev of head to temp node.
    this->head->prev = temp;
    this->head = temp;
}

// method to add a node at specific postion.
void DoubleLinkedList::add_to_position(int pos, int value){
    // if pos is inital 
    if (pos == 0 ){
        add_at_start(value); // add at start postion function called.
    }
    // if last position supplied.
    else if (pos == countNodes())
    {
        add_to_list(value); // add to list method called.
    }
    // if pos b/w 0 and num of nodes
    else if (pos > 0 && pos < countNodes())
    {
        // initalize prev and current position nodes
        Node *add_prev_position, *add_position;
        Node *temp = new Node(); // initialize and alloc mem to temp node.
        // taverse these nodes at certian positon. 
        add_prev_position = traverse_to_position(pos -1); // traverse to prev position
        add_position = traverse_to_position(pos); // traverse to specified position

        // assign the values to temp function 
        temp->data = value;
        temp->next = add_position;
        temp->prev = add_prev_position;

        // add noed in main list
        add_prev_position->next = temp;
        add_position->prev = temp;
    }
    // if invalid range supplied.
    else
    {
        cout<<"Invalid node";
    }
    
}

// override delete at start fuction 
void DoubleLinkedList::delete_at_start(){
    LinkedList::delete_start_element();
    this->head->prev = NULL;
}

// override delete at position function for the doubly list 
void DoubleLinkedList::delete_at_position(int pos){
    // call delete at start if pos is 0
    if (pos == 0){
        delete_at_start(); // call delete start element;
    }
    // delete at end if pos is last node 
    else if (pos == countNodes() -1) {
        delete_end_element(); // call delete end element;
    }
    // if pos in between 0 and num of nodes 
    else if (pos > 0 && pos < countNodes()){
        Node *next, *prev; // to temp nodes
        prev = traverse_to_position(pos -1); // traverse prev to pos-1 node
        next = traverse_to_position(pos); // traverse next to pos node

        prev->next = next->next; // point next of prev to next of next.
        next->next->prev = prev; // point prev of next to next to prev node.

        cout<<"Deleted element is "<<next->data;
        free(next); // free the next node.
    }
    // do nothing if invalid range.
    else
    {
        cout<<"Invalid range";
    }
    
}

// function to print list in reversed order 
void DoubleLinkedList::reverse_print(){
    // move to last position
    Node *print = traverse_to_position(countNodes()-1);
    while(print->prev != NULL){
        cout<<"The value of node is "<<print->data<<endl;
        print = print->prev;
    }
    cout<<"The value of node is "<<print->data;
}