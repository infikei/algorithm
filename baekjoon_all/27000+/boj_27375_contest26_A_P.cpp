// Solve 2023-02-04
// Update 2023-08-22

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;

int n, k, ans;
vector<pii> vec;

void dfs(int depth = 0, int start = 1, int hakjum = 0) {
    if (depth == n) {
        if (hakjum == k) ans++;
        return;
    }

    if (hakjum > k) return;

    if (vec[depth].first < 500 && vec[depth].first >= start) {
        dfs(depth + 1, vec[depth].second + 1, hakjum + vec[depth].second - vec[depth].first + 1);
    }

    dfs(depth + 1, start, hakjum);
}

int main() {
    FASTIO;

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int w, s, e;
        cin >> w >> s >> e;

        vec.push_back({ w * 100 + s, w * 100 + e });
    }

    sort(vec.begin(), vec.end());

    dfs();

    cout << ans << '\n';

    return 0;
}
