/*
 * Linked.cpp  - Demonstration of STL linked list using insertion sort
 *
 * Ryan Brosnahan
 * BrosnahanRyan@gmail.com RJB39
 */

#include <iostream>
#include <list>
using namespace std;


template <class T>
void printlist(list<T> lst) {
    class list<T>::iterator it = lst.begin();
        while (it != lst.end()) {
            cout << *it << " ";
            it++;
        }

}
//for some reason this function didnt run properly using g++ in windows cygwin
//it worked fine in Mingw and linux gcc; it was a pain to troubleshoot!
template <class T>
void insertionsort(list<T>& lst) {

    class list<T>::iterator sortedend = lst.begin();
    class list<T>::iterator next = lst.begin();
        next++;
    class list<T>::iterator it;

    while (next != lst.end()) {
        if(*sortedend > *next){
            lst.erase(next);

            for(it = lst.begin(); it != lst.end(); it++) {
                if(*it > *next) {
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


int main() {
    list<int> numbers;
    list<int>::iterator it;   // iterator

    // populate list "randomly"
    int j = 1;
    for(int i=1;i<10;++i) {
        numbers.push_back(j);
        j = (j + 3037) % 2099;  // prime numbers yay!
    }

    printlist(numbers);
   // uncomment for part 2:
    cout << endl;
    insertionsort(numbers);
    printlist(numbers);
    cin.get();

    return 0;
}

