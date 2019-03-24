struct Node
{
    int data; 
    Node *next;
    Node *prev;
};

class LinkedList
{
protected:
    Node *head;
public:
    LinkedList();
    ~LinkedList();
    void create_inital_node(int value);
    void add_to_list(int value);
    void delete_start_element();
    void delete_at_position(int pos);
    void delete_end_element();
    void update_element(int pos, int new_value);
    void print_list();
    int countNodes();
};
