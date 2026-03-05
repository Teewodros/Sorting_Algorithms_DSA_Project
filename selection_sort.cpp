//selection sort implemention
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

const int SIZE = 100000; // Constant size for the arrays

// ------------------ Classic Selection Sort (V1) ------------------
// This version finds the largest element in the unsorted portion 
// and moves it to the end in every pass, regardless of whether it's needed.
void selectionSortV1(int Data[], int n) {
    for (int last = n - 1; last >= 1; --last) {
        int largestIndex = 0;

        // Find the index of the largest element in the unsorted part
        for (int i = 1; i <= last; ++i) {
            if (Data[i] > Data[largestIndex]) {
                largestIndex = i;
            }
        }

        // Swap the largest element with the last item in the unsorted section
        int temp = Data[largestIndex];
        Data[largestIndex] = Data[last];
        Data[last] = temp;
    }
}

// ------------------ Improved Selection Sort (V2) ------------------
// This version includes two main optimizations:
// 1. Early exit if the array is already sorted
// 2. Shrinks the sorting bounds from both ends by placing the smallest and largest elements
void selectionSortV2(int Data[], int n)
{
    // Step 1: Check if the array is already sorted.
    bool alreadySorted = true;
    for (int i = 1; i < n; ++i) {
        if (Data[i - 1] > Data[i]) {
            alreadySorted = false;
            break;
        }
    }

    // If already sorted, exit the function early
    if (alreadySorted) return;

    int first = 0;         // Start of the unsorted region
    int last = n - 1;      // End of the unsorted region
    int smallestIndex, largestIndex;

    // Loop while the unsorted region has more than one element
    while (first < last)
    {
        smallestIndex = first;
        largestIndex = first;

        // Step 2: Find the smallest and largest in the current unsorted region
        for (int i = first; i <= last; ++i)
        {
            if (Data[i] < Data[smallestIndex])
                smallestIndex = i;
            if (Data[i] > Data[largestIndex])
                largestIndex = i;
        }

        // Step 3: Move the smallest element to the beginning of the unsorted region
        int temp = Data[first];
        Data[first] = Data[smallestIndex];
        Data[smallestIndex] = temp;

        // If the largest element was at 'first', update its index 
        // since the smallest swap may have moved it
        if (largestIndex == first)
            largestIndex = smallestIndex;

        // Step 4: Move the largest element to the end of the unsorted region
        temp = Data[last];
        Data[last] = Data[largestIndex];
        Data[largestIndex] = temp;

        // Narrow the bounds for the next pass
        first++;
        last--;
    }
}


// Reads integers from a file into a dynamically allocated array
int* getArray(string filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cout << "Error opening file: " << filename << endl;
        exit(1); // Stop program if file can't be opened
    }

    int* arr = new int[SIZE];
    int val, index = 0;

    // Read values from file until end or array is full
    while (inFile >> val && index < SIZE) {
        arr[index++] = val;
    }

    inFile.close();
    return arr;
}


// Helper function to print out the array contents (optional, not used in final code)
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ------------------ Main Testing function ------------------
int main() {
    // Load the arrays from external files
    int* sortedArr = getArray("Sorted.txt");
    int* reversedArr = getArray("SortedBackwards.txt");
    int* randomArr = getArray("randomList.txt");

    clock_t start, end; // For timing

    // -------- Run Classic Selection Sort (V1) --------
    cout << "Original Selection Sort:\n";

        // Test V1 on sorted data
        int* test1 = getArray("Sorted.txt");
    start = clock();
    selectionSortV1(test1, SIZE);
    end = clock();
    cout << "For Sorted Array: " << double(end - start) / CLOCKS_PER_SEC << " seconds\n";
    delete[] test1;

    // Test V1 on reverse-sorted data
    int* test2 = getArray("SortedBackwards.txt");
    start = clock();
    selectionSortV1(test2, SIZE);
    end = clock();
    cout << "For Reversed Array: " << double(end - start) / CLOCKS_PER_SEC << " seconds\n";
    delete[] test2;

    // Test V1 on random data
    int* test3 = getArray("randomList.txt");
    start = clock();
    selectionSortV1(test3, SIZE);
    end = clock();
    cout << "For Random Array: " << double(end - start) / CLOCKS_PER_SEC << " seconds\n";
    delete[] test3;

    cout << endl;

    // -------- Run Improved Selection Sort (V2) --------
    cout << "Improved Selection Sort:\n";

    // Test V2 on sorted data
    int* test4 = getArray("Sorted.txt");
    start = clock();
    selectionSortV2(test4, SIZE);
    end = clock();
    cout << "For Sorted Array: " << double(end - start) / CLOCKS_PER_SEC << " seconds\n";
    delete[] test4;

    // Test V2 on reverse-sorted data
    int* test5 = getArray("SortedBackwards.txt");
    start = clock();
    selectionSortV2(test5, SIZE);
    end = clock();
    cout << "For Reversed Array: " << double(end - start) / CLOCKS_PER_SEC << " seconds\n";
    delete[] test5;

    // Test V2 on random data
    int* test6 = getArray("randomList.txt");
    start = clock();
    selectionSortV2(test6, SIZE);
    end = clock();
    cout << "For Random Array: " << double(end - start) / CLOCKS_PER_SEC << " seconds\n";
    delete[] test6;

    // Free any leftover arrays (good practice even though they aren't reused)
    delete[] sortedArr;
    delete[] reversedArr;
    delete[] randomArr;

    return 0;
}
