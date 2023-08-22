// Solve 2023-05-20 (BOJ First Solved)
// Update 2023-08-22

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    priority_queue<int, vector<int>, greater<int> > pq_mintop[200001];

    for (int p = 1; p <= n; p++) {
        int wish_cnt;
        cin >> wish_cnt;

        for (int i = 0; i < wish_cnt; i++) {
            int wish;
            cin >> wish;

            pq_mintop[wish].push(p);
        }
    }

    int ans[100001] = { 0 };

    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;

        if (pq_mintop[b].empty()) continue;
        int p = pq_mintop[b].top();
        pq_mintop[b].pop();
        ans[p]++;
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }

    cout << '\n';

    return 0;
}
