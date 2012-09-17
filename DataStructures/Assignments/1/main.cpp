#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include "LinkedList.cpp"
#include "ListQue.cpp"
#include "ListStack.cpp"
#include "ArrayQue.cpp"


int Length(ListQue<char> &);

int main() {

	/*
	Question 1:
	Demonstrates a non recursive function that reverses a singly-linked list
	 */

	//make a list
	LinkedList<int> list;

	//seed the RNG
	srand( time(NULL) );

	//populate the list with 12 psuedorandom numbers (0, 200)
	for(int i = 0; i < 12; i++)
		list.appendNode(rand() % 200);

	//display the list as it was created
	std::cout << "randomly generated list:" << std::endl;
	list.displayList();

	//reverse the list and display the results
	std::cout << "reversed list:" << std::endl;
	list.reverseList();
	list.displayList();

	std::cout << endl;

	/*
	Question 2:
	Demonstrates a palindrome tester
	 */

	//create a string
	string words;

	//prompt the user for some text and assign it to the string
	std::cout << "Enter a string to be tested for palidrome: " ;
	std::getline(cin, words);

	//initialize a que and stack
	ListQue<char> q;
	ListStack<char> s;

	//populate the que and stack with the text
	for(int i = 0; i < words.size(); i++) {
		q.push(words[i]);
		s.push(words[i]);
	}

    //assume it is a palindrome until proven otherwise
    bool pal = 1;

    //checking both, perhaps not neccesary
	while(!q.isempty() && !s.isempty()) {

        //this logic stops checking at the first instance of failure
		if( q.pop() == s.pop() )
            continue;

        pal = 0;
        break;
	}

    //print the results
    std::cout << (pal ? "That was a palindrome!" : "That was not a palindrome!") << std::endl << std::endl;


    /*
    Question 3 Demonstration
    Function is below
     */

    ListQue<char> q3;

    for (int i = 0; i < rand() % 100; i++)
    	q3.push(rand() % 100);

    std::cout << "Length of randomly generated queue for question 3: " << Length(q3) << std::endl << std::endl;

    /*
    Question 4 Demonstration
     */
    ArrayQue<char> arrQ;

    for (int i = 0; i < 10; i++)
    	arrQ.push(rand() % 100);

    std::cout << "ArrayQue should be 10 long, function says: " << arrQ.size() << std::endl;

    /*
    Question 5 Demonstration
     */

    ListQue<char> listQ;

    for (int i = 0; i < 10; i++)
    	listQ.push(rand() % 100);

    std::cout << "ListQue should be 10 long, function says: " << listQ.size() << std::endl;


    std::cin.get();
	return 0;
}



/*
Question 3
Implement a client function that returns the number of elements in a queue
We must assume the queue has functions:
	pop
	push
	isempty
We also assume it is a list of chars

What would the time requirements be in BigO?

To answer this we must assume that the queue operates in linear time.
Time requirement:
	n for each pop
	n for each length++
	n for each push

	3+3n

	BigO(n)

 */

int Length(ListQue<char>& queue) {

	ListQue<char> tempQ;
	int length = 0;

	//empty the queue while counting the elements
	while(!queue.isempty()) {
		tempQ.push(queue.pop());
		length++;
	}

	//refill the queue from the temporary one
	while(!queue.isempty())
		queue.push(tempQ.pop());

	return length;

}

/*
Question 4 is implemented in the file ArrayQue.cpp

The size of an array can be found in O(1) time using standard function size(),
by tracking elements, or by comparing the size of the array in memory to the
size of the element.

All solutions are in 0(1)
 */


/*
Question 5 is implemented in the file ListQue.cpp

Because I have control over the implementation of all members in the class,
it is possible to track the number of elements in the queue and return that
number in O(1) time.
 */

