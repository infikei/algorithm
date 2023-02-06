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

int main() {
    FASTIO;

    const int N_MAX = 1e6;
    int n, m;
    cin >> n >> m;
    int trees[N_MAX], highest_tree = 0;
    for (int i = 0; i < n; i++) {
        cin >> trees[i];
        highest_tree = max(highest_tree, trees[i]);
    }

    ll low = 0, high = highest_tree;
    while (low + 1 < high) {
        ll mid = (low + high) / 2;

        ll cut_trees_sum = 0;
        for (int i = 0; i < n; i++) {
            ll tree = trees[i];
            if (tree > mid) {
                cut_trees_sum += (tree - mid);
            }
        }
        if (cut_trees_sum >= m) {
            low = mid;
        }
        else {
            high = mid;
        }
    }

    cout << low << '\n';

    return 0;
}