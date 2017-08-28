#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

void linkedListTest()
{
    cout << "***Linked List Test***" << endl;
    LinkedList<int> test_list{};

    test_list.addElementAt(0, 1);
    test_list.addElementAt(1, 2);
    test_list.addElementAt(0, 3);
    test_list.addElementAt(2, 4);
    cout << "Number of elements in LL: " << test_list.getSize() << " (expected: 4)" << endl;
    cout << "Value at 0: " << test_list.getElementAt(0) << " (expected: 3)" << endl;
    cout << "Value at 1: " << test_list.getElementAt(1) << " (expected: 1)" << endl;
    cout << "Value at 2: " << test_list.getElementAt(2) << " (expected: 4)" << endl;
    cout << "Value at 3: " << test_list.getElementAt(3) << " (expected: 2)" << endl;
}

int main()
{
    linkedListTest();
}
