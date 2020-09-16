#ifndef __STACK__
#define __STACK__

#define MAX_SIZE_OF_STACK 10;

template <typename T>
class Stack
{
private:
    T container[MAX_SIZE_OF_STACK];
    int numElements;

public:
    Stack();
    ~Stack();
    void push(T data);
    T pop();
    T return_top();
    bool isEmpty();
};

#endif
