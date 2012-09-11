#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include "LinkedList.cpp"
#include "ListQue.cpp"
#include "ListStack.cpp"

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
    std::cout << (pal ? "Succes!" : "Failure!") << std::endl;

    std::cin.get();
	return 0;
}
