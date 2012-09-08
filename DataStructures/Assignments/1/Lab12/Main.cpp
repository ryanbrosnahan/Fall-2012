/*
 * Main.cpp  - Demonstrate stacks and queues
 */

#include "Stacktester.h"
#include "ListQue.h"
#include <iostream>
using namespace std;

int main() {
    cout << "---- STL Stacks: ----" << endl;
    stacktester();

    cout << "---- Custom-built Queues: ----" << endl;
    ListQue<double> q;
    q.push(1.2);
    q.push(2.3);
    q.push(3.4);
    cout << (q.isempty() ? "empty" : "not empty") << endl;
    cout << q.pop() << " ";
    cout << q.pop() << " ";
    q.push(4.5);
    cout << q.pop() << " ";
    cout << q.pop() << " ";
    cout << "\n" << (q.isempty() ? "empty" : "not empty") << endl;

    return 0;
}

