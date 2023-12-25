// Solve 2023-02-11
// Update 2023-12-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const int INF = 1e9;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    int r = 0, c = INF;

    for (int i = 1; i <= n; i++) {
        int dist;
        cin >> dist;

        if (dist < c) {
            c = dist + 1;
            r = i;
        }
    }

    for (int i = 1; i < m; i++) {
        int dist;
        cin >> dist;
    }

    cout << r << ' ' << c << '\n';

    return 0;
}
