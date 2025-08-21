// insertionsort.cpp 
// Programmer: Eddy Garcia

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

// Function to perform insertion sort
void insertionSort(vector<int>& arr) 
{
    int n = arr.size();
    for (int i = 1; i < n; i++) 
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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

    // Sort using insertion sort
    insertionSort(numbers);

    // Print the sorted output numbers
    cout << "Output: ";
    for (int num : numbers) 
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

