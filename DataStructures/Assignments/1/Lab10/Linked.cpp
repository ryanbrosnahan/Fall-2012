/*
 * Linked.cpp  - Demonstration of STL linked list using insertion sort
 *
 * Ryan Brosnahan
 * BrosnahanRyan@gmail.com RJB39
 */

#include <iostream>
#include <list>


template <class T>
void printlist(std::list<T> lst) {
    class std::list<T>::iterator it = lst.begin();
        while (it != lst.end()) {
            std::cout << *it << " ";
            it++;
        }

        std::cout << '\n';

}
//for some reason this function didnt run properly using g++ in windows cygwin
//it worked fine in Mingw and linux gcc; it was a pain to troubleshoot!
template <class T>
void aceSort(std::list<T>& lst) {

    class std::list<T>::iterator sortedend = lst.begin();
    class std::list<T>::iterator next = lst.begin();
        next++;
    class std::list<T>::iterator it;

    while (next != lst.end()) {
        
        if(*sortedend > *next){
            lst.erase(next);

            for(it = lst.begin(); it != lst.end(); it++) {
                if(*it > *next) {
                    lst.insert(it, *next);
                    break;
                }
            }
        } 

        else {
            sortedend++;
        }

        next = sortedend;
        next++;

    }
}


template <class T>
void descSort(std::list<T>& lst) {

    class std::list<T>::iterator sortedend = lst.begin();
    class std::list<T>::iterator next = lst.begin();
        next++;
    class std::list<T>::iterator it;

    while (next != lst.end()) {
        if(*sortedend < *next){
            lst.erase(next);

            for(it = lst.begin(); it != lst.end(); it++) {
                if(*it < *next) {
                    lst.insert(it, *next);
                    break;
                }
            }
        } else {
            sortedend++;
        }

        next = sortedend;
        next++;

    }
}

template <class T>
void reverseSort(std::list<T>& lst) {

    class std::list<T>::iterator iterator = lst.begin();
    class std::list<T>::iterator temp = lst.end();

    int i = 0;

    for(iterator; iterator = temp; iterator++ ) {
        std::swap(iterator, temp);

        temp--; 
    }

}


int main() {
    std::list<int> numbers;
    std::list<int>::iterator it;   // iterator

    // populate list "randomly"
    int j = 1;
    for(int i=1;i<10;++i) {
        numbers.push_back(j);
        j = (j + 3037) % 2099;  // prime numbers yay!
    }

    std::cout << "A list of random numbers:" << std::endl;
    printlist(numbers);

    std::cout << "List sorted in reverse:" << std::endl;
    reverseSort(numbers);
    printlist(numbers);

    std::cout << "List sorted ascending:" << std::endl;
    aceSort(numbers);
    printlist(numbers);

    std::cout << "List sorted descending:" << std::endl;
    descSort(numbers);
    printlist(numbers);

    std::cin.get();

    return 0;
}

