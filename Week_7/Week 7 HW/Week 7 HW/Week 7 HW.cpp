#include <iostream>
#include <string>

using namespace std;

int main()
{
	const int TOTALMONTHS = 12;

	double highest, lowest, getAverage;
	double total = 0;
	double rainfall[TOTALMONTHS];
	string months[TOTALMONTHS] = { "January", "February", "March", "April","May", "June", "July", "August", "September","October", "November", "December" };

	cout << "Enter the inches of rainfall for every month" << endl;

	// Get total rainfall per month
	for (int month = 0; month < TOTALMONTHS; month++)
	{
		cout << "The rainfall for the month of " << months[month] << ": ";
		cin >> rainfall[month];
		total += rainfall[month];

		// Validate the input
		while (rainfall[month] < 0)
		{
			cout << "Rainfall must be zero or more per month...";
			cout << "Please enter positive amount for " << months[month] << " again: ";
			cin >> rainfall[month];
			total += rainfall[month];
		}
	}

	cout << "The total rainfall amount was: \t\t" << total << endl;

	getAverage = total / TOTALMONTHS;
	cout << "The average rainfall amount was: \t" << getAverage << endl;

	// Get highest and lowest rainfall
	string maxMonth, minMonth;

	for (int month = 0; month < TOTALMONTHS; month++)
	{
		highest = rainfall[0];
		for (int count = 0; count < TOTALMONTHS; count++)
		{
			if (rainfall[count] > highest)
			{
				highest = rainfall[count];
				maxMonth = months[count];
			}
		}
		lowest = rainfall[0];
		for (int count = 0; count < TOTALMONTHS; count++)
		{
			if (rainfall[count] < lowest)
			{
				lowest = rainfall[count];
				minMonth = months[count];
			}
		}
	}
	cout << maxMonth << " was the month with the highest rainfall of " << highest << " inches." << endl;
	cout << minMonth << " was the month with the lowest rainfall of " << lowest << " inches." << endl;

	return 0;
}
