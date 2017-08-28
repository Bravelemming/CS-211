/*
Assignment: CS 211 - LAB1
Description: Ceasar Cipher
Author: "Jack" Daniel Kinne
HSU ID: 9395-18119
Completion Time: 6 Hours
*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//shift char down 3 positions
char encode_character(char character, int offset)
{
	if (character >= 'A' && character <= 'Z') //upper case
	{
		character = ( ( (character + offset - 'A' + 26) % 26) + 'A'); 
	}
	else if (character >= 'a' && character <= 'z') //lower case
	{
		character = ( ( (character + offset - 'a' + 26) % 26) + 'a');
	}
	
    return character;
}

//check for alpha, pass down to char encode_character.
string encode(string text, int offset)
{
    for (int i = 0; i < text.size(); i++)
	{
		if (isalpha(text[i])){ // check if its a letter, otherwise do nothing.
			text[i] = encode_character(text[i], offset);  // pass to encode_character, save.
			
			cout << text[i]; //TEST ONLY
		}
    }
    return text;
}

//begin MAIN
int main()
{
	//begin instream, from input.txt
	ifstream inText;
	inText.open("input.txt");

	vector<string> encodedFinal;  // vector, used for storing output

    //loop through all lines in input.txt file
    while (inText.good() )
    {
        string current_line; //storage for temp use
        getline(inText, current_line); // pass line by line

		cout << endl; //test
        cout << current_line << endl; //test!

        string encoded_text = encode (current_line, 3); // pass to function, begin encode

		encodedFinal.push_back(encoded_text); // store that sucker in a vector for output.
    }

	//write out to a file!
	ofstream outFile;
	//targetting specific file
	outFile.open("output.txt");
	//writing from variables
	//for (int x = 0; x < encodedFinal.size; x++) {
	for (vector<string>::iterator it = encodedFinal.begin(); it != encodedFinal.end(); ++it) {

		outFile << *it;
		cout << *it; //TEST ONLY, but lets keep it because it looks pretty.
	}

	//close infile
	inText.close();
	//close outfile
	outFile.close();

	//thrown in for a pause before exit!
	cout << endl;
	system("pause");
	
    return 0;
} // end main