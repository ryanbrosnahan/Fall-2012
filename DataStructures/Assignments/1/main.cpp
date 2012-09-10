#include <iostream>
#include <cstdlib>
#include <time.h>
#include "LinkedList.h"

int main() {

	LinkedList<int> list;
	srand( time(NULL) );

	for(int i = 0; i < 12; i++)
		list.appendNode(rand() % 200);

	std::cout << "randomly generated list:" << std::endl;
	list.displayList();

	std::cout << "reversed list:" << std::endl;
	list.reverseList();
	list.displayList();

	return 0;
}