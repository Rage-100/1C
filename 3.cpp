#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void insertionSort(vector<int>& arr) {
    for (int i = 1; i < (int)arr.size(); i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key)
            arr[j + 1] = arr[j--];
        arr[j + 1] = key;
    }
}

int main() {
    // Bubble Sort
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for (int& x : arr) cin >> x;

    bubbleSort(arr);
    cout << "\nSorted array in ascending order:\n";
    for (int x : arr) cout << x << " ";

    // Insertion Sort
    cout << "\n\nenter the values of array\n";
    vector<int> arr2(5);
    for (int& x : arr2) cin >> x;

    insertionSort(arr2);
    cout << "sorted ouptout\n";
    for (int x : arr2) cout << "   " << x;

    return 0;
}
