// Week 8 HW Lottery Winners: This program uses linear search to see if the user entered the winning lottery numbers

#include <iostream>
#include <vector>

using namespace std;
int main()
{

vector<int> lotteryNum{ 13579, 26791, 26792, 33445, 55555, 62483, 77777, 79422, 85647, 93121 };
int index = 0;
int userInput;
int position = -1;
bool found = false;

//Ask user for input
cout << "Please enter a five-digit lottery ticket: ";
cin >> userInput;

//Input validation: Numbers must be 5 digits
while (userInput < 10000 || userInput > 99999) 
{
	cout << "Lottery tickets can only contain 5 digits. Try again. " << endl;
	cin >> userInput;
}

//Linear Search Algorithm
while (index < 10 && !found) 
{
	if (lotteryNum[index] == userInput) 
	{
		found = true;
		position = index;
	}
	index++;
}

//Confirm whether or not the user input is a valid lottery number
if (position == -1)
cout << "The lottery number you have entered are not the winning lottery numbers." << endl;
else
cout << "Congratulations! You are the grand prize winner! The winning lottery numbers are: " << lotteryNum[position] << endl;
}