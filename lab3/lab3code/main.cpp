/*
Assignment: CS 211 - LAB3
Description: Bunny Image Manipulation
Author: "Jack" Daniel Kinne
HSU ID: 9395-18119
Completion Time: 15 Hours
*/

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "Point.h"
#include "SimpleImageEffect.h"
#include "StringSplitter.h"

#include "RemoveGreenEffect.h"
#include "NegateGreenEffect.h"

#include "RemoveBlueEffect.h"
#include "NegateBlueEffect.h"
#include "RemoveRedEffect.h"
#include "NegateRedEffect.h"


#include "HighContrast.h"
#include "GrayscaleEffect.h"


using namespace std;

int main(void)
{

	//prompt for input and output file names
	string input_file_name;
	string output_file_name;
	cout << "Enter a PPM file to parse: ";
	getline(cin, input_file_name);
	cout << "Enter destination file: ";
	getline(cin, output_file_name);

	//read all information into a vector of strings
	vector<string> lines{};

	ifstream input_file{ input_file_name };

	//is file open?
	if (input_file.is_open() == true)
	{
		//grab each line in the file
		string line;

		while (input_file.good() == true)
		{
			getline(input_file, line);
			lines.push_back(line);

		}
	}

	cout << "test: we are adding line to lines" << endl;

	//vector of pixel values
	vector<int> pixel_values{};


	//for (string line : lines) {
	for (int i = 4; i < lines.size(); i++) {
		queue<string> numbers = StringSplitter::splitQ(lines[i], " ");

		//string number_str = "";

		while (numbers.empty() == false) {
			string number_str = numbers.front();
			numbers.pop();
			int pixel = atoi(number_str.c_str());
			pixel_values.push_back(pixel);

			//cout << "pixels: " << pixel << endl;
		}
	}
	//vector points of Point
	vector<Point> points{};

	for (int i = 7; i < (pixel_values.size() - 3); i = i + 3) {

		//assign values by R G B
		int red = pixel_values[i];
		int green = pixel_values[i + 1];
		int blue = pixel_values[i + 2];

		//pass values to class point, push 3 each of RGB to vector of points.
		points.push_back(Point(red, green, blue));

		//test
		//cout << pixel_values[i] << " " << pixel_values[i + 1] << " " << pixel_values[i + 2] << " ";

	}

	cout << "before processing." << endl;
	//object for remove green effect
	RemoveGreenEffect rge;
	//function process image of points for remove green
	rge.processImage(points);

	cout << "after processing." << endl;

	//write to file

	ofstream output{ output_file_name };

	//write first three lines with appropriate breaks

	//output << lines[0] << endl << lines[2] << " " << lines[3] << endl

	output << lines[0] << endl;
	output << lines[1] << " " << endl << lines[2] << endl;
	output << lines[3] << endl;


	//write from points tostring
	for (auto &item : points)
	{
		output << item.toString() << " ";
	}

	//TEST
	/*
	for (auto item : points) {
		cout << item.toString() << endl;
	}
	*/

	output.close();
	input_file.close();


	//TO DO FOR NEXT:
	//menu prompt
	// chain effects
}
