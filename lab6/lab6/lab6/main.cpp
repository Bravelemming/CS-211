#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main()
{
	cout << boolalpha;
	BinarySearchTree<int> bst{};
	bst.addItem(10);
	bst.addItem(2);
	//bst.addItem(1);
	bst.addItem(5);
	bst.addItem(15);
	bst.addItem(25);
	bst.addItem(3);
	bst.addItem(9);
	bst.addItem(11);

	cout << "tree is full: " << bst.isFull() << endl;
	cout << "tree is AVL: " << bst.isAvl() << endl;

	system("PAUSE");
	return 0;
}

