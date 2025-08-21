// This program modifies the student Line Up program described in Programming Challenge 14 so that it gets the names from a file. 
// The program should be read in names from the file until there is no more data to read.

// Eddy Garcia

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream inputFile;
	string name, front, back;

	inputFile.open("LineUp.txt");

	if (inputFile)
	{
		inputFile >> name;

		name = front = back;

		while (inputFile >> name)
		{
			if (name < front)
				back = name;

			if (name > back)
				front = name;
		}

		inputFile.close();
	}

	else
	{
		cout << "Error opening file." << endl;
	}

	cout << back << " is in the front." << endl;

	cout << front << " is in the back." << endl;

	return 0;
}


