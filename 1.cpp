#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

long long fact_iter(int n) { long long r=1; for(int i=1;i<=n;i++) r*=i; return r; }
long long fact_rec(int n)  { return n<=1 ? 1 : n*fact_rec(n-1); }

void benchmark(const string& label, long long(*fn)(int), int n, const string& space) {
    clock_t s = clock();
    long long result = fn(n);
    double t = (double)(clock()-s)/CLOCKS_PER_SEC;
    cout << "\n[" << label << "] Factorial of " << n << " = " << result
         << "\n[" << label << "] Time taken: " << fixed << setprecision(10) << t << " seconds"
         << "\n[" << label << "] Space Complexity ≈ " << space << "\n";
}

int main() {
    int n;
    cout << "Enter a number to find factorial: "; cin >> n;
    benchmark("Iterative", fact_iter, n, "O(1)");
    benchmark("Recursive", fact_rec,  n, "O(n) (due to recursion stack)");
}
