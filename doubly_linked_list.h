// import linked_list class 
#include"linked_list.h"

// doubly linked list inherited from linkedlist
class DoubleLinkedList : public LinkedList
{
private:
    /* data */
public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    void add_to_list(int value); // overrite the add to list function.
    void add_at_start(int value); // overrides add at start function 
    void add_to_position(int pos, int value); // overrides add to position function
    void reverse_print();
    void delete_at_start(); // over rides delete at start function of ll
    void delete_at_position(int pos); // overrides delete at position method of LL.
};
