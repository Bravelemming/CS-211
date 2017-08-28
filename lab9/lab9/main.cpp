#include <iostream>
#include "LinkedList.h"
#include "DoublyLinkedNode.h"
#include "DoublyLinkedList.h"

using namespace std;

int main()
{
    LinkedList<char> letters{};
    for(int i = 'a'; i < 'z'; i++)
    {
        letters.addElementAt((char)i, i - 'a');
    }
    for(int i = 0; i < letters.getSize(); i++)
    {
        cout << letters.getElementAt(i) << endl;
    }
    while(letters.getSize() > 0)
    {
        cout << letters.removeElementAt(0) << " ";
    }
    cout << endl;
	system("Pause");
    return 0;
}
