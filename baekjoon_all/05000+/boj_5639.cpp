// Solve 2023-02-14

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

const int MAX_N = 10000;
int n, preorder[MAX_N];

void print_postorder(int pre_l, int pre_r) {
    if (pre_l > pre_r) return;

    int root_val = preorder[pre_l];
    int pre_next_l = lower_bound(preorder + (pre_l + 1), preorder + (pre_r + 1), root_val) - preorder;

    print_postorder(pre_l + 1, pre_next_l - 1);
    print_postorder(pre_next_l, pre_r);
    cout << root_val << '\n';
}

int main() {
    FASTIO;

    int x;
    while (cin >> x) {
        preorder[n] = x;
        n++;
    }

    print_postorder(0, n - 1);

    return 0;
}