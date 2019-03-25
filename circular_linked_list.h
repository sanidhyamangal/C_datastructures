// added header guards
#ifndef __CIRCULAR_LINKEDLIST__
#define __CIRCULAR_LINKEDLIST__

#include "linked_list.h"

class CircularLinkedList: public LinkedList
{
private:
    /* data */
public:
    CircularLinkedList(/* args */);
    ~CircularLinkedList();
    void create_inital_node(int value); // override the base function
    void print_list(); // override the base function.
};

#endif