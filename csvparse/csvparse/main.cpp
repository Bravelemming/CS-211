#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string readCSVEntry(istream &input)
{
	string result;
	char c = input.get();
	result.push_back(c);
	return result;
}

int main() {
	ifstream is;
	string  read_csv_entry;
	string fileName;
	cout << "filename:" << endl;
	cin >> fileName;
	is.open(fileName);
	while (is.good() == true) 
	{
		is.get();
	}


	is >> read_csv_entry;

	cout << read_csv_entry;


	// 
	// 
	// 


	cin.get();
	return 0;
}