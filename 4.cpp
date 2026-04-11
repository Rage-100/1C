#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    unsigned freq;
    Node *left, *right;
    Node(char d, unsigned f) : data(d), freq(f), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) { return a->freq > b->freq; }
};

void printCodes(Node* root, string code = "") {
    if (!root) return;
    if (!root->left && !root->right)
        cout << root->data << ": " << code << "\n";
    printCodes(root->left,  code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    char arr[] = {'A','B','C','D','E','F'};
    int  freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr) / sizeof(arr[0]);

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (int i = 0; i < size; i++)
        pq.push(new Node(arr[i], freq[i]));

    while (pq.size() > 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();
        Node *top = new Node('$', left->freq + right->freq);
        top->left = left; top->right = right;
        pq.push(top);
    }

    cout << "Huffman Codes are:\n";
    printCodes(pq.top());
    return 0;
}
