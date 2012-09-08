/*
 * Stacktester.h  - Practice using the STL stack object
 *
 * Ryan Brosnahan
 * BrosnahanRyan@gmail.com
 * rjb39
 */

#ifndef LAB_STACKTESTER
#define LAB_STACKTESTER

#include <iostream>
#include <stack>
using std::cout;
using std::endl;
using std::stack;

template <class T>
void popandprint(stack<T>& stak) {
    cout << stak.top() << " ";
    stak.pop();
}

void stacktester() {
    stack<int> st;

    st.push(8);
    st.push(6);
    st.push(1);
        popandprint(st);
    st.push(2);
        popandprint(st); 
    st.push(5);
    st.push(3);
        popandprint(st);
    st.push(4);
        popandprint(st);
        popandprint(st);
        popandprint(st);
    st.push(7);
        popandprint(st);
        popandprint(st);

    cout << endl;
}

#endif  // LAB_STACKTESTER

