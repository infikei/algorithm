#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)1e9
#define LLINF (ll)4e18
using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using pii = pair<int, int>;

int n, k, ans;
vector<pii> vec;

void dfs(int depth = 0, int start = 1, int hakjum = 0) {
    if (depth == n) {
        if (hakjum == k) {
            ans++;
        }
        return;
    }
    if (hakjum > k) {
        return;
    }

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
        vec.push_back({w * 100 + s, w * 100 + e});
    }
    sort(ALL(vec));

    dfs();
    cout << ans << '\n';

    return 0;
}