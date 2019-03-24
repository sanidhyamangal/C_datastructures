#include<iostream>
using namespace std;
#include "linked_list.h"

int main(){
    LinkedList ll;
    ll.single_list(20);
    ll.single_list(15);
    // ll.single_list(10);
    ll.print_list();
    return 0;
}