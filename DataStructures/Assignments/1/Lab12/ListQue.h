/*
 * ListQue.cpp  - Linked list implementation of a queue
 *
 * Ryan Brosnahan
 * BrosnahanRyan@gmail.com
 * rjb39
 */

#ifndef LAB_LINKEDQUE
#define LAB_LINKEDQUE


#include <cstdlib> // for NULL
#include <iostream>
using namespace std;

/*
    Provided class, Node.
    No changes need to be done to this class.
*/
template<class T>
class Node {
private:
    T value;
    Node* next;
public:
    Node() {
        next = NULL;
    }

    Node(T t) {
        value = t;
        next = NULL;
    }

    T getValue() {
        return value;
    }

    Node* getNext() {
        return next;
    }

    void setNext(Node* n) {
        next = n;
    }
};


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

            double value = temp->getValue();
            delete temp;
            return value;
        }

        return 0;
    }

    bool isempty() {
        return !(bool)elements;
    }
};




#endif  // LAB_LINKEDQUE

