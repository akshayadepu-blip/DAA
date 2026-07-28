#include <iostream>
#include <chrono>   // For execution time
using namespace std;
using namespace std::chrono;

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

    // Selection Sort
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the minimum element with the current element
        swap(arr[i], arr[minIndex]);
    }

    // Stop timer
    auto stop = high_resolution_clock::now();

    // Calculate execution time
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "\nSorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n\nExecution Time: " << duration.count() << " nanoseconds";
    cout << "\nExecution Time: " << duration.count() / 1000.0 << " microseconds";

    cout << "\n\nTime Complexity:";
    cout << "\nBest Case: O(n^2)";
    cout << "\nAverage Case: O(n^2)";
    cout << "\nWorst Case: O(n^2)";

    cout << "\n\nSpace Complexity: O(1)" << endl;

    return 0;
}