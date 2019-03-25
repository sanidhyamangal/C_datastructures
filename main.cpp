#include<iostream>
using namespace std;
// #include "linked_list.h"

#include "doubly_linked_list.h"
int main(){
    LinkedList ll;
    ll.add_to_list(20);
    ll.add_to_list(15);
    // ll.add_to_list(5);
    ll.add_to_position(1, 10);
    // cout<<ll.countNodes();
    // ll.delete_at_position(1);
    // ll.delete_end_element();
    // ll.update_element(1, 5);
    ll.print_list();

    // DoubleLinkedList dl;
    // dl.add_to_list(36);
    // dl.add_to_list(3);
    // dl.add_to_list(6);
    // // dl.delete_at_start();
    // // dl.print_list();
    // // dl.delete_end_element();
    // // cout<<endl;
    // // dl.print_list();
    // dl.delete_at_position(1);
    // cout<<endl;
    // dl.reverse_print();
    // Node *test = dl.traverse_to_position(0);
    // cout<<test->data;
    return 0;
}