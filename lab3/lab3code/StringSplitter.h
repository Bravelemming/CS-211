#ifndef STRING_SPLITTER_H
#define STRING_SPLITTER_H

#include <queue>
#include <string>
using namespace std;
class StringSplitter
{
private:

public:

	//Break apart the supplied text based on the given delimiter.
	//static functions do not alter the internal state (i.e. variables)
	//of a given class instance.
	static queue<string> splitQ(string text, string delimiter)
	{
		//hold all of the discovered pieces
		queue<string> pieces{};

		//find the first instance of our delimiter
		int delimiter_location = text.find(delimiter);

		//begin at start of string
		int start = 0;

		//go until we have no more delimiters
		while (delimiter_location != string::npos)
		{
			//grab current piece bound by start and delimiter location
			string piece = text.substr(start, delimiter_location - start);

			//enqueue into our queue
			pieces.push(piece);

			//update our pointers
			start = delimiter_location + 1;
			delimiter_location = text.find(delimiter, start);
		}

		//at the end of the loop, there will always be a text fragment
		//that needs to be put into the queue.
		string piece = text.substr(start, delimiter_location - start);
		pieces.push(piece);

		//all done, return queue
		return pieces;
	}
};

#endif // STRING_SPLITTER_H