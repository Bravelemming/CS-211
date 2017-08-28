#ifndef CHECKSTAND_H
#define CHECKSTAND_H

#include <vector>
#include <string>
#include <queue>
#include <conio.h>
#include "Customer.h"


using namespace std;

template <queue> class queue<Customer>
{
private:
	string _line_name;
	int tick_count;
	queue<Customer> _line;
public:

	queue();
	~queue();

	void insert(int i);
	int remove();


	queue() {
		front = 0;
		back = 0;
	}

	~queue() {
		delete queArray[];
	}

	void insert(int i) {
		if (isfull()) {

		}
	}


};
#endif