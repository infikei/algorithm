// Solve 2023-02-14
// Update 2024-03-03

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int pre_order[10000];

void print_post_order(int i_begin, int i_end) {
    if (i_begin > i_end) return;

    int i_mid = upper_bound(pre_order + (i_begin + 1), pre_order + (i_end + 1), pre_order[i_begin]) - pre_order;
    print_post_order(i_begin + 1, i_mid - 1);
    print_post_order(i_mid, i_end);
    cout << pre_order[i_begin] << '\n';
}

int main() {
    FASTIO;

    int n = 0;
    int x;

    while (cin >> x) {
        pre_order[n++] = x;
    }

    print_post_order(0, n - 1);

    return 0;
}
