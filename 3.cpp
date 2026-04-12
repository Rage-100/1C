#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Helper to print arrays quickly
void display(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << endl;
}

int main() {
    int n;

    // --- Part 1: Bubble Sort ---
    cout << "--- Bubble Sort ---\nEnter number of elements: ";
    cin >> n;
    vector<int> bubbleArr(n);
    cout << "Enter " << n << " elements:\n";
    for (int &x : bubbleArr) cin >> x;

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (bubbleArr[j] > bubbleArr[j + 1]) swap(bubbleArr[j], bubbleArr[j + 1]);

    cout << "Sorted array in ascending order:\n";
    display(bubbleArr);

    // --- Part 2: Insertion Sort ---
    cout << "\n--- Insertion Sort ---\nEnter 5 elements:\n";
    vector<int> insertArr(5);
    for (int &x : insertArr) cin >> x;

    for (int i = 1; i < 5; i++) {
        int key = insertArr[i], j = i - 1;
        while (j >= 0 && insertArr[j] > key) {
            insertArr[j + 1] = insertArr[j];
            j--;
        }
        insertArr[j + 1] = key;
    }

    cout << "Sorted output:\n";
    display(insertArr);

    return 0;
}
