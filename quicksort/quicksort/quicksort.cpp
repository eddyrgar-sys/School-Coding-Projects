// quicksort.cpp 
// Programmer: Eddy Garcia

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For seeding rand() with time

using namespace std;

// Function to partition the array
int partition(vector<int>& arr, int low, int high) 
{
    // Random pivot selection
    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[randomIndex], arr[high]); // Move chosen pivot to the end

    int pivot = arr[high]; // Set pivot as the last element
    int i = low - 1;

    for (int j = low; j < high; j++) 
    {
        if (arr[j] < pivot) 
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Quick Sort function
void quickSort(vector<int>& arr, int low, int high) 
{
    if (low < high) 
    {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() 
{
    srand(time(0));  // Seed random number generator for randomness

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

    // Sort using quick sort with random pivot selection
    quickSort(numbers, 0, numbers.size() - 1);

    // Print the sorted output numbers
    cout << "Output: ";
    for (int num : numbers) 
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}


