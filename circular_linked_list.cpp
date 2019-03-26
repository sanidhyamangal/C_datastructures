#include "circular_linked_list.h" // for linked list class 
#include <iostream> // for the input output stream 

using namespace std; // std namespace for all ops 
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

// print method for printing files 
void CircularLinkedList::print_list(){
    // intialize print pointer 
    Node *print = this->head;

    while(print->next != head){
        cout<<"The value of node is "<<print->data<<endl;
        print = print->next;
    }
    cout<<"The value of node is "<<print->data<<endl;  
}

// add to list function to push the node at end. 
void CircularLinkedList::add_to_list(int value){
    // check if no node is created
    if (this->head == NULL){
        create_inital_node(value);
    }else
    {
        // a node to point till last 
        Node *s = this->head;

        while(s->next != this->head){
            s = s->next;
        }
        
        // initalize the new node temp 
        Node *temp = new Node(); 
        temp->data = value;
        temp->next = this->head;

        // add node at last 
        s->next = temp;
    }
}

// method to traverse to a position 
Node *CircularLinkedList::traverse_to_position(int pos){
    // if position is between 0 and num of nodes
    if (pos < countNodes()){
        
        // create a temp node to be travsersed 
        Node *temp = this->head;
        for(int i = 0; i < pos; i++)
        {
            temp = temp->next;
        }
        cout<<temp->data;
        return temp;
    }
        return NULL;
}

// function to count number nodes in the list 
int CircularLinkedList::countNodes(){
    // if head equal to null 
    if (this->head == NULL){
        return 0;
    }else{
        // make a count node point at 
        Node *count = this->head;
        int _count = 0;
        // traverse till end.
        while(count->next != this->head){
            _count++; // increment count 
            count = count->next;
        }
        return _count +1;
    }
}