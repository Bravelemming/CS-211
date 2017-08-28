/*
Assignment: CS 211 - PA4
Description: Cluster - Priority Queue
Author: "Jack" Daniel Kinne
HSU ID: 9395-18119
Completion Time: 14 Hours
I received help from the following people: Jack Witherell
*/
#include "Job.h"
#include <queue> // PQ
#include <vector> // vector
#include <iostream> // cout
#include <functional> // min heap
#include <fstream> // write out
#include <string> // strings

int main() {
	//passive priority queue of a vector of Jobs, named cluster.
	std::priority_queue<Job, std::vector<Job>, std::greater<Job> > cluster;

	//active jobs
	std::vector<Job> activeJobs;

	// Class of ifstream for inputing string data.
	std::ifstream inFile;
	inFile.open("jobs.txt");
	
	//first value in the file is the cluster size
	int clusterSize;
	inFile >> clusterSize;
	int activeCpu = 0;

	//values to save in jobs
	std::string name;
	int cpuRequired;
	int duration;
	int startTick = 0;
	
	//testpoint
	std::cout << "Cluster size" << std::endl;
	std::cout << clusterSize << std::endl;
		
	//write out to a file!
	std::ofstream outFile;
	//targeting specific file
	outFile.open("result.csv");
	//first line
	outFile << "Job Name,Starting Tick,Ending Tick,Duration,\n";
	

	//main loop
	bool checkforqueue = true; //breakout main
	int tick = 0; //iterator
	bool runThat = true; //run job if cpus are free

	while (checkforqueue) 
	{
		//if check does: MULTIPLE INPUTS from txt and creates a job object
		if (!inFile.eof()) 
		{
			//setting values to save in jobs
			inFile >> name >> cpuRequired >> duration;
			int startTick = tick;
			//create job object
			Job name(name, cpuRequired, duration, startTick);
			name.setDurationLeft(duration); //set duration left
			// add to passive PA cluster
			cluster.push(name);
			//testpoint
			std::cout << "name " << "cpuRequired " << "duration " << "start tick"<< std::endl;
			std::cout << name.getName() << " " << cpuRequired << " " << duration << " " << name.getStartTick() << " end" << std::endl;

			if (name.getCpu() > clusterSize) 
			{ //error check for larger cpu
				std::cout << "Error: cluster of CPU's smaller than job size.  Exiting..." << std::endl;
				return 1;
			}

		}//end if infile stuff

		// temp holder Job object, first priority object.
		Job holder = cluster.top();

		//test point
		std::cout << "fetching required cpu's for task: " << holder.getCpu() << " required."<< std::endl;

		//run a job if cpus required are less than or equal to free cluserSize cpus
		if (holder.getCpu() <= clusterSize) 
		{
			//test point
			std::cout << "Pending Job(s): "<< cluster.size() << std::endl;
			std::cout << "active Job(s): " << activeJobs.size() << std::endl;

			if ( !cluster.empty() ) //if cluster has a job and is not empty
			{
				Job holder = cluster.top(); //get cluster PQ in holder

				if (holder.getCpu() == 0) //if job is complete
				{ 
					cluster.pop();  //remove job from cluster

					if (!cluster.empty()) 
					{
						holder = cluster.top(); //if cluster isn't empty, holder.
					}
				}//end if job is complete

				while ((clusterSize - activeCpu) >= holder.getCpu() && !cluster.empty()) 
				{
					activeJobs.push_back(holder); // add holder to active
					activeCpu = holder.getCpu() + activeCpu; // these cpu's now active
					cluster.pop(); // kill last in cluster
					if (!cluster.empty()) 
					{
						holder = cluster.top(); //if the cluster isn't empty, next = holder
					}
				}

			} //end if cluster not empty

			//iterate over activeJobs
			for (int i = 0; i < activeJobs.size(); i++) 
			{
					activeJobs.at(i).setDurationLeft( activeJobs.at(i).getDuration() );
					if (1 > activeJobs.at(i).getDuration()) 
					{
						activeCpu = activeCpu - activeJobs.at(i).getCpu(); // free active cpus
						//output to CSV
						outFile << activeJobs.at(i).getName() << "," << activeJobs.at(i).getStartTick() << "," << tick << "," << tick - activeJobs.at(i).getStartTick()  << ",\n";
						activeJobs.erase(activeJobs.begin() + i);
					}
			}//end for


		}//end run a job

		tick++; //ticks iterator
		//if (inFile.eof()) { //sentinel condition to escape
		if (!clusterSize&&cluster.empty() && activeJobs.empty() ) {
			checkforqueue = false;
		} 

	}//end while main loop

	//close outFile and inFile, cleanup.
	inFile.close();
	outFile.close();

	//thrown in for a pause before exit!
	std::cout << std::endl;
	system("pause");

	return 0;
} //end main