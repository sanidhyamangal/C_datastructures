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
    void reverse_print();
    void delete_at_start();
    void delete_at_position(int pos);
};
