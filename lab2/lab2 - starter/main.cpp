#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

void linkedListTest()
{
    cout << "***Linked List Remove Test***" << endl;
    LinkedList<int> test_list{};

    //add some simple values
    test_list.addElement(1);
    test_list.addElement(2);
    test_list.addElement(3);
    test_list.addElement(4);
    test_list.addElement(5);
    test_list.addElement(6);
    test_list.addElement(7);

    //sample removes
    test_list.removeElementAt(0); //remove first element (should be 0)
    test_list.removeElementAt(test_list.getSize() - 1); //remove last element (should be 7)
    test_list.removeElementAt(2); //remove 2nd element (should be 4)

    //print LL values
    cout << "LL values: ";
    for(int i = 0; i < test_list.getSize(); i++)
    {
        cout << test_list.getElementAt(i) << " ";
    }
    cout << endl;
    cout << "Expected: 2 3 5 6" << endl;
}

int main()
{
    linkedListTest();
}
