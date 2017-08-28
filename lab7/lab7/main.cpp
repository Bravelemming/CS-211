#include <iostream>
#include <vector>
#include "Vector.h"
using namespace std;

void vectorConstructorTest() {
	//move constructor
	Vector<int> v1{ Vector<int>{10} };
	v1[0] = 1;
	v1[1] = 2;

	//copy constructor
	Vector<int> v2{ v1 };
	v2[2] = 3;

	//copy operator
	v1 = v2;

	//move operator
	v2 = Vector<int>{}; //clears it to nothing

	//v1 : 1 2 3 0 0 0 0 0 0 0
	//v2 : empty

	for (int i = 0; i < v1.getSize(); i++) {
		cout << v1[i] << " ";

	}
	cout << endl << "V2: ";
	for (int i = 0; i < v2.getSize(); i++) {
		cout << v2[i] << " ";
	}
	cout << endl;
}

void vectorTest1() {
	Vector<int> numbers{};
	cout << "Vector Size: " << numbers.getSize() <<
			"(Expected: 0)" << endl;
	cout << "adding values 0 - 9 to vector..." << endl;
	for (int i = 0; i < 10; i++) {
		numbers.push(i);

	}
	cout << "vector size: " << numbers.getSize() <<
		"expected: 10" << endl;
	cout << "popping all values from vector: ";

	while (numbers.getSize() > 0) {
		cout << numbers.pop() << " ";
	}

	cout << endl;
	cout << "expected: ";
	cout << "9 8 7 6 5 4 3 2 1 0" << endl;
}

void vectorTest2() {
	Vector<int> numbers{};
	cout << "Vector Size: " << numbers.getSize() <<
		"(Expected: 0)" << endl;
	cout << "adding values 0 - 9 to vector..." << endl;
	for (int i = 0; i < 10; i++) {
		numbers.push(i);

	}

	Vector<int> numbers_copy = numbers;
	numbers.setElementAt(99, 4);

	for (int i = 0; i < numbers.getSize(); i++) {
		cout << numbers.getElementAt(i) << " ";

	}
	cout << endl;

	for (int i = 0; i < numbers_copy.getSize(); i++) {
		cout << numbers_copy.getElementAt(i) << " ";
	}


	cout << endl;
	cout << "expected: ";
	cout << "9 8 7 6 5 4 3 2 1 0" << endl;
}

int main()
{
	vectorTest2();
	vectorConstructorTest();
	system("PAUSE");
	return 0;
}