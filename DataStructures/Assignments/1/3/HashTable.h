/*
 * $Id: HashTable.h 6852 2012-04-15 06:02:42Z rjb39 $
 *
 * Author: James R. Daehn
 * Author: Ryan Brosnahan
 *
 * Hash table declaration.
 *
 * A class to model a hash table that deals with collisions
 * with chaining.
 *
 *
 * The implementation of HashTable had to be included here in 
 * the header because of how bad c++ templates are and compiler
 * stuff that I dont really understand. 
 * Read about it at http://yosefk.com/c++fqa/templates.html#fqa-35.12
 *
 * In theory it could be fixed by using a separate implementation .cpp
 * http://www.parashift.com/c++-faq-lite/templates.html#faq-35.13
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include "LinkedList.h"
#include "LinkedList.h"
#include <cstdlib>
#include <iostream>

using namespace std;

template <class T>
class HashTable{
public:
    LinkedList<T>* array;
    HashTable();
    ~HashTable();
    void Insert(T);
    bool Find(const T&) const;
    void Display();
};

//spec said 13, could be a parameter in version2
template <typename T>
HashTable<T>::HashTable(){  
    array = new LinkedList<T>[13];
}   

template <typename T>
HashTable<T>::~HashTable(){
    delete [] array;
}

template <typename T>
void HashTable<T>::Insert(T value){
    //calculates the ascii and mod 13 position
    int count = 0;
    for(int i = 0; i < 3; i++)
        count += int(value[i]);
    count = count % 13;

    //insert it
    array[count].insertNode(value);
}

template <typename T>
bool HashTable<T>::Find(const T& value) const{
    //for each hash value, check if the node exists
    for(int i = 0; i <=13; i++)
        if (array[i].findNode(value))
            return 1;
    return 0;
}

template <typename T>
void HashTable<T>::Display(){
    for(int i = 0; i <13; i++){
        cout << "HASH VALUE " << i <<": " << endl;
        array[i].displayList();
        cout << endl;
    }
}

#endif /* HASHTABLE_H_ */
