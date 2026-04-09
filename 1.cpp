#include <iostream>  
using namespace std;  
// ---------------- ITERATIVE FUNCTION ----------------  
  
int J(int n) {  
    int sum = 0;               
    for (int i = 1; i <= n; i++)  
  {  
        sum += i;          
    }  
    return sum;  
}  
// ---------------- RECURSIVE FUNCTION ----------------  
  
int A(int n)  
{  
    if (n == 1)            
        return 1;  
    return n + A(n - 1);  
}  
// ---------------- FUNCTION TO DISPLAY ANALYSIS ----------------  
void S()  
{  
    cout << "\n--- Iterative Function Analysis ---\n";  
    cout << "Code Pattern: for loop running n times\n";  
    cout << "Time Complexity:\n";  
    cout << "  Big-O: O(n)\n";  
    cout << "  Theta: Θ(n)\n";  
    cout << "  Omega: Ω(n)\n";  
    cout << "Space Complexity: O(1) (constant memory)\n";  
}  
void T()  
{  
    cout << "\n--- Recursive Function Analysis ---\n";  
    cout << "Code Pattern: recursive calls decreasing by 1\n";  
    cout << "Time Complexity:\n";  
    cout << "  Big-O: O(n)\n";  
    cout << "  Theta: Θ(n)\n";  
    cout << "  Omega: Ω(n)\n";  
    cout << "Space Complexity: O(n) (due to recursion stack)\n";  
}  
// ---------------- MAIN FUNCTION ----------------  
  
int main() 
 {  
    int n;  
    cout << "Enter value of n: ";  
    cin >> n;  
     
    int JA = J(n);  
    int AB = A(n);  
     
    cout << "\nIterative Sum = " << JA << endl;  
    cout << "Recursive Sum = " << AB << endl;  
     
    S();  
    T();  
    return 0;  
} 
