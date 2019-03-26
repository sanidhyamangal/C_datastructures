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

// override delete at start method.
void CircularLinkedList::delete_start_element(){
    // if non zero nodes
    if (countNodes() > 0){
    // init a node and point it to last node 
    Node *last = traverse_to_position(countNodes() -1);

    // point last node to next of head 
    this->head = this->head->next;
    last->next = this->head;
    }
}

// delete element at last 
void CircularLinkedList::delete_at_end(){
    // if cout of nodes is non zero 
    if (countNodes() > 0){
        // init a node and traverse it to last second node 
        Node *last_second = traverse_to_position(countNodes()-2);

        // free last node 
        free(last_second->next);

        // point last second node to head node.
        last_second->next = this->head;
    }
}

// delete at position method implementation
void CircularLinkedList:: delete_at_position(int pos){
    // if zero position
    if(pos == 0){
        delete_start_element();
    }
    // if last postion given 
    else if (pos == countNodes()-1)
    {
        delete_at_end();
    }
    // if pos in range of 0 and num of nodes. 
    else if (pos > 0 and pos < countNodes())
    {
        // create an instance of the head list and traverse to given pos. 
        Node *prev = traverse_to_position(pos -1); // pos -1 
        Node *next = traverse_to_position(pos); // pos.

        // skip the next node.
        prev->next = next->next;

        // free the next node.
        free(next);
    }
    
    
}

// method to update element
void CircularLinkedList::update_element(int pos, int value){
    // if postion is in range 
    if (pos >= 0 and pos < countNodes()){
        // Init a node and traverse it to pos
        Node *position = traverse_to_position(pos);

        // assign the value to this node.
        position->data = value;
    }
}

// method to traverse to a position 
Node *CircularLinkedList::traverse_to_position(int pos){
    // if position is between 0 and num of nodes
    if (pos < countNodes() and pos >= 0){
        
        // create a temp node to be travsersed 
        Node *temp = this->head;
        for(int i = 0; i < pos; i++)
        {
            temp = temp->next;
        }
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