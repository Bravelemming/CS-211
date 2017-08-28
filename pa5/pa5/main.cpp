/*
Assignment: CS 211 - PA5
Description: Gradebook
Author: "Jack" Daniel Kinne
HSU ID: 9395-18119
Completion Time: 26 Hrs
*/

#include <unordered_map>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class gradebookRow {
public:
	string studentLast;
	string studentFirst;
	// <Assignment name, Assignment score>
	unordered_map<string, int> gradesUMap;
};

class gradebook {
public:
	// <Assignment name, Max score>
	unordered_map<string, int> assignmentUMap;
	// <Student ID, Row>
	unordered_map<int, gradebookRow> completeEntryUMap;
};


#pragma region CSV stuff

string readCSVString(istream &input)
{//getline, return string
	string result;
	getline(input, result, ',');
	return result;
}

void output(ostream &output, string print)
{//output, pick stream, format
	output << "\"" + print + "\"" + ',';
}

void outputNoComma(ostream &output, string print)
{//output, pick stream, format
	output << "\"" + print + "\"";
}

void outCSVs(gradebook &name, vector<string> &masterKeyAssign, vector<int> &masterKeyStuID)
{
	ofstream outDetails; //output of details
	outDetails.open("details.csv");
	ofstream outSummary; //output of summary
	outSummary.open("summary.csv");

	output(outDetails, "#ID"); // outputing first objects
	outputNoComma(outDetails, "Name");
	output(outSummary, "#ID");
	output(outSummary, "Name");

	outputNoComma(outSummary, "Final Grade"); //formating

	bool exams = false; //flags for output
	bool homework = false;
	bool quizzes = false; 

	for (auto i : masterKeyAssign)
	{//output header assignment names
		outDetails << ',';
		outputNoComma(outDetails, i);

		//if (i == "Total") {}
		
		if (i.find("E") != string::npos) 
		{
			exams = true;
		}
		else if (i.find('H') != string::npos)
		{
			homework = true;
		}
		else if (i.find('Q') != string::npos)
		{
			quizzes = true;
		}

	}//end header assignment names

	if (exams == true)
	{
		outSummary << ',';
		outputNoComma(outSummary, "Exams");
	}
	if (homework == true)
	{
		outSummary << ',';
		outputNoComma(outSummary, "Homework");
	}
	if (quizzes == true)
	{
		outSummary << ',';
		outputNoComma(outSummary, "Quizzes");
	}


	outDetails << '\n' << "\"\","; //formatting
	outSummary << '\n' << "\"\",";

	outputNoComma(outDetails, "OVERALL"); //output overall
	outputNoComma(outSummary, "OVERALL");

	outSummary << ','; //formating

	float eMax = 0; // max score, additive for all exams, HW, Quizzes.
	float hMax = 0;
	float qMax = 0;

	for (auto i : masterKeyAssign)
	{//output header assignment max values
		outDetails << ',';
		outputNoComma(outDetails, to_string(name.assignmentUMap[i])); // <Assignment name, Max score>

		if (i.find('E') != string::npos)
		{
			eMax = (float)name.assignmentUMap[i] + eMax;
		}
		else if (i.find('H') != string::npos)
		{
			hMax = (float)name.assignmentUMap[i] + hMax;
		}
		else if (i.find('Q') != string::npos)
		{
			qMax = (float)name.assignmentUMap[i] + qMax;
		}

	}//end header assignment max values

	if (eMax > 0)
	{//if theres an exam
		outSummary << ',';
		outSummary << "\"" << eMax << "\"";
	}
	if (hMax > 0)
	{//if theres homework
		outSummary << ',';
		outSummary << "\"" << hMax << "\"";
	}
	if (qMax > 0)
	{//if theres a quiz
		outSummary << ',';
		outSummary << "\"" << qMax << "\"";
	}


	outDetails << '\n'; //formatting
	outSummary << '\n';




	for (int i : masterKeyStuID)
	{//row

		output(outDetails, to_string(i)); // i = student id
		output(outSummary, to_string(i));

		outDetails << name.completeEntryUMap[i].studentLast << ','; // output student names
		outDetails << name.completeEntryUMap[i].studentFirst;

		outSummary << name.completeEntryUMap[i].studentLast << ','; // output student names
		outSummary << name.completeEntryUMap[i].studentFirst;

		float total = 0; //hold values for outSummary
		float totalH = 0;
		float totalQ = 0;
		float totalE = 0;


		for (string x : masterKeyAssign) 
		{ // x = assignment name
		// output in string form, from gradebook1 object, // completeEntryUMap = <Student ID, Row>
			outDetails << ',';
			outputNoComma(outDetails, to_string(name.completeEntryUMap[i].gradesUMap[x])); // gradesUmap = <Assignment name, Assignment score> // output score 


			if (x.find('E') != string::npos)
			{
				totalE = (float)name.completeEntryUMap[i].gradesUMap[x] + totalE;
			}
			else if (x.find('H') != string::npos)
			{
				totalH = (float)name.completeEntryUMap[i].gradesUMap[x] + totalH;
			}
			else if (x.find('Q') != string::npos)
			{
				totalQ = (float)name.completeEntryUMap[i].gradesUMap[x] + totalQ;
			}

		}//end for loop entries in row

		total = totalE + totalH + totalQ; //math for total calculation
		total = (total / (eMax + hMax + qMax)) * 100.00;


		outSummary << ',';
		outSummary << "\"" << total << "\"";

		if (totalE > 0)
		{//if theres an exam
			outSummary << ',';
			outSummary << "\"" << totalE << "\"";
		}
		if (totalH > 0)
		{//if theres homework
			outSummary << ',';
			outSummary << "\"" << totalH << "\"";
		}
		if (totalQ > 0)
		{//if theres a quiz
			outSummary << ',';
			outSummary << "\"" << totalQ << "\"";
		}



		outDetails << '\n';
		outSummary << '\n';

	}//end student id row


	outDetails.close();
	outSummary.close();
}

#pragma endregion




int main() {

	cout << "Gradebook aggregator." << endl;

	gradebook gradebook1; //main object.

	vector<string> fileNames; //parsing for file names

	vector<string> masterKeyAssign; //master headings (all)
	vector<int>masterKeyStuID; // master student ID's (all)

#pragma region filename input

	//loop for CSV's input
	bool keepAsking = true;
	while (keepAsking == true)
	{
		//file names input
		cout << "please input filename(s) of gradebooks (<category>_<#>.csv)" << endl;
		cout << "(enter <s> to stop): ";
		string  file_name;
		getline(cin, file_name);

		fileNames.push_back(file_name);

		if (file_name == "s") //stop loop
		{
			keepAsking = false;
			fileNames.pop_back(); //drop 's' entry
		}
	}//end parsing loop

#pragma endregion

		//check for empty vector, then parse file.
	while (fileNames.size() > 0)
	{
		vector<string> assignVector; // first headings
		vector<int> studentIDVector; // student Id's 

		ifstream input_file; //input
		input_file.open(fileNames.back());
		cout << fileNames.back();
		cout << "...file is open" << endl;


		
		//save unique first two entries
		cout << "saving first two uniques...";
		string uniqueID = readCSVString(input_file);
		string uniqueNAME = readCSVString(input_file);
		
		//cout << "unique 1: " + uniqueID << " and " << " unique 2: " + uniqueNAME <<  endl; //TEST POINT

		while (input_file.good() == true) //while there is input
		{
			string assign = readCSVString(input_file);

			if (assign == "OVERALL") {
				break; //breakpoint; stop at overall.
			}

			//cout << "object: " << assign << endl; // TEST POINT
			assignVector.push_back(assign); // temp add, flush each file for input
			masterKeyAssign.push_back(assign); // master key add
		}
		
		string line; //split a line into smaller pieces.
		stringstream iss;
		getline(input_file, line);
		iss << line;
		//cout << "linecheck: " << line << endl; // testing

		for (string i : assignVector) //should be x4 on exams_1.csv
		{
			if (input_file.good() == false)
			{
				cout << "oh my god everything is broken!" << endl;
				break;
			}

			string token = readCSVString(iss); //break iss into tokened pieces
			//cout << "token: " << token << endl;

			gradebook1.assignmentUMap[i] = stoi(token); // [key] = int value 

			//cout << "i = " << i << endl;
			//cout << "AssignmentUMap[i] = " << gradebook1.assignmentUMap[i] << endl;
		}
		cout << endl;
		cout << "checkpoint: assignVector has populated assignmentUMap." << endl;
		cout << endl;

		while (input_file.good() == true) //while there is input
		{

			string tempStudentID = readCSVString(input_file);
			//cout << "string of student ID: " << tempStudentID << endl; // TESTPOINT

			if (tempStudentID.empty()) { break; } //loop is repeating--last entry treated as newline

			studentIDVector.push_back(stoi(tempStudentID)); // temp add, flush on new file
			masterKeyStuID.push_back(stoi(tempStudentID)); // master key add
			//cout << "student id: " << studentIDVector.back() << endl;

			//if ('"' == input.peek()) { quote parsing } // to check for quotes, and parse!!!!
			//

			//get student name
			string studentLast = readCSVString(input_file);
			string studentFirst = readCSVString(input_file);

			//cout << "studenLast:" << studentLast << endl;
			//cout << "studentFirst:" << studentFirst << endl;

			//split a line into smaller pieces.
			string line2;
			stringstream iss2;
			getline(input_file, line2); //whole line to new character
			iss2 << line2;

			for (string i : assignVector) //while there are objects in assignVector 
			{

				//break the iss into tokened pieces
				string token2 = readCSVString(iss2);
				//cout << "token: " << token2 << endl;

				// this creates an instance of a full row...mining down into around 8 objects
				if (gradebook1.completeEntryUMap.find(stoi(tempStudentID)) == gradebook1.completeEntryUMap.end())
				{
					gradebook1.completeEntryUMap[stoi(tempStudentID)] = { studentLast, studentFirst,{} };  // [key] = int value, static place 2 str's 
				}
				gradebook1.completeEntryUMap[stoi(tempStudentID)].gradesUMap[i] = stoi(token2); // <Assignment name, Assignment score>

				//cout << "i = " << i << endl;
				//cout << "gradesUMap[i] = " << gradebook1.completeEntryUMap[stoi(tempStudentID)].gradesUMap[i] << endl;
			}//end for

			if (input_file.good() == false) //catch 
			{
				cout << "end parse." << endl;
				break;
			}

		}//end while, student ID rows are populated.

		cout << "rows are now populated." << endl;

		input_file.close(); //cleanup

		fileNames.pop_back(); //drop file name from vector
	}//end while parsing of fileNames vector

	outCSVs(gradebook1, masterKeyAssign, masterKeyStuID); // call to output function

	cout << "Program complete, press enter to exit." << endl;

	cin.get();  // for a pause

	return 0; // end main
}









