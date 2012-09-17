/*
ArrayQue.cpp  - Array implementation of a queue

WARNING: QUICK AND DIRTY CODE!!!!!!!!!
ONLY HOLDS 1000 ELEMENTS!

 Ryan Brosnahan
 BrosnahanRyan@gmail.com
 rjb39
 */


#include <cstdlib>
#include <iostream>
#include <array>

template <class T>
class ArrayQue {
private:
    ArrayQue(const ArrayQue<T>&);
    int endPosition;
    int startPosition;
    std::array<T, 1000> data;

public:
    ArrayQue() {
        startPosition = 0;
        endPosition = 0;
    }


    void push(T val) {

        if(startPosition - 1 == endPosition) {
            std::cout << "Cannot perform push operation. Queue is full!" << std::endl;
            return;
        }

        data[endPosition % 1000] = val;
        endPosition++;
    }


    T pop() {
        startPosition++;
        return data[startPosition % 1000 - 1];
    }


    int size() {
        return (endPosition - startPosition) % 1000;
    }







};





