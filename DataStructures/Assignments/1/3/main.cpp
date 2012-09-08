/*
 * $Id: main.cpp 6852 2012-04-15 06:02:42Z rjb39 $
 *
 * Author: James R. Daehn
* Author: Ryan Brosnahan
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include "HashTable.h"
#include "LinkedList.h"
#include <String>
#include <ctime>
#include <iomanip>

using namespace std;

/*
 * This program demonstrates an application of linked lists,
 * namely, the use of hash tables.
 */
int main(int argc, char** argv) 
{
    //Just some tests of the LinkedList class
    LinkedList<std::string> list;
    list.insertNode("test a");
    list.insertNode("test b");
    list.insertNode("test c");
    list.insertNode("test b");
    list.insertNode("test d");
    list.insertNode("test e");
    list.insertNode("test b");

    list.displayList();
    cout << "finding 'test a' " << list.findNode("test a") << endl;
    cout << "finding 'test f' " << list.findNode("test f") << endl;

    //make the HashTable
    HashTable<string> table;
    
    //we gonna time it
    const int PRECISION = 6;
    clock_t startTime = clock();


    //make the fstream and use a temporary holder for
    //the data called dat
    std::ifstream data;
    data.open("usconst.txt");
    string dat;

    //while the file is good, put the word in dat and 
    //put it in the HashTable
    while(data.good()){
        data >> dat;
        table.Insert(dat);
    }

    //calculate and print the elapsed time!
    clock_t endTime = clock();
    double elapsedTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    //close the file
    data.close();

    //display the timing results
    table.Display();

    cout << "Elapsed time: ";
    cout << fixed << std::setprecision(PRECISION);
    cout << elapsedTime << " seconds!" << endl;

    //test the find function:
    cout << "Find States,: " << table.Find("States,") << endl;
    cout << "Find blah: " << table.Find("blah") << endl;

  return 0;
}
