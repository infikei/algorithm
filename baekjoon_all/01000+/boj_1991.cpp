// Solve 2023-01-19
// Update 2024-02-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Node{
    int left, right;
};

Node nodes[26];

void preorder(int cur = 0) {
    if (cur == -1) return;

    cout << (char)('A' + cur);
    preorder(nodes[cur].left);
    preorder(nodes[cur].right);
}

void inorder(int cur = 0) {
    if (cur == -1) return;

    inorder(nodes[cur].left);
    cout << (char)('A' + cur);
    inorder(nodes[cur].right);
}

void postorder(int cur = 0) {
    if (cur == -1) return;

    postorder(nodes[cur].left);
    postorder(nodes[cur].right);
    cout << (char)('A' + cur);
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char cur, left, right;
        cin >> cur >> left >> right;

        nodes[cur - 'A'].left = left == '.' ? -1 : left - 'A';
        nodes[cur - 'A'].right = right == '.' ? -1 : right - 'A';
    }

    preorder();
    cout << '\n';

    inorder();
    cout << '\n';

    postorder();
    cout << '\n';

    return 0;
}
