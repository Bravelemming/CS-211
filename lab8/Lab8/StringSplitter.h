#ifndef STRING_SPLITTER_H
#define STRING_SPLITTER_H

#include <string>
#include <vector>
#include <queue>

using namespace std;

class StringSplitter
{
public:

    //Breaks apart the supplied text based on the given delimiter
	//static function do not affect the internal state
	//(e.g. variables) of a given class instance
    static queue<string> splitQ(string text, string delimiter)
    {
        //vectors are dynamically expanding arrays
		queue<string> pieces;

		//find the first delimiter
		int location = text.find(delimiter);

		//we are starting at the beginning of our string
		int start = 0;

		//go until we have no more delimiters
		while (location != string::npos)
		{
			//add the current piece to our list of pieces
			string piece = text.substr(start, location - start);
			pieces.push(piece);

			//update our index markers for the next round
			start = location + 1;
			location = text.find(delimiter, start);
		}

		//at the end of our loop, we're going to have one trailing piece to take care of.
		//handle that now.
		string piece = text.substr(start, location - start);
		pieces.push(piece);

		//now, return the completed vector
		return pieces;
    }
};

#endif // STRING_SPLITTER_H
