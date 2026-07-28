#include <iostream>
#include <chrono>   // For execution time
using namespace std;
using namespace std::chrono;

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high];   // Choose last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Start timer
    auto start = high_resolution_clock::now();

    // Perform Quick Sort
    quickSort(arr, 0, n - 1);

    // Stop timer
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "\nSorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n\nExecution Time: " << duration.count() << " nanoseconds";
    cout << "\nExecution Time: " << duration.count() / 1000.0 << " microseconds";

    cout << "\n\nTime Complexity:";
    cout << "\nBest Case: O(n log n)";
    cout << "\nAverage Case: O(n log n)";
    cout << "\nWorst Case: O(n^2)";

    cout << "\n\nSpace Complexity:";
    cout << "\nAverage Case: O(log n)";
    cout << "\nWorst Case: O(n)" << endl;

    return 0;
}