#include <iostream>
using namespace std;

bool isValid(double x) { return x >= 0.0; }

double getValidRain(string month) 
{
	double rain;
	cout << "Enter rainfall for " << month << ": ";
	cin >> rain;
	while (!isValid(rain)) 
	{
		cout << "invalid data (negative rainfall) -- retry";
		cin >> rain;
	}
	return rain;
}

double sumArray(double x[], int n) 
{
	double sum = 0.0;
	for (int k = 0; k < n; k++)
		sum += x[k];
	return sum;
}

// assumes n>0
int findMaxArray(double x[], int n) 
{
	int max = 0;
	for (int k = 1; k < n; k++)
		if (x[max] < x[k]) max = k;
	return max;
}

// assumes n>0
int findMinArray(double x[], int n) 
{
	int min = 0;
	for (int k = 1; k < n; k++)
		if (x[min] > x[k]) min = k;
	return min;
}

int main() 
{
	const int MONTHS = 12;
	string monthNames[MONTHS] = { "January", "February", "March", "April",
				"May", "June", "July", "August", "September",
				"October", "November", "December" };
	double	rainfall[MONTHS];

	for (int m = 0; m < MONTHS; m++)
		rainfall[m] = getValidRain(monthNames[m]);

	double total = sumArray(rainfall, MONTHS);

	cout << "Total rainfall: " << total << endl;
	cout << "Average rainfall: " << total / MONTHS << endl;
	cout << "Least rainfall in: " << monthNames[findMinArray(rainfall, MONTHS)] << endl;
	cout << "Most rainfall in: " << monthNames[findMaxArray(rainfall, MONTHS)] << endl;
	for (int i = 0; i < 12; i++)
		cout << rainfall[i] << " inches in " << monthNames[i] << endl;

	return 0;
}