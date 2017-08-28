/*
Assignment: CS 211 - MA3
Description: Super string reduction
Author: "Jack" Daniel Kinne
HSU ID: 9395-18119
Completion Time: 3 Hours (ish)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string line = ""; // given code
	cout << "Input string to reduce:" << endl;
	getline(cin, line);
	
	for (int i = 0; i < line.size(); ) {
		if (line[i] == line[i + 1]) {
		//if (line[i] == line[i - 1]) { potential to count down to eliminate reset!
			line.erase(i, 2);
			i = 0;
		}
		else {
			i++; // so it only iterates once complete.
		}
			//line[i] = NULL;  //this also works!  (but leaves a hole)
			//line[i + 1] = NULL;  
			//line.erase(line.begin()+i, line.begin()+i+2); //works, but breaks iterator
			//substr() //another option that maybe could work.
	}//end for

	if (line != "") {
		cout << line << endl; // if its not empty, print this.
	}
	else {
		cout << "Empty String"; // print this if empty.
	}
	cout << endl;
	system("PAUSE"); //appropriate pause here
	return 0; 
} //end prog
