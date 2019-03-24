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
    void create_list(int value);
    void single_list(int value);
    void print_list();
};
