// Solve 2025-11-10

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int t[100001];
priority_queue<pii, vector<pii>, greater<pii>> p[100001];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;
    int t_sum = 0;

    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        t_sum += t[i];
    }

    int w_max = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        w_max = max(w_max, w);

        // 각 지점마다 해당 지점에서 승차할 승객 정보 저장
        p[u].emplace(w, v);
    }

    int cur = w_max / t_sum * t_sum - t_sum * 2;
    cur = max(0, cur);
    set<int> v_set;

    for (int u = 1;; u = (u == n ? 1 : u + 1)) {
        v_set.erase(u); // 승객 하차

        while (!p[u].empty() && p[u].top().first <= cur) {
            // 승객을 승차시키고, 하차 정보 저장
            v_set.insert(p[u].top().second);
            p[u].pop();
            m--;
        }

        // 현재 탑승한 승객과 앞으로 탑승할 승객이 없다면 운행 종료
        if (m == 0 && v_set.empty()) break;

        cur += t[u];
    }

    cout << cur << '\n';
    return 0;
}
