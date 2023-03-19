// Solve 2023-03-18

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

int main() {
    FASTIO;

    int n, m, j;
    cin >> n >> m >> j;

    int ans = 0, left = 1, right = m;
    for (int k = 0; k < j; k++) {
        int drop;
        cin >> drop;

        int move = 0;
        if (drop < left) {
            move = drop - left;
        }
        else if (right < drop) {
            move = drop - right;
        }
        ans += abs(move);
        left += move;
        right += move;
    }
    cout << ans << '\n';

    return 0;
}
