// Solve 2024-04-14

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    while (true) {
        int n;
        cin >> n;

        if (n == -1) break;

        int dist = 0, prev_t = 0;

        for (int i = 0; i < n; i++) {
            int v, t;
            cin >> v >> t;

            dist += v * (t - prev_t);
            prev_t = t;
        }

        cout << dist << " miles\n";
    }

    return 0;
}
