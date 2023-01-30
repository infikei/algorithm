#include <iostream>
#include <vector>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

vector<vector<int> > tree;

void preorder(int node = 0) {
    if (node == -1) return;
    cout << (char)('A' + node);
    preorder(tree[node][0]);
    preorder(tree[node][1]);
}

void inorder(int node = 0) {
    if (node == -1) return;
    inorder(tree[node][0]);
    cout << (char)('A' + node);
    inorder(tree[node][1]);
}

void postorder(int node = 0) {
    if (node == -1) return;
    postorder(tree[node][0]);
    postorder(tree[node][1]);
    cout << (char)('A' + node);
}

int main() {
    fastio;

    int n;
    cin >> n;

    tree.assign(n, vector<int>(2, -1));
    for (int i = 0; i < n; i++) {
        char parent, left, right;
        cin >> parent >> left >> right;
        if (left != '.') tree[parent - 'A'][0] = left - 'A';
        if (right != '.') tree[parent - 'A'][1] = right - 'A';
    }

    preorder(); cout << '\n';
    inorder(); cout << '\n';
    postorder(); cout << '\n';

    return 0;
}