#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

#define INF 9999
#define MAX 100

struct Edge { int u, v, w; };

// Union-Find
int find(int p[], int i){ return p[i]==i ? i : p[i]=find(p,p[i]); }
void unite(int p[], int a, int b){ p[find(p,a)] = find(p,b); }

// Prim's
void prim(int c[MAX][MAX], int n){
    bool s[MAX]={0}; s[0]=1;
    int e=0, total=0;

    cout << "\nPrim's Algorithm Edges:\n";
    while(e<n-1){
        int min=INF,x=0,y=0;
        for(int i=0;i<n;i++) if(s[i])
            for(int j=0;j<n;j++)
                if(!s[j] && c[i][j]<min)
                    min=c[i][j], x=i, y=j;

        cout<<"Edge "<<e+1<<": ("<<x<<" - "<<y<<") cost: "<<c[x][y]<<"\n";
        total+=c[x][y]; s[y]=1; e++;
    }
    cout<<"Total cost using Prim's Algorithm = "<<total<<"\n";
}

// Kruskal's
void kruskal(int c[MAX][MAX], int n){
    vector<Edge> ed;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(c[i][j]!=INF) ed.push_back({i,j,c[i][j]});

    sort(ed.begin(),ed.end(),[](Edge a,Edge b){return a.w<b.w;});

    int p[MAX]; for(int i=0;i<n;i++) p[i]=i;
    int total=0,cnt=0;

    cout << "\nKruskal's Algorithm Edges:\n";
    for(auto &e:ed){
        if(find(p,e.u)!=find(p,e.v)){
            cout<<"Edge "<<cnt+1<<": ("<<e.u<<" - "<<e.v<<") cost: "<<e.w<<"\n";
            total+=e.w; unite(p,e.u,e.v);
            if(++cnt==n-1) break;
        }
    }
    cout<<"Total cost using Kruskal's Algorithm = "<<total<<"\n";
}

// Main
int main(){
    int n,c[MAX][MAX];
    cout<<"Enter number of vertices: ";
    cin>>n;

    cout<<"Enter the cost adjacency matrix (use 0 for no edge):\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            cin>>c[i][j];
            if(c[i][j]==0 && i!=j) c[i][j]=INF;
        }

    clock_t t;
    t=clock(); prim(c,n);
    double t1=(double)(clock()-t)/CLOCKS_PER_SEC;

    t=clock(); kruskal(c,n);
    double t2=(double)(clock()-t)/CLOCKS_PER_SEC;

    cout<<"\nExecution Time Comparison:";
    cout<<"\nPrim's Algorithm Time: "<<t1;
    cout<<"\nKruskal's Algorithm Time: "<<t2<<"\n";
}
