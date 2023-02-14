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

const int MAX_N = 100000;
int n, inorder[MAX_N + 1], inorder_idx[MAX_N + 1], postorder[MAX_N + 1];

void print_preorder(int in_l, int in_r, int post_l, int post_r) {
    if (in_l > in_r || post_l > post_r) return;

    int root_val = postorder[post_r];
    int root_idx = inorder_idx[root_val];
    int left_size = root_idx - in_l;
    int right_size = in_r - root_idx;

    cout << root_val << ' ';
    print_preorder(in_l, root_idx - 1, post_l, post_l + left_size - 1);
    print_preorder(root_idx + 1, in_r, post_r - right_size, post_r - 1);
}

int main() {
    FASTIO;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> inorder[i];
        inorder_idx[inorder[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> postorder[i];
    }

    print_preorder(1, n, 1, n);

    return 0;
}