#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool detLang(unordered_map<string, int> dictionary, string word)
{
	if (dictionary.find(word) != dictionary.end()) {
		
		return true;
	}
	else 
	{
		return false;
	}
}

int main() {

	cout << "hello world!" << endl;
	
	//unordered_map<string, //dictionary file name
	//		unordered_map<string, //word in dictionary
	//				int number of times found in other file
	
	unordered_map<string, unordered_map<string, int>> dictionaries{};
	
	bool keep_going = true;
	while (keep_going == true) 
	{
		cout << "enter a dictionary file (press enter to stop): ";
		string  file_name;
		getline(cin, file_name);

		//check for empty string
		if (file_name.length() > 0)
		{
			//parse file
			ifstream input_file(file_name);
			if(input_file.is_open() == true)
			{
				while (input_file.good() == true) {
					//put word in appropriate dictionary
					string word;
					getline(input_file, word);
					dictionaries[file_name][word] = 0;

				}
			}
		}
		else {
			//nothing found, stop loop
			keep_going = false;
		}


	}//end dictionary parsing loop

	 //testing correctness of above code

	for (auto dictionary : dictionaries) 
	{
		//the variable dictionary is a key value pair
		//dictionary.first (key): string
		//dictionary.second (value) : unordered_map<string, int>


		cout << dictionary.first << " contains " <<
				dictionary.second.size() << " Words. " << endl;
		/*
		cout << "first ten words in dictionary; " << endl;
		int count = 0;
		for (auto entry : dictionary.second) 
		{
			//entry is a key value pair
			//entry.first string
			//entry.second int
			cout << entry.first << endl;
			count++;
			if (count > 9) 
			{
				break;
			}
		}
		*/
		cout << "Does \"test\" exist; ";
		if (dictionary.second.find("test") != dictionary.second.end()) 
		{
			cout << "TRUE" << endl;
		}
		else 
		{
			cout << "FALSE" << endl;
		}

		cout << endl;
	}
	 
	 
	 //next, open file and determine language
	


	cout << "enter a file to determine language (press enter to stop): ";
	string  test_file;
	getline(cin, test_file);

	ifstream test_input(test_file);

	vector<string> test_vector;
	priority_queue<int>hitnums; //for maxness.
	//vector<string> hitNames;
	//vector<int> hits;

	//another option  to store for answering second question
	unordered_map<string, int> hits{};

	while(!test_input.eof())
	{
		string line;
		getline(test_input, line, ' ');
		test_vector.push_back(line);
	}

	for (auto dictionary : dictionaries) 
	{
		int counter = 0;
		for (int i = 0; i < 30; i++)
		//for (auto word : test_vector) 
		{
			
			if (detLang(dictionary.second, test_vector[i])) 
			{
				counter++;
			}
			hits[dictionary.first] = counter;
			hitnums.push(counter);
			

		}

	}

	int it = hitnums.top();

	cout << endl;
	cout << "The Language of this file is: ";

	for (auto entry : hits) 
	{
		if( (int) entry.second == (int) it)
		cout << entry.first.substr(0,entry.first.find('.')) << "." << endl;
	}

	if (it == NULL) "your language was not found in our archive.";
	system("pause");
	return 0;
	

};