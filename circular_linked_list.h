#include "linked_list.h"

class CircularLinkedList: public LinkedList
{
private:
    /* data */
public:
    CircularLinkedList(/* args */);
    ~CircularLinkedList();
    void create_inital_node(int value); // override the base function
};