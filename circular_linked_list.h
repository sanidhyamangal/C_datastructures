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
    void add_to_list(int value); // function to add at end in circular LL.
    int countNodes(); // override the count nodes method
    void update_element(int pos, int vlaue);
    Node *traverse_to_position(int pos);
};

#endif