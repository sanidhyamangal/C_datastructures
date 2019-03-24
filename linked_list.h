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
    LinkedList(/* args */);
    ~LinkedList();
    void create_inital_node(int value);
    void add_to_single_list(int value);
    void print_list();
    int countNodes();
};
