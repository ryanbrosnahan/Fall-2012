/*
ListQue.cpp  - Linked list implementation of a queue

Ryan Brosnahan
BrosnahanRyan@gmail.com
rjb39
 */


#include <cstdlib>
#include <iostream>
#include "Node.cpp"

template <class T>
class ListQue {
private:
    ListQue(const ListQue<T>&);  // disable copy constructor
    Node<T>* head;
    Node<T>* tail;
    Node<T>* temp;
    int elements;

public:
    ListQue() {
        head = tail = NULL;
        elements = 0;
    }
    virtual ~ListQue() {
      while(!isempty())
        pop();
    }

    void push(T val) {

        temp = new Node<T>(val);

        if(isempty()){
            tail  = head = temp;
        }

        else{
            tail->setNext(temp);
            tail = temp;
        }

        elements++;
    }


    T pop() {
        if (!isempty()){
            Node<T>* temp = head;
            head = head->getNext();
            elements--;

            T value = temp->getValue();

            delete temp;
            return value;
        }

        return 0;
    }

    bool isempty() {
        return !(bool)elements;
    }

    int size() {
        return elements;
    }
};





