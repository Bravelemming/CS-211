/*
Assignment: CS 211 - PA3
Description: Store lines
Author: "Jack" Daniel Kinne
HSU ID: 9395-18119
Completion Time: 13 Hours
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <queue>

#include "CsvWriter.h"
#include "Customer.h"

//seperate function, pulled for returning WHICH checkstand to go to as a customer
int static findCheckStand(vector< queue<Customer> > &checkStands) {
	for (int i = 0; checkStands.size() > i; i++)
	{
		if (checkStands[i].empty() == false)
		{
			return i;
		}
	}
	return (rand() % checkStands.size());
}

int main()
{

	//number of checkstands
	int checkStandValue = 0;

	//input from user for number of checkstands, total.  capped at 10.
	while (10 < checkStandValue || checkStandValue < 1)
	{
		std::cout << "please insert a valid number of checkstands between 1 and 10:" << endl;
		std::cin >> checkStandValue;
	}

	//output
	std::cout << "Performing Simulation..." << endl;

	//vector of queues of type customer.
	vector< queue<Customer> > checkStands(checkStandValue);

	//probability of a customer
	int custProbability = 0;

	//write out to a file!
	ofstream outFile;
	//targeting specific file
	outFile.open("output.csv");
	//first line
	outFile << "Customer ID,Arrival,Time to check out,Departure Time,Total wait,Line Number\n";

	//cycle of 720 minutes, or twelve hours.  MAIN FOR LOOP.
	for (int t = 0; t <= 719; t++)
	{
		//test 
		//std::cout << endl << "t= " << t << endl;

		//random number, setting seed.
		srand((unsigned int)time(0));

		if ((rand() % 5) <= custProbability)
		{
			custProbability = 0;

			//our customer, bob.  THEY ARE ALL NAMED BOB.
			Customer bob;

			//set service, arrival time, and ID. (same as arrival)
			bob.set_service_time(rand() % 4 + 1);

			bob.set_arrival_time(t);

			bob.set_customer_id(t);

			// pushing bob onto the appropriate checkstand, using function!
			checkStands[findCheckStand(checkStands)].push(bob);

		}
		else
		{
			//increment probablity of customer
			custProbability++;
		}

		//if there is a customer at the checkstand...
		for (int j = 0; checkStands.size() > j; j++)
		{
			if (checkStands[j].empty() == false)
			{
				//test
				//std::cout << "J:" << j << endl;

				//new customer object, temp held as steve from the "front" of queue
				Customer &steve = checkStands[j].front();

				if (steve.get_departure_time() == -1) //if departure is not listed
				{
					//set departure time
					steve.set_departure_time(t + steve.get_service_time());
				}

				if (t > steve.get_departure_time()) //if steve hasn't left
				{
					//write out to CSV
					outFile << steve.get_customer_id() << "," << steve.get_arrival_time() << "," <<
						steve.get_service_time() << "," << steve.get_departure_time() << "," <<
						steve.getTotalWaitTime() << "," << j << "\n";
					//pop object from queue, they leave the store.
					checkStands[j].pop();
				}

			}//end if

		}//end for

	}//end main for loop.

	//output
	std::cout << "Simulation Complete.  Saving Results to output.csv..." << endl;

	//close file.
	outFile.close();

	//output
	std::cout << "Save Finished.  Program Complete." << endl;

	//thrown in for a pause before exit so I can read the output.
	std::cout << endl;
	std::system("pause");
	return 0;

}//end main