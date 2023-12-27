// Solve 2023-09-02

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    priority_queue<int> pq_maxtop[12];

    for (int i = 0; i < n; i++) {
        int p, w;
        cin >> p >> w;

        pq_maxtop[p].push(w);
    }

    int ans = 0;

    for (int p = 1; p <= 11; p++) {
        if (pq_maxtop[p].empty()) continue;

        for (int j = 0; j < k; j++) {
            if (pq_maxtop[p].top() == 1) break;

            int x = pq_maxtop[p].top();
            pq_maxtop[p].pop();
            pq_maxtop[p].push(x - 1);
        }

        ans += pq_maxtop[p].top();
    }

    cout << ans << '\n';

    return 0;
}
