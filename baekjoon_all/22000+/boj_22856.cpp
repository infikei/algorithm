// Solve 2024-02-12

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

int main() {
    FASTIO;

    int n;
    cin >> n;

    Node tree[100001];

    for (int i = 0; i < n; i++) {
        int cur, left, right;
        cin >> cur >> left >> right;

        tree[cur].left = left;
        tree[cur].right = right;
    }

    int ans = (n - 1) * 2;

    for (int cur_node = 1; cur_node != -1; cur_node = tree[cur_node].right) {
        ans--;
    }

    cout << ++ans << '\n';

    return 0;
}
