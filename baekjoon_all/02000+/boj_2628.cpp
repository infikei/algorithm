// Solve 2023-02-22

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
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

const int MAX_N = 100;
bool sero[MAX_N], garo[MAX_N];

int main() {
    FASTIO;

    int n, m, k;
    cin >> m >> n >> k;
    for (int i = 0; i < k; i++) {
        int cmd, x;
        cin >> cmd >> x;
        if (cmd == 0) {
            sero[x] = true;
        }
        else {
            garo[x] = true;
        }
    }

    int max_sero = 0, max_garo = 0, prev = 0;
    for (int i = 1; i < n; i++) {
        if (sero[i]) {
            max_sero = max(max_sero, i - prev);
            prev = i;
        }
    }
    max_sero = max(max_sero, n - prev);

    prev = 0;
    for (int i = 1; i < m; i++) {
        if (garo[i]) {
            max_garo = max(max_garo, i - prev);
            prev = i;
        }
    }
    max_garo = max(max_garo, m - prev);

    cout << max_sero * max_garo << '\n';

    return 0;
}