// Solve 2022-06-05
// Update 2023-03-01

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using pii = pair<int, int>;

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int n, m;
        cin >> n >> m;

        queue<pii> q;
        priority_queue<int> pq_maxtop;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            q.push({ x, i });
            pq_maxtop.push(x);
        }

        int ans = 0;
        while (true) {
            pii now = q.front();
            q.pop();

            if (now.first == pq_maxtop.top()) {
                pq_maxtop.pop();
                ans++;
                if (now.second == m) break;
            }
            else {
                q.push(now);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}