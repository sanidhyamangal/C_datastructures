#include<iostream>
using namespace std;
#include "linked_list.h"

int main(){
    LinkedList ll;
    ll.add_to_single_list(20);
    ll.add_to_single_list(15);
    // ll.single_list(10);
    cout<<ll.countNodes();
    ll.delete_end_element();
    cout<<ll.countNodes();
    return 0;
}