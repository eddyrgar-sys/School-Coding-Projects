// mergesort.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Programmer: Eddy Garcia

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>  // Include fstream for file operations

using namespace std;

// Function to merge two sorted subarrays into one
void merge(vector<int>& arr, int left, int right, int pivot) 
{
    vector<int> temp(right - left + 1);
    int i = left, j = pivot, k = 0;

    // The pivot is selected randomly to shuffle the merging behavior
    // Instead of starting directly at the mid, the random pivot allows 
    // us to avoid creating any biases in data comparison.
    while (i < pivot && j <= right) 
    {
        if (arr[i] <= arr[j]) 
        {
            temp[k++] = arr[i++];
        }
        else 
        {
            temp[k++] = arr[j++];
        }
    }

    while (i < pivot) 
    {
        temp[k++] = arr[i++];
    }

    while (j <= right) 
    {
        temp[k++] = arr[j++];
    }

    for (i = 0; i < temp.size(); i++) 
    {
        arr[left + i] = temp[i];
    }
}

// Recursive function to implement merge sort
void mergeSort(vector<int>& arr, int left, int right) 
{
    if (left < right) 
    {
        int pivot = left + rand() % (right - left + 1); // Random pivot between left and right
        mergeSort(arr, left, pivot);
        mergeSort(arr, pivot + 1, right);
        merge(arr, left, right, pivot);
    }
}

int main() 
{
    srand(time(0));  // Seed for random number generator

    // Open the file inputfile.txt
    ifstream inputFile("inputfile.txt");

    if (!inputFile) 
    {
        cerr << "Unable to open file inputfile.txt" << endl;
        return 1;  // Exit if file cannot be opened
    }

    vector<int> arr;
    int num;

    // Read numbers from the file into the array
    while (inputFile >> num) 
    {
        arr.push_back(num);
    }

    // Close the file after reading
    inputFile.close();

    // Printing the input array
    cout << "Input Array: ";
    for (int num : arr) 
    {
        cout << num << " ";
    }
    cout << endl;

    // Call mergeSort on the entire array
    mergeSort(arr, 0, arr.size() - 1);

    // Printing the sorted array (Output)
    cout << "Sorted Array: ";
    for (int num : arr) 
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

