#include<iostream>
#include<ctime>      // For measuring execution time
#include<fstream>    // For reading from files
using namespace std;

const int SIZE = 100000;         // Size of the arrays to sort
int tempArray[SIZE];             // Global temporary array used in mergeSortV2

// Function declarations
void mergeSortV1(int theArray[], int first, int last); // Original merge sort
void mergeV1(int theArray[], int first, int mid, int last); // Merge function for version 1
int* getArray(string filename);  // Reads integers from a file into an array
void print_array(int arr[], int n); // Utility to print array (currently unused)
void mergeSortV2(int theArray[], int first, int last); // Improved merge sort
void mergeV2(int theArray[], int first, int mid, int last); // Merge function for version 2

int main()
{
    // Read arrays from files
    int* sortedArr = getArray("Sorted.txt");
    int* sortedBackwardsArr = getArray("SortedBackwards.txt");
    int* randomArr = getArray("randomList.txt");

    // Uncomment to print the arrays
    // print_array(sortedArr, SIZE);
    // print_array(sortedBackwardsArr, SIZE);
    // print_array(randomArr, SIZE);

    cout << "Original Mergesort: \n";
    clock_t start, end;
    double dif_sec;

    // Time mergeSortV1 on sorted array
    start = clock();
    mergeSortV1(sortedArr, 0, SIZE - 1);
    end = clock();
    cout << "\nFor Sorted Array: " << double(end - start) / CLOCKS_PER_SEC << endl;

    // Time mergeSortV1 on reverse-sorted array
    start = clock();
    mergeSortV1(sortedBackwardsArr, 0, SIZE - 1);
    end = clock();
    cout << "\nFor Backwards Sorted Array: " << double(end - start) / CLOCKS_PER_SEC << endl;

    // Time mergeSortV1 on random array
    start = clock();
    mergeSortV1(randomArr, 0, SIZE - 1);
    end = clock();
    cout << "\nFor Random Array: " << double(end - start) / CLOCKS_PER_SEC << endl;

    cout << endl;

    // Reload arrays from files to reset them for the second sort
    sortedArr = getArray("Sorted.txt");
    sortedBackwardsArr = getArray("SortedBackwards.txt");
    randomArr = getArray("randomList.txt");

    cout << "Improved Mergesort: \n";

    // Time mergeSortV2 on sorted array
    start = clock();
    mergeSortV2(sortedArr, 0, SIZE - 1);
    end = clock();
    cout << "\nFor Sorted Array: " << double(end - start) / CLOCKS_PER_SEC << endl;

    // Time mergeSortV2 on reverse-sorted array
    start = clock();
    mergeSortV2(sortedBackwardsArr, 0, SIZE - 1);
    end = clock();
    cout << "\nFor Backwards Sorted Array: " << double(end - start) / CLOCKS_PER_SEC << endl;

    // Time mergeSortV2 on random array
    start = clock();
    mergeSortV2(randomArr, 0, SIZE - 1);
    end = clock();
    cout << "\nFor Random Array: " << double(end - start) / CLOCKS_PER_SEC << endl;

    cout << endl;

    // Clean up dynamically allocated memory
    delete[] sortedArr;
    delete[] sortedBackwardsArr;
    delete[] randomArr;
}

// Recursive implementation of MergeSort (Version 1)
void mergeSortV1(int theArray[], int first, int last)
{
    if (first < last)
    {
        int mid = (first + last) / 2;
        mergeSortV1(theArray, first, mid);
        mergeSortV1(theArray, mid + 1, last);
        mergeV1(theArray, first, mid, last); // Merge the two halves
    }
}

// Merging step for mergeSortV1 using local temp array
void mergeV1(int theArray[], int first, int mid, int last)
{
    int tempArrayLocal[SIZE];  // Temporary array for merging
    int first1 = first, last1 = mid;        // First subarray
    int first2 = mid + 1, last2 = last;     // Second subarray
    int index = first;                      // Index for merged array

    // Merge two sorted subarrays into tempArrayLocal
    while ((first1 <= last1) && (first2 <= last2))
    {
        if (theArray[first1] < theArray[first2])
            tempArrayLocal[index++] = theArray[first1++];
        else
            tempArrayLocal[index++] = theArray[first2++];
    }

    // Copy remaining elements from subarray 1, if any
    for (; first1 <= last1; ++first1, ++index)
        tempArrayLocal[index] = theArray[first1];
    // Copy remaining elements from subarray 2, if any
    for (; first2 <= last2; ++first2, ++index)
        tempArrayLocal[index] = theArray[first2];
    // Copy back to original array
    for (index = first; index <= last; ++index)
        theArray[index] = tempArrayLocal[index];
}

// Reads an array of integers from a file
int* getArray(string filename)
{
    ifstream inFile;
    inFile.open(filename);
    if (inFile.fail())
    {
        cout << "File open failed.\n";
        exit(1);
    }
    else {
        int* arr = new int[SIZE];
        int index = 0;
        int num;
        // Read up to SIZE integers into array
        while (inFile >> num && index < SIZE)
        {
            arr[index++] = num;
        }
        inFile.close();
        return arr;
    }
}

// Prints an array to the console
void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// Optimized MergeSort (Version 2) with extra condition to avoid unnecessary merges
void mergeSortV2(int theArray[], int first, int last)
{
    if (first < last)
    {
        int mid = (first + last) / 2;
        mergeSortV2(theArray, first, mid);
        mergeSortV2(theArray, mid + 1, last);
        // Only merge if elements are out of order
        if (theArray[mid] > theArray[mid + 1])
        {
            mergeV2(theArray, first, mid, last);
        }
    }
}

// Merge function for mergeSortV2 using global temp array (tempArray)
void mergeV2(int theArray[], int first, int mid, int last)
{
    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = first;

    // Merge the two halves into tempArray
    while ((first1 <= last1) && (first2 <= last2))
    {
        if (theArray[first1] < theArray[first2])
            tempArray[index++] = theArray[first1++];
        else
            tempArray[index++] = theArray[first2++];
    }

    // Copy any remaining elements
    for (; first1 <= last1; ++first1, ++index)
        tempArray[index] = theArray[first1];
    for (; first2 <= last2; ++first2, ++index)
        tempArray[index] = theArray[first2];
    // Copy back to the original array
    for (index = first; index <= last; ++index)
        theArray[index] = tempArray[index];
}

