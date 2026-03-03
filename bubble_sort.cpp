#include <iostream>
#include <fstream>
#include <ctime> // for time() and difftime()
using namespace std;

const int SIZE = 100000;

// BubbleSort function to sort an array of integers in ascending order.
void BubbleSort_v1(int data[], int listSize)
{
    int tempValue;
    // External loop: Controls the number of passes.
    for (int pass = 1; pass < listSize; pass++)
    {
        // Internal loop: Compares adjacent elements.
        for (int x = 0; x < listSize - pass; x++)
        {
            if (data[x] > data[x + 1])
            {
                tempValue = data[x];
                data[x] = data[x + 1];
                data[x + 1] = tempValue;
            }
        }
    }
}
void BubbleSort_v2(int data[], int n)
{
    int tempValue;
    int lastSwap = n - 1; // Track the last swap position

    for (int pass = 1; pass < n; ++pass)
    {
        bool sorted = true;
        int currentSwap = -1; // Track where the last swap occurs in this pass

        for (int x = 0; x < lastSwap; ++x)
        {
            if (data[x] > data[x + 1])
            {
                // Swap elements
                tempValue = data[x];
                data[x] = data[x + 1];
                data[x + 1] = tempValue;
                sorted = false;
                currentSwap = x; // Update the last swap position
            }
        }

        if (sorted)
            break;              // Early exit if no swaps occurred
        lastSwap = currentSwap; // Reduce the range for the next pass
    }
}
int* getArray(string filename)
{
    ifstream inFile;
    inFile.open(filename);
    if (inFile.fail())
    {
        cout << "File open failed.\n";
        exit(1);
    }
    else
    {
        int* arr = new int[SIZE];
        int index = 0;
        int num;
        while (inFile >> num && index < SIZE)
        {
            arr[index++] = num;
        }
        inFile.close();
        return arr;
    }
}

int main()
{
    // Process the first file: randomList (1).txt
    int* sortedArr = getArray("Sorted.txt");
    int* sortedBackwardsArr = getArray("SortedBackwards.txt");
    int* randomArr = getArray("randomList.txt");
    // print_array(sortedArr, 100000);

    time_t time1, time2;
    clock_t start, end;
    double dif_sec;

    cout << "--------------------------------\n";
    cout << "BubbleSort-v1\n";

    start = clock();
    BubbleSort_v1(sortedArr, SIZE);
    end = clock();
    cout << "Sorted array: " << double(end - start) / CLOCKS_PER_SEC << endl;

    start = clock();
    BubbleSort_v1(randomArr, SIZE);
    end = clock();
    cout << "Randomly ordered array: " << double(end - start) / CLOCKS_PER_SEC << endl;

    start = clock();
    BubbleSort_v1(sortedBackwardsArr, SIZE);
    end = clock();
    cout << "Reverse sorted array: " << double(end - start) / CLOCKS_PER_SEC << endl;
    cout << "--------------------------------\n";
    sortedArr = getArray("Sorted.txt");
    sortedBackwardsArr = getArray("SortedBackwards.txt");
    randomArr = getArray("randomList.txt");
    // print_array(sortedArr, 100000);

    cout << "--------------------------------\n";
    cout << "BubbleSort-v2\n";

    start = clock();
    BubbleSort_v2(sortedArr, SIZE);
    end = clock();
    cout << "Sorted array: " << double(end - start) / CLOCKS_PER_SEC << endl;

    start = clock();
    BubbleSort_v2(randomArr, SIZE);
    end = clock();
    cout << "Randomly ordered array: " << double(end - start) / CLOCKS_PER_SEC << endl;

    start = clock();
    BubbleSort_v2(sortedBackwardsArr, SIZE);
    end = clock();
    cout << "Reverse sorted array: " << double(end - start) / CLOCKS_PER_SEC << endl;
    cout << "--------------------------------\n";

    return 0;
}

