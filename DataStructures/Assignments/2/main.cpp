#include "ListTree.cpp"

int main() {
	ListTree<int> tree;

    for(int i = 1; i<10; ++i)
        tree.insert(i);

    tree.display();

}