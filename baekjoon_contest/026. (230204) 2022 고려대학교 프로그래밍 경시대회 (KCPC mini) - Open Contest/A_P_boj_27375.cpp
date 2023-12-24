// Solve 2023-02-04
// Update 2023-12-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;

void dfs(int n, int k, int &ans, vector<pii> &lectures, int depth = 0, int start = 1, int hakjum = 0) {
    if (depth == n) {
        if (hakjum == k) ans++;
        return;
    }

    if (hakjum > k) return;

    if (lectures[depth].first < 500 && lectures[depth].first >= start) {
        int next_start = lectures[depth].second + 1;
        int next_hakjum = hakjum + lectures[depth].second - lectures[depth].first + 1;
        dfs(n, k, ans, lectures, depth + 1, next_start, next_hakjum);
    }

    dfs(n, k, ans, lectures, depth + 1, start, hakjum);
}

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    vector<pii> lectures;

    for (int i = 0; i < n; i++) {
        int w, s, e;
        cin >> w >> s >> e;

        lectures.emplace_back(w * 100 + s, w * 100 + e);
    }

    sort(lectures.begin(), lectures.end());
    int ans = 0;
    dfs(n, k, ans, lectures);

    cout << ans << '\n';

    return 0;
}
