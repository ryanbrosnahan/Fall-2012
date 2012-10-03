#include "ListTree.cpp"
#include <time.h>

int main() {
	ListTree<int> tree;
    srand( time(NULL) );

    int sum = 0;
    std::cout << "Randomly generated numbers to be put into a tree: ";
    for(int i = 0; i < 3; i++) {
        int p = rand() % 8;
        tree.insert(p);
        std::cout << p << " ";
        sum += p;
    }
    std::cout << std::endl << "Tree contents printed in PREORDER: ";
    tree.display();

    std::cout << std::endl << "The sum of the tree should be " << sum << std::endl;
    std::cout << "The calculated sum is " << tree.sumAll() <<std::endl;

    tree.displayLess(4);


    std::cout << std::endl;
    std::cout << "The max depth of this tree is: " << tree.maxDepth() << std::endl;
    std::cout << "The min depth of this tree is: " << tree.minDepth() << std::endl;

    std::cout << "Is the tree balanced? " << (tree.isBalanced() ? "It is!" : "It isn't!")
                << std::endl;

    std::cout << "the depth to reach the node with value of 5 is: " << tree.nodeDepth(5)
                << std::endl;

    std::cout << "The most expenive path costs: " << tree.maxPath();
}