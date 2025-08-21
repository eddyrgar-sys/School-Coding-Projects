//This program should output: 
//1. Total Rainfall
//2. Average monthly rain
//3. Average monthly average temperature
//4. Highest and Lowest Temperature during the year and they months they occurred in
//Programmer: Eddy Garcia

#include <iostream>
#include <string>
#include <limits>

using namespace std;

//Define a structure to hold weather data for a month
struct WeatherData 
{
    double totalRainfall;
    double highTemperature;
    double lowTemperature;
    double averageTemperature;
};

//Function to get a validated temperature input
double getTemperature(const string& prompt) 
{
    double temperature;
    while (true) 
    {
        cout << prompt;
        cin >> temperature;
        if (cin.fail() || temperature < -100 || temperature > 140) 
        {
            cin.clear(); //Clear the fail flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Discard invalid input
            cout << "Invalid input. Please enter a temperature between -100 and 140 degrees Fahrenheit." << endl;
        }
        else 
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Clear the input buffer
            return temperature;
        }
    }
}

int main() 
{
    const int MONTHS_IN_YEAR = 12;
    WeatherData weather[MONTHS_IN_YEAR];
    string months[MONTHS_IN_YEAR] = 
    {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    //Collect data for each month
    for (int i = 0; i < MONTHS_IN_YEAR; ++i) 
    {
        cout << "Enter data for " << months[i] << ":\n";
        cout << "Total rainfall (in inches): ";
        cin >> weather[i].totalRainfall;

        weather[i].highTemperature = getTemperature("High temperature (F): ");
        weather[i].lowTemperature = getTemperature("Low temperature (F): ");

        //Calculate average temperature
        weather[i].averageTemperature = (weather[i].highTemperature + weather[i].lowTemperature) / 2;
        cout << endl;
    }

    //Calculate and display statistics
    double totalRainfall = 0;
    double totalAverageTemperature = 0;
    double highestTemperature = weather[0].highTemperature;
    double lowestTemperature = weather[0].lowTemperature;
    int highestMonth = 0;
    int lowestMonth = 0;

    for (int i = 0; i < MONTHS_IN_YEAR; ++i) 
    {
        totalRainfall += weather[i].totalRainfall;
        totalAverageTemperature += weather[i].averageTemperature;

        if (weather[i].highTemperature > highestTemperature) 
        {
            highestTemperature = weather[i].highTemperature;
            highestMonth = i;
        }

        if (weather[i].lowTemperature < lowestTemperature) 
        {
            lowestTemperature = weather[i].lowTemperature;
            lowestMonth = i;
        }
    }

    double averageMonthlyRainfall = totalRainfall / MONTHS_IN_YEAR;
    double averageOfAverageTemperatures = totalAverageTemperature / MONTHS_IN_YEAR;

    //Display results
    cout << "\nSummary of Weather Data for the Year:\n";
    cout << "Total rainfall for the year: " << totalRainfall << " inches\n";
    cout << "Average Monthly Rain: " << averageMonthlyRainfall << " inches\n";
    cout << "Average Monthly Average Temperature: " << averageOfAverageTemperatures << " F\n";
    cout << "Highest temperature: " << highestTemperature << " F in " << months[highestMonth] << endl;
    cout << "Lowest temperature: " << lowestTemperature << " F in " << months[lowestMonth] << endl;

    return 0;
}
