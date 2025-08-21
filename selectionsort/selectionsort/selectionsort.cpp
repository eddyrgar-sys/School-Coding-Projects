// selectionsort.cpp
// Programmer: Eddy Garcia

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

// Function to perform selection sort
void selectionSort(vector<int>& arr) 
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) 
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[minIndex]) 
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    ifstream inputFile("inputfile.txt");  // Open file for reading
    if (!inputFile) 
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    vector<int> numbers;
    string line;

    // Read the file content
    if (getline(inputFile, line)) 
    {
        stringstream ss(line);
        int num;
        while (ss >> num) 
        {
            numbers.push_back(num);
        }
    }
    inputFile.close();

    // Print the input numbers
    cout << "Input: ";
    for (int num : numbers) 
    {
        cout << num << " ";
    }
    cout << endl;

    // Sort using selection sort
    selectionSort(numbers);

    // Print the sorted output numbers
    cout << "Output: ";
    for (int num : numbers) 
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}


