// Quick sort algorithm (both standard and improved versions)
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;
const int SIZE = 100000;// set the maximum size of the array

//function declaration


void quicksortV1(int* arr, int first, int last);// Sorts an array using the basic quicksort algorithm (version 1)
void quicksortV2(int* arr, int first, int last);// Sorts an array using an improved quicksort algorithm (version 2) 
int partition(int* arr, int first, int last);// Partitions the array for quicksort using the last element as pivot
int partitionImproved(int* arr, int first, int last);// Improved partition function that uses median-of-three
void swap(int* arr, int bottom, int top);// Swaps two elements in an array
int* getArray(string filename);// Reads an array from a file and returns a pointer to it
void display(int* arr);// Displays the elements of an array
int getMedian(int first, int mid, int last);// returns the median of the three values

//main function
int main() {

    // import the data using getarray function
    int* Sorted = getArray("Sorted.txt");// Fixed-size array
    int* SortedBackwards = getArray("SortedBackwards.txt");
    int* randomList = getArray("randomList.txt");
    
    //
    clock_t start, end;// clock
    cout << "Quick Sort V1" << endl;
    cout << "--------------------------------------------" << endl;

    start = clock();
    quicksortV1(Sorted, 0, SIZE - 1);//call the quicksortV1 function for the sorted list
    end = clock();
    cout << "Sorted V1 : " << double(end - start) / CLOCKS_PER_SEC << endl;

    start = clock();
    quicksortV1(SortedBackwards, 0, SIZE - 1);//call the quicksortV1 function for the reversesorted list; 
    end = clock();
    cout << "SortedBackwards V1 : " << double(end - start) / CLOCKS_PER_SEC << endl;

    start = clock();
    quicksortV1(randomList, 0, SIZE - 1);//call the quicksortV1 function
    end = clock();
    cout << "randomList V1 : " << double(end - start) / CLOCKS_PER_SEC << endl<<endl;


     Sorted = getArray("Sorted.txt");// Fixed-size array
     SortedBackwards = getArray("SortedBackwards.txt");
     randomList = getArray("randomList.txt");

     cout << "Quick Sort V2" << endl;
     cout << "--------------------------------------------" << endl;

    start = clock();
    quicksortV2(Sorted, 0, SIZE - 1);//call the quicksortV2 function
    end = clock();
    cout << "Sorted V2 : " << double(end - start) / CLOCKS_PER_SEC << endl;

    start = clock();
    quicksortV2(SortedBackwards, 0, SIZE - 1);//call the quicksortV2 function
    end = clock();
    cout << "SortedBackwards V2 : " << double(end - start) / CLOCKS_PER_SEC << endl;

    start = clock();
    quicksortV2(randomList, 0, SIZE - 1);//call the quicksortV2 function
    end = clock();
    cout << "randomList V2 : " << double(end - start) / CLOCKS_PER_SEC << endl;
    

    return 0;
}
//
void quicksortV1(int* arr, int first, int last) {
    int cut;
    if (first < last) {
        cut = partition(arr, first, last);
        quicksortV1(arr, first, cut - 1);
        quicksortV1(arr, cut + 1, last);
    }
}
void quicksortV2(int* arr, int first, int last) {
    int cut;
    if (first < last) {
        cut = partitionImproved(arr, first, last);
        quicksortV2(arr, first, cut - 1);
        quicksortV2(arr, cut + 1, last);
    }
}
int partition(int* arr, int first, int last) {
    int pivot;
    int loop, cutPoint, bottom, top;
    pivot = arr[first];
    bottom = first;
    top = last;
    loop = 1; //always TRUE
    while (loop) {
        while (arr[top] > pivot) {
            top--;
        }
        while (arr[bottom] < pivot) {
            bottom++;
        }
        if (bottom < top) {
            // change pivot place
            swap(arr, bottom, top);
        }
        else {
            loop = 0; //loop false
            cutPoint = top;
        }
    }
    return cutPoint;
}
int partitionImproved(int* arr, int first, int last) {
    int pivot;
    int loop, cutPoint, bottom, top;
    pivot = getMedian(arr[first], arr[(first + last) / 2],arr[last]);// assigns the median value to pivot
    bottom = first;
    top = last;
    loop = 1; //always TRUE
    while (loop) {
        while (arr[top] > pivot) {
            top--;
        }
        while (arr[bottom] < pivot) {
            bottom++;
        }
        if (bottom < top) {
            // change pivot place
            swap(arr, bottom, top);
        }
        else {
            loop = 0; //loop false
            cutPoint = top;
        }
    }
    return cutPoint;// returns the cutpoint
}
int* getArray(string filename)
{
    ifstream inFile;
    inFile.open(filename);

    int* arr = new int[SIZE];
    int count = 0;

    int num;
    while (inFile >> num && count < SIZE)
    {
        arr[count++] = num;
    }
    inFile.close();

    return arr;
} 
void swap(int* arr, int bottom, int top) {// swaps the top and bottom values
    int temp = arr[bottom];
    arr[bottom] = arr[top];
    arr[top] = temp;
}
void display(int* arr) {
     //Display the numbers stored in the array
     cout << "Numbers read from file (" << SIZE << " integers):" << endl;
     for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
      }
    cout << endl;
}
int getMedian(int first, int mid, int last) {
    if ((first <= mid && mid <= last) || (last <= mid && mid <= first)) {//returns the middle element
        return mid;
    }
    else if ((mid <= first && first <= last) || (last <= first && first <= mid)) {//returns the first element
        return first;
    }
    else {
        return last;//returns the last element
    }
}

