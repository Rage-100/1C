#include <iostream> 
using namespace std; 
  
int binarySearch(int arr[], int left, int right, int key) { 
    if (left > right) 
        return -1;  // not found 
  
    int mid = left + (right - left) / 2; 
  
    if (arr[mid] == key) 
        return mid; 
    else if (arr[mid] > key) 
        return binarySearch(arr, left, mid - 1, key); 
    else 
        return binarySearch(arr, mid + 1, right, key); 
} 
  
int main() { 
    int arr[] = {1, 3, 5, 7, 9}; 
    int n = 5, key = 7; 
  
    int result = binarySearch(arr, 0, n - 1, key); 
  
    if (result != -1) 
        cout << "Found at index " << result; 
    else 
        cout << "Not found"; 
  
    return 0; 
}
