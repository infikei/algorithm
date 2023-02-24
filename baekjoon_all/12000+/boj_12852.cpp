// Solve 2022-07-26
// Update 2023-02-09

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

const int MAX_N = 1e6;
int n, dp_count[MAX_N + 1], dp_parent[MAX_N + 1];

int main() {
    FASTIO;

    cin >> n;

    dp_count[1] = 0;
    for (int i = 2; i <= n; i++) {
        dp_count[i] = dp_count[i - 1];
        dp_parent[i] = i - 1;

        if (i % 2 == 0) {
            int ni = i / 2;
            if (dp_count[ni] < dp_count[i]) {
                dp_count[i] = dp_count[ni];
                dp_parent[i] = ni;
            }
        }

        if (i % 3 == 0) {
            int ni = i / 3;
            if (dp_count[ni] < dp_count[i]) {
                dp_count[i] = dp_count[ni];
                dp_parent[i] = ni;
            }
        }

        dp_count[i]++;
    }

    cout << dp_count[n] << '\n';
    int cur = n;
    while (cur != 1) {
        cout << cur << ' ';
        cur = dp_parent[cur];
    }
    cout << cur << '\n';

    return 0;
}