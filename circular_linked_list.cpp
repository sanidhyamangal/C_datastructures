#include "circular_linked_list.h" // for linked list class 
#include <iostream> // for the input output stream 

CircularLinkedList::CircularLinkedList(/* args */)
{
}

CircularLinkedList::~CircularLinkedList()
{
}

void CircularLinkedList::create_inital_node(int value){
    // initialize temp node for the memory 
    Node *temp = new Node(); 

    // assign the value to node 
    temp->data = value;
    temp->next = temp;

    // add this node to head node 
    this->head = temp;
}
