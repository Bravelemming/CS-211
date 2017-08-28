#include <iostream>
#include <string>
#include <sstream>
#include "Stack.h"

using namespace std;

void stackTest()
{
    string text = "This is a test";
    string expected = "tset a si sihT";
    Stack<char> ch_stack{};
    for(char ch : text)
    {
        ch_stack.push(ch);
    }

    int counter = 0;
    while(ch_stack.isEmpty() == false)
    {
        cout << "Output: " << ch_stack.pop() << " (expected: " << expected[counter] << ")" << endl;
        counter++;
    }

}

int main()
{
    stackTest();
    return 0;
}
