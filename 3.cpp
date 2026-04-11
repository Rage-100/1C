#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

int n, arr1[100], arr2[100];

void print(int a[]) { for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<"\n"; }

void bubble(int a[]) { for(int i=0;i<n-1;i++) for(int j=0;j<n-i-1;j++) if(a[j]>a[j+1]) swap(a[j],a[j+1]); }

void insertion(int a[]) { for(int i=1;i<n;i++) { int k=a[i],j=i-1; while(j>=0&&a[j]>k) a[j+1]=a[j--]; a[j+1]=k; } }

void run(void(*fn)(int[]), int a[], const string& name) {
    clock_t s=clock(); fn(a); double t=(double)(clock()-s)/CLOCKS_PER_SEC;
    cout<<"\n["<<name<<"] Sorted: "; print(a);
    cout<<"Time: "<<fixed<<setprecision(10)<<t<<" sec | Time: O(n^2) | Space: O(1)\n";
}

int main() {
    cout<<"Enter number of elements: "; cin>>n;
    cout<<"Enter "<<n<<" elements:\n";
    for(int i=0;i<n;i++) { cin>>arr1[i]; arr2[i]=arr1[i]; }
    run(bubble,    arr1, "Bubble Sort");
    run(insertion, arr2, "Insertion Sort");
}
