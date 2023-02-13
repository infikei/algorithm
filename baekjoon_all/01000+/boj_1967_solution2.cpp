// Solve 2023-02-13

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
using pii = pair<int, int>;

const int MAX_N = 10000;
int n, ans;
vector<pii> tree[MAX_N + 1];

int dfs(int now = 1) {
    if (tree[now].empty()) {
        return 0;
    }

    priority_queue<pii, vector<pii>, greater<pii> > pq_mintop;
    for (auto next : tree[now]) {
        int next_node = next.first;
        int next_dist = dfs(next_node) + next.second;
        pq_mintop.push({ next_dist, next_node });
        if (SIZE(pq_mintop) > 2) {
            pq_mintop.pop();
        }
    }

    auto b = pq_mintop.top();
    pq_mintop.pop();
    if (pq_mintop.empty()) {
        ans = max(ans, b.first);
        return b.first;
    }

    auto a = pq_mintop.top();
    ans = max(ans, a.first + b.first);
    return a.first;
}

int main() {
    FASTIO;

    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        tree[a].push_back({ b, d });
    }

    dfs();

    cout << ans << '\n';

    return 0;
}