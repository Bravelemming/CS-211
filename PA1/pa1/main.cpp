/*
Assignment: CS 211 - PA1

Description: Grocery Store

Author: "Jack" Daniel Kinne
HSU ID: 9395-18119
Completion Time: 9 Hours

In completing this program, I received help from the following people:
Brennan
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

//function prototype(s)
string menu();

int main() {

	ifstream inFile;
	// Class of ifstream for inputing string data.
	inFile.open("grocery_list.txt");

	//checking for errors!
	if (inFile.fail()) {
		cerr << "Error when opening this file.  Exiting." << endl;
		exit(1);
	}

	//money that the user has, declared.
	int money;
	int spent = 0;

	//arrays created
	int cost[7];
	int quantity[7];
	int purchased[7];
	string type[7];
	string quantityhold[7];
	string costhold[7];

	//grab object, associate to variable.

	//apples
	//type[0] = item.substr(0, 6);
	//quantity[0] = stoi(item.substr(7, 1));  old way with substr!
	//cost[0] = stoi(item.substr(9, 1));

	getline(inFile, type[0], ':');
	getline(inFile, quantityhold[0], ':');
	getline(inFile, costhold[0]);
	//convert int to string
	quantity[0] = stoi(quantityhold[0]);
	cost[0] = stoi(costhold[0]);

	//milk
	//type[1] = item.substr(10, 4);
	//quantity[1] = stoi(item.substr(16, 1));  old way with substr!
	//cost[1] = stoi(item.substr(18, 1));

	getline(inFile, type[1], ':');
	getline(inFile, quantityhold[1], ':');
	getline(inFile, costhold[1]);
	//convert int to string
	quantity[1] = stoi(quantityhold[1]);
	cost[1] = stoi(costhold[1]);

	//bread
	//type[2] = item.substr(19, 5);
	//quantity[2] = stoi(item.substr(26, 1));  old way with substr!
	//cost[2] = stoi(item.substr(28, 1));

	getline(inFile, type[2], ':');
	getline(inFile, quantityhold[2], ':');
	getline(inFile, costhold[2]);
	//convert int to string
	quantity[2] = stoi(quantityhold[2]);
	cost[2] = stoi(costhold[2]);

	//candy
	//type[3] = item.substr(29, 5);
	//quantity[3] = stoi(item.substr(36, 2));  old way with substr!
	//cost[3] = stoi(item.substr(39, 1));

	getline(inFile, type[3], ':');
	getline(inFile, quantityhold[3], ':');
	getline(inFile, costhold[3]);
	//convert int to string
	quantity[3] = stoi(quantityhold[3]);
	cost[3] = stoi(costhold[3]);

	//cheese
	//type[4] = item.substr(40, 6);
	//quantity[4] = stoi(item.substr(48, 1));  old way with substr!
	//cost[4] = stoi(item.substr(50, 1));

	getline(inFile, type[4], ':');
	getline(inFile, quantityhold[4], ':');
	getline(inFile, costhold[4]);
	//convert int to string
	quantity[4] = stoi(quantityhold[4]);
	cost[4] = stoi(costhold[4]);

	//oranges
	//type[5] = item.substr(51, 7);
	//quantity[5] = stoi(item.substr(60, 1));  old way with substr!
	//cost[5] = stoi(item.substr(62, 1));

	getline(inFile, type[5], ':');
	getline(inFile, quantityhold[5], ':');
	getline(inFile, costhold[5]);
	//convert int to string
	quantity[5] = stoi(quantityhold[5]);
	cost[5] = stoi(costhold[5]);

	//cherries
	//type[6] = item.substr(63, 8);
	//quantity[6] = stoi(item.substr(73, 1));  old way with substr!
	//cost[6] = stoi(item.substr(75, 1));

	//getline(inFile, empty[5], '\n');
	getline(inFile, type[6], ':');
	getline(inFile, quantityhold[6], ':');
	getline(inFile, costhold[6]);
	//convert int to string
	quantity[6] = stoi(quantityhold[6]);
	cost[6] = stoi(costhold[6]);

	//menu start
	string cartAnswer;
	bool keepLooping = true;
	bool check = false;
	char continues;

	cout << "Welcome to Jack's Mart!" << endl;

	string menu(); {
		//TODO try and catch for invalid string or otherwise input.
		do {
			cout << "How much money do you have?:";
			cin >> money;
			if (money > 0 && money <= 999) {
				check = true;
			}
			else {
				//error catch for valid inputs to money.
				cout << endl << "Invalid input.  Please try again." << endl;
			}

		} while (check == false);

		//the great loop:
		while (keepLooping) {
			// what's in stock today for all items
			cout << "Here's what we have in stock today:" << endl;
			for (int x = 0; x < 6; x++) {
				cout << "*** " << type[x] << "    $" << cost[x] << "    (qty: " << quantity[x] << ")" << endl;
			}
			cout << endl;
			cout << "You have $" << money << endl;
			cout << "what would you like to put into your cart:";
			//grab cart answer from user
			cin >> cartAnswer;

			if (cartAnswer == "apples") {

				if ((money - cost[0]) > 0) {
					quantity[0]--;
					purchased[0]++;
					money = money - cost[0];
					spent = spent + cost[0];
				}
				else {
					cout << "Sorry!  Not enough money for that item." << endl;
				}
			}
			else if (cartAnswer == "milk") {

				if ((money - cost[1]) > 0) {
					quantity[1]--;
					purchased[1]++;
					money = money - cost[1];
					spent = spent + cost[1];
				}
				else {
					cout << "Sorry!  Not enough money for that item." << endl;
				}
			}
			else if (cartAnswer == "bread") {

				if ((money - cost[2]) > 0) {
					quantity[2]--;
					purchased[2]++;
					money = money - cost[2];
					spent = spent + cost[2];
				}
				else {
					cout << "Sorry!  Not enough money for that item." << endl;
				}
			}
			else if (cartAnswer == "candy") {

				if ((money - cost[3]) > 0) {
					quantity[3]--;
					purchased[3]++;
					money = money - cost[3];
					spent = spent + cost[3];
				}
				else {
					cout << "Sorry!  Not enough money for that item." << endl;
				}
			}
			else if (cartAnswer == "cheese") {

				if ((money - cost[4]) > 0) {
					quantity[4]--;
					purchased[4]++;
					money = money - cost[4];
					spent = spent + cost[4];
				}
				else {
					cout << "Sorry!  Not enough money for that item." << endl;
				}
			}
			else if (cartAnswer == "oranges") {

				if ((money - cost[5]) > 0) {
					quantity[5]--;
					purchased[5]++;
					money = money - cost[5];
					spent = spent + cost[5];
				}
				else {
					cout << "Sorry!  Not enough money for that item." << endl;
				}
			}
			else if (cartAnswer == "cherries") {

				if ((money - cost[6]) > 0) {
					quantity[6]--;
					purchased[6]++;
					money = money - cost[6];
					spent = spent + cost[6];
				}
				else {
					cout << "Sorry!  Not enough money for that item." << endl;
				}
			}
			else {
				//catch error and repeat
				cout << endl << "We're sorry, we're all out of " << cartAnswer << " today." << endl;
			}

			while (bool timeloop = true) {

				cout << "Would you like to continue shopping? (y/n): ";
				cin >> continues;

				cout << endl;
				cout << endl;

				if (continues == 'n') {
					keepLooping = false;
					timeloop = false;
					cout << "Here's what you added to your shopping cart:" << endl;

					for (int x = 0; x < 7; x++) {
						if ((purchased[x] > 0) && (purchased[x] != NULL)) {
							cout << "* " << type[x] << endl;
						}
					}
					cout << "You spent $" << spent << " and have $" << money << " left over." << endl;
					cout << "Thank you, come again!";
					break;
				}
				else if (continues == 'y') {
					timeloop = false;
					break;
				}
				else {
					//catch invalid selection
					cout << "invalid selection." << endl;
					break;
				}
			}


			//note to self: TO break it for TESTING
			//use keepLooping = false;

		} //end while

	} //end menu

	//write out to a file!
	ofstream outFile;
	//targetting specific file
	outFile.open("grocery_list.txt");
	//writing from variables
	for (int x = 0; x < 7; x++) {
		outFile << type[x] << ":" << quantity[x] << ":" << cost[x] << endl;
	}
	//close that thing.
	outFile.close();

	//thrown in for a pause before exit!
	cout << endl;
	system("pause");

	return 0;
}