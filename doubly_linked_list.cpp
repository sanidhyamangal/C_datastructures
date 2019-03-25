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
        Node *temp = new Node(), *s;
        // assign values to the temp value
        temp->data = value;
        temp->next = NULL;
        
        // traverse till the end of the list 
        s = traverse_to_position(countNodes()-1);
        // assign previous node value to current node
        temp->prev = s;

        // finally add a new node at the between
        s->next = temp;
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