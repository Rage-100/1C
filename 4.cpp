#include <iostream> 
#include <queue> 
using namespace std; 
struct Node { char ch; int freq; Node *left, *right; Node(char c, int f) { ch = c; freq = f; left = 
right = NULL; } }; 
struct cmp { bool operator()(Node* a, Node* b) { return a->freq > b->freq; // min-heap } }; 
void printCodes(Node* root, string code) { if (!root) return; 
if (root->ch != '$')  // leaf node 
    cout << root->ch << ": " << code << endl; 
 
printCodes(root->left, code + "0"); 
printCodes(root->right, code + "1"); 
  
} 
int main() { char ch[] = {'a','b','c','d'}; int freq[] = {5,9,12,13}; int n = 4; 
priority_queue<Node*, vector<Node*>, cmp> pq; 
 
for(int i=0;i<n;i++) 
    pq.push(new Node(ch[i], freq[i])); 
 
while(pq.size() > 1) { 
    Node *l = pq.top(); pq.pop(); 
    Node *r = pq.top(); pq.pop(); 
 
    Node *sum = new Node('$', l->freq + r->freq); 
    sum->left = l; 
    sum->right = r; 
 
    pq.push(sum); 
} 
 
printCodes(pq.top(), ""); 
return 0; 
  
}
