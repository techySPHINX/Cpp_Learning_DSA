#include <iostream>
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

// Function to swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to partition the array using a random pivot
int randomizedPartition(vector<int>& arr, int low, int high) {
    // Generate a random index between low and high
    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[randomIndex], arr[high]); // Move the random pivot to the end

    int pivot = arr[high]; // The pivot element
    int i = low - 1; // Index of the smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); // Move the pivot to its correct position
    return i + 1; // Return the partition index
}

// Randomized Quick Sort function
void randomizedQuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pivotIndex = randomizedPartition(arr, low, high);

        // Recursively sort elements before and after partition
        randomizedQuickSort(arr, low, pivotIndex - 1);
        randomizedQuickSort(arr, pivotIndex + 1, high);
    }
}

// Utility function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Example array to be sorted
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    cout << "Original array: ";
    printArray(arr);

    // Perform Randomized Quick Sort
    randomizedQuickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
