struct Node
{
    int data; 
    Node *next;
    Node *prev;
};

class LinkedList
{
private:
    Node *head, *temp;
public:
    LinkedList(/* args */);
    ~LinkedList();
    void create_list(int data);
};
