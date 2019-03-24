struct Node
{
    int data; 
    Node *next;
    Node *prev;
};

class LinkedList
{
private:
    Node *head;
public:
    LinkedList();
    ~LinkedList();
    void create_inital_node(int value);
    void add_to_single_list(int value);
    void delete_start_element();
    void delete_end_element();
    void print_list();
    int countNodes();
};
