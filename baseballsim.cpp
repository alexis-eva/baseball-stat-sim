/* baseball stat simulator */

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	cout.precision (3); // set global precision of 3

	struct PLAYER // struct for each player's data
	{
		// int number;
		string name;
		string position;
		float at_bats;
		float batavg;
		float strikeouts;
		float on_bases;
		float homeruns;
		int location;
	};

	PLAYER arr[100];
	ifstream File;
	File.open("stats.txt");
	int i = 0, j = 0; // variables for storing player data to the right spot in array and outputting it same
	int players = 2; // for counting players. if it started as 0 there were problems in outputting updated stats.
	while(File >> i) // while loop to store each player's data to its respective struct
	{
		// File >> i; // assign i the current player's number
		// arr[i].number = i;
		File >> arr[i].name;
		File >> arr[i].position;
		File >> arr[i].at_bats;
		File >> arr[i].batavg;
		File >> arr[i].strikeouts;
		File >> arr[i].on_bases;
		File >> arr[i].homeruns;
		arr[i].location = players; // for file recreation
		players++;
	}

	File.close();

	/* now it's time for baseball! */
	int outs = 0;
	int sel = 0; // for sports happenings selection
	while(outs < 3)
	{
		/* retrieve and display player data */
		cout << "Current player at bat (enter player's number): ";
		cin >> i;
		cout << endl << arr[i].name << ", #" << i << " (" << arr[i].position << ")" << endl;
		cout << "  AT BATS:          " << arr[i].at_bats << endl;
		cout << "  BATTING AVERAGE:  " << arr[i].batavg << endl;
		cout << "  STRIKEOUTS:       " << arr[i].strikeouts << endl;
		cout << "  ON BASE:          " << arr[i].on_bases << endl;
		cout << "  HOMERUNS:         " << arr[i].homeruns << endl << endl;

		/* display options, retrieve input, update sport */
		cout << "(1) STRIKEOUT (2) ON BASE (3) HOMERUN (4) OUT : ";
		cin >> sel;
		switch (sel)
		{
			case 1: // strikeout
				arr[i].at_bats += 1;
				arr[i].strikeouts += 1;
				break;
			case 2: // on base
				arr[i].at_bats += 1;
				arr[i].on_bases +=1;
				break;
			case 3: // homerun
				arr[i].at_bats += 1;
				arr[i].homeruns += 1;
				break;
			case 4: // out
				arr[i].at_bats += 1;
				outs += 1;
				break;
			default: // no
				break;
		}
		arr[i].batavg = ((arr[i].homeruns + arr[i].on_bases) / arr[i].at_bats); // update batting average
		cout << "=== OUTS: " << outs << " ===========================================" << endl << endl;

	}

	cout << "3 OUTS, INNING COMPLETED." << endl;
	cout << "NOW ATTEMPTING TO CREATE A NEW STATISTICS FILE" << endl << endl;

	ofstream outputFile;
	outputFile.open("updatedstats.txt");

	for(j = 2; j < players; j++) // loop to create output file
	{
		i = 0;
		while (arr[i].location != j) // find player data according to proper locations in the text file
		{
			i++;
		}
		outputFile << i << " ";
		outputFile << arr[i].name << " ";
		outputFile << arr[i].position << " ";
		outputFile << arr[i].at_bats << " ";
		outputFile << arr[i].batavg << " ";
		outputFile << arr[i].strikeouts << " ";
		outputFile << arr[i].on_bases << " ";
		outputFile << arr[i].homeruns << " ";
		outputFile << endl;
		i = 0;
	}
	if (outputFile.fail())
		cout <<  "Unable to pen file. New file has not been written.";
	return 0;
}



