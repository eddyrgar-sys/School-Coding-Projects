// Week 1 HW.cpp : This program calculates and displays the distance a car can travel on one 
// tank of gas when driven in town and when driven on the highway.
// Eddy Garcia

#include <iostream>
using namespace std;

int main() 
{
    const int gasTank = 20;
    float averageTown = 23.5,
        averageHighway = 28.9;

    cout << "The car has a " << gasTank << " gallon gas tank. \n" << endl;

    cout << endl;
    cout << "The distance a car can travel in town" << endl;
    cout << "on a 20 gallon gas tank at 23.5 mpg is ";
    cout << averageTown * gasTank << " miles." << endl;
    cout << endl;

    cout << "The distance a car can travel on the highway" << endl;
    cout << "on a 20 gallon gas tank at 28.9 mpg is ";
    cout << averageHighway * gasTank << " miles." << endl;
    cout << endl;
}

