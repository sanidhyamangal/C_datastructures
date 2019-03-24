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

// override delete at start fuction 
void DoubleLinkedList::delete_at_start(){
    LinkedList::delete_start_element();
    this->head->prev = NULL;
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