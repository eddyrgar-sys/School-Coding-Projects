//This program dynamically allocates an array large enough to hold a user-defined number of test scores.
//Using pointer notation rather than array notation whenever possible.
//Programmer: Eddy Garcia

#include <iostream>
#include <iomanip>
using namespace std;


void sortScores(double* scores, int size) 
{
    for (int i = 0; i < size - 1; ++i) 
    {
        for (int j = 0; j < size - i - 1; ++j) 
        {
            if (*(scores + j) > *(scores + j + 1))
            {
                //Swap
                double temp = *(scores + j);
                *(scores + j) = *(scores + j + 1);
                *(scores + j + 1) = temp;
            }
        }
    }
}

double calculateAverage(double* scores, int size) 
{
    double sum = 0.0;
    for (int i = 0; i < size; ++i) 
    {
        sum += *(scores + i);
    }
    return sum / size;
}

int main() 
{
    int numScores;

    //Input validation for the number of scores
    do 
    {
        cout << "Enter the number of test scores (greater than 0): ";
        cin >> numScores;
        if (numScores <= 0) 
        {
            cout << "Please enter a valid number of scores (must be positive).\n";
        }
    } while (numScores <= 0);

    //Dynamically allocate an array for the scores
    double* scores = new double[numScores];

    //Input validation for scores
    for (int i = 0; i < numScores; ++i) 
    {
        do 
        {
            cout << "Enter score " << (i + 1) << " (0 to 100, must be positive): ";
            cin >> *(scores + i);
            if (*(scores + i) < 0) 
            {
                cout << "Score cannot be negative. Please try again.\n";
            }
            else if (*(scores + i) > 100) 
            {
                cout << "Score must be between 0 and 100. Please try again.\n";
            }
        } while (*(scores + i) < 0 || *(scores + i) > 100);
    }

    //Sort the scores
    sortScores(scores, numScores);

    //Calculate the average
    double average = calculateAverage(scores, numScores);

    //Display results
    cout << "\nSorted Test Scores in Ascending Order:\n";
    for (int i = 0; i < numScores; ++i) 
    {
        cout << *(scores + i) << endl;
    }
    cout << "\n\nAverage Score: " << fixed << setprecision(2) << average << endl;

    //Free allocated memory
    delete[] scores;

    return 0;
}
