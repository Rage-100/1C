#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

int binarySearch(int arr[], int low, int high, int key) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == key) return mid;
    return arr[mid] > key ? binarySearch(arr, low, mid-1, key) : binarySearch(arr, mid+1, high, key);
}

int main() {
    int arr[100000], n, key;
    cout << "Enter number of elements: "; cin >> n;

    cout << "Enter " << n << " elements in sorted order:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter the element to search: "; cin >> key;

    clock_t s = clock();
    int result = binarySearch(arr, 0, n-1, key);
    double t = (double)(clock()-s)/CLOCKS_PER_SEC;

    if (result != -1)
        cout << "\nElement " << key << " found at position " << result+1 << ".\n";
    else
        cout << "\nElement " << key << " not found in the array.\n";

    cout << "\nTime taken by recursive binary search: " << fixed << setprecision(10) << t << " seconds"
         << "\nTheoretical Time Complexity: O(log n)"
         << "\nSpace Complexity (due to recursion stack): O(log n)\n";

    return 0;
}
