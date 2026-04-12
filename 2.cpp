#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int binarySearch(const vector<int>& arr, int low, int high, int key) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == key) return mid;
    return (arr[mid] > key) ? binarySearch(arr, low, mid - 1, key) : binarySearch(arr, mid + 1, high, key);
}

int main() {
    int n, key;
    cout << "Enter number of elements:\n";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements in sorted order:\n";
    for (int &i : arr) cin >> i;

    cout << "Enter the element to search: ";
    cin >> key;

    clock_t start = clock();
    int result = binarySearch(arr, 0, n - 1, key);
    clock_t end = clock();

    if (result != -1)
        cout << "\nElement " << key << " found at position " << result + 1 << ".\n";
    else
        cout << "\nElement " << key << " not found in the array.\n";

    printf("\nTime taken by recursive binary search: %.10f seconds", (double)(end - start) / CLOCKS_PER_SEC);
    cout << "\nTheoretical Time Complexity: O(log n)\nSpace Complexity (due to recursion stack): O(log n)\n";

    return 0;
}
