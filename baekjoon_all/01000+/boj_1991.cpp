// Solve 2023-01-19
// Update 2023-02-13

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

const int MAX_N = 26;
int n, tree[MAX_N][2];

void preorder(int now = 0) {
    if (now == -1) return;
    cout << (char)('A' + now);
    preorder(tree[now][0]);
    preorder(tree[now][1]);
}

void inorder(int now = 0) {
    if (now == -1) return;
    inorder(tree[now][0]);
    cout << (char)('A' + now);
    inorder(tree[now][1]);
}

void postorder(int now = 0) {
    if (now == -1) return;
    postorder(tree[now][0]);
    postorder(tree[now][1]);
    cout << (char)('A' + now);
}

int main() {
    FASTIO;

    cin >> n;
    for (int i = 0; i < n; i++) {
        char parent, lchild, rchild;
        cin >> parent >> lchild >> rchild;
        tree[parent - 'A'][0] = (lchild == '.' ? -1 : lchild - 'A');
        tree[parent - 'A'][1] = (rchild == '.' ? -1 : rchild - 'A');
    }

    preorder(); cout << '\n';
    inorder(); cout << '\n';
    postorder(); cout << '\n';

    return 0;
}