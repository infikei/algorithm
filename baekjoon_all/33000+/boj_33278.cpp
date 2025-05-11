// Solve 2025-05-11

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    FASTIO;

    int n, t;
    cin >> n >> t;

    vector<pll> trees(n);

    for (int i = 0; i < n; i++) {
        cin >> trees[i].first >> trees[i].second;
    }

    sort(trees.begin(), trees.end());

    ll shadow_sum = 0;
    ll prev_tree = trees[0].second;

    for (int i = 1; i < n; i++) {
        ll shadow_height = prev_tree - (trees[i].first - trees[i - 1].first) * t;
        shadow_sum += max(0LL, min(shadow_height, trees[i].second));
        prev_tree = max(shadow_height, trees[i].second);
    }

    cout << shadow_sum << '\n';

    return 0;
}
