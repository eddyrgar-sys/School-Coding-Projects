//Week 4 HW: Punch Line in the textbook
//Programmer: Eddy Garcia

#include <iostream>
#include <fstream>
#include <string>
#include <deque>

using namespace std;

//Function to display the joke from the joke file
void displayJoke(ifstream& jokeFile) 
{
    string line;
    while (getline(jokeFile, line)) 
    {
        cout << line << endl;
    }
}

//Function to display the punchline from the punch line file
void displayPunchLine(ifstream& punchLineFile) 
{
    //Read the entire file into a deque of strings (this allows us to access the last line easily)
    deque<string> lines;
    string line;

    //Read all lines into the deque
    while (getline(punchLineFile, line)) 
    {
        lines.push_back(line);
    }

    //The punchline is the last line in the deque
    if (!lines.empty()) 
    {
        cout << lines.back() << endl;  //Display the last line (punchline)
    }
}

int main() 
{
    //Open the joke file
    ifstream jokeFile("joke.txt");
    if (!jokeFile) 
    {
        cerr << "Could not open the joke file!" << endl;
        return 1;
    }

    //Open the punchline file
    ifstream punchLineFile("punchline.txt");
    if (!punchLineFile) 
    {
        cerr << "Could not open the punchline file!" << endl;
        return 1;
    }

    //Display the joke from the joke file
    cout << "Here's the joke:" << endl;
    displayJoke(jokeFile);

    //Display the punchline from the punchline file
    cout << "\nAnd here's the punchline:" << endl;
    displayPunchLine(punchLineFile);

    //Close the files
    jokeFile.close();
    punchLineFile.close();

    return 0;
}

