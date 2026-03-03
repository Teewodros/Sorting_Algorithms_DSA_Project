
// InsertionSortV1 & V2 - Fixed Version

#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

// Define the constant size of the array.
const int SIZE = 100000;

// Declare the sorting functions and utility functions
void insertionSortV1(int data[], int n);
void insertionSortV2(int data[], int n);
void print_array(int arr[], int n);
int* getArray(string filename);

int main()
{
    srand(time(0)); // Seed for random number generator

    // Load the arrays from text files.
    int* sortedArr = getArray("Sorted.txt");
    int* sortedBackwardsArr = getArray("SortedBackwards.txt");
    int* randomArr = getArray("randomList.txt");

    // Variables for timing
    clock_t start, end;
    double dif_sec;

    cout << "--------------------------------\n";
    cout << "InsertionSortV1\n";
    cout << "--------------------------------\n";

    start = clock();
    insertionSortV1(sortedArr, SIZE);
    end = clock();
    cout << "Sorted array: " << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    start = clock();
    insertionSortV1(randomArr, SIZE);
    end = clock();
    cout << "Randomly ordered array: " << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    start = clock();
    insertionSortV1(sortedBackwardsArr, SIZE);
    end = clock();
    cout << "Reverse sorted array: " << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    // Free old arrays before reloading
    delete[] sortedArr;
    delete[] sortedBackwardsArr;
    delete[] randomArr;

    // Reload arrays for second sorting test
    sortedArr = getArray("Sorted.txt");
    sortedBackwardsArr = getArray("SortedBackwards.txt");
    randomArr = getArray("randomList.txt");

    cout << "--------------------------------\n";
    cout << "InsertionSortV2\n";
    cout << "--------------------------------\n";

    start = clock();
    insertionSortV2(sortedArr, SIZE);
    end = clock();
    cout << "Sorted array: " << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    start = clock();
    insertionSortV2(randomArr, SIZE);
    end = clock();
    cout << "Randomly ordered array: " << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    start = clock();
    insertionSortV2(sortedBackwardsArr, SIZE);
    end = clock();
    cout << "Reverse sorted array: " << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    // Clean up
    delete[] sortedArr;
    delete[] sortedBackwardsArr;
    delete[] randomArr;

    cout << "--------------------------------\n";
}

// insertionSortV1: Basic insertion sort
void insertionSortV1(int data[], int n)
{
    int item;
    int pass, insertIndex;

    for (pass = 1; pass < n; pass++)
    {
        item = data[pass];
        insertIndex = pass;
        while (insertIndex > 0 && item < data[insertIndex - 1])
        {
            data[insertIndex] = data[insertIndex - 1];
            insertIndex--;
        }
        data[insertIndex] = item;
    }
}

// insertionSortV2: Improved insertion sort with binary search and random pivot
void insertionSortV2(int data[], int n)
{
    int item, temp;
    int pass, insertIndex, randomIndex;
    int middle, left, right;

    pass = 0;
    while (pass < n - 1 && data[pass] < data[pass + 1])
    {
        pass++;
    }

    for (; pass < n; pass++)
    {
        randomIndex = (rand() % (SIZE - pass)) + pass;

        temp = data[randomIndex];
        data[randomIndex] = data[pass];
        data[pass] = temp;

        item = data[pass];

        left = 0;
        right = pass - 1;
        while (left <= right)
        {
            middle = (left + right) / 2;
            if (data[middle] > item)
                right = middle - 1;
            else
                left = middle + 1;
        }
        insertIndex = left;

        for (int i = pass; i > insertIndex; i--)
        {
            data[i] = data[i - 1];
        }

        data[insertIndex] = item;
    }
}

// getArray: reads integers from a file into a new array
int* getArray(string filename)
{
    ifstream inFile(filename);
    if (inFile.fail())
    {
        cout << "File open failed: " << filename << endl;
        exit(1);
    }

    int* arr = new int[SIZE];
    int index = 0, num;

    while (inFile >> num && index < SIZE)
    {
        arr[index++] = num;
    }

    inFile.close();
    return arr;
}

// print_array: prints the elements of an array
void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}