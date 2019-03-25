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
    void add_at_start(int value);
    void add_to_position(int pos, int value);
    void update_element(int pos, int new_value);
    void delete_start_element();
    void delete_at_position(int pos);
    void delete_end_element();

    Node *traverse_to_position(int pos);
    void print_list();
    int countNodes();
};
