// Solve 2024-05-19

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

    priority_queue<int> pq_maxtop;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq_maxtop.push(x);
    }

    int ans = 0;

    for (int i = 0; i < min(m, (n + 1) / 2); i++) {
        if (pq_maxtop.top() <= 0) break;

        ans += pq_maxtop.top();
        pq_maxtop.pop();
    }

    cout << ans << '\n';

    return 0;
}
