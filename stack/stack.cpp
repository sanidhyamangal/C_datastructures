#include<iostream>
#include "stack.h"

using namespace std;

template <typename T>
Stack<T>::Stack(){
    numElements = 0;
}

template <typename T>
void Stack<T>::push(T data){
    if (numElements > MAX_SIZE_OF_STACK){
        cout<<"Error: Stack OverFlow"<<endl;
    }else
    {
        container[numElements] = data;
        numElements++;
    }
}

template <typename T>
T Stack<T>::pop(){
    if (isEmpty()){
        cout<<"Error: No element to pop"<<endl;
    }else
    {
        numElements--;
        return container[numElements];
    }
}

template <typename T>
T Stack<T>::return_top(){
    return conatainer[numElements-1];
}

template <typename T>
bool Stack<T>::isEmpty(){
    return numElements == 0;
}