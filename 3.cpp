#include <iostream> 
#include <ctime> 
using namespace std; 
  
void bubble(int a[], int n){ 
    for(int i=0;i<n-1;i++) 
        for(int j=0;j<n-i-1;j++) 
            if(a[j]>a[j+1]) swap(a[j],a[j+1]); 
} 
  
void insertion(int a[], int n){ 
    for(int i=1;i<n;i++){ 
        int key=a[i], j=i-1; 
        while(j>=0 && a[j]>key) a[j+1]=a[j], j--; 
        a[j+1]=key; 
    } 
} 
  
int main(){ 
    int n=1000, a[n], b[n]; 
    for(int i=0;i<n;i++) a[i]=b[i]=rand()%1000; 
  
    clock_t t=clock(); bubble(a,n); 
    cout<<"Bubble sort time: "<<(double)(clock()-t)/CLOCKS_PER_SEC<<"\n"; 
  
    t=clock(); insertion(b,n); 
    cout<<"Insertion sort time: "<<(double)(clock()-t)/CLOCKS_PER_SEC ; 
}
