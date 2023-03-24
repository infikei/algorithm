// Solve 2022-07-30
// Update 2023-03-23

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

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int scores[5];
        for (int i = 0; i < 5; i++) {
            cin >> scores[i];
        }

        sort(scores, scores + 5);

        if (scores[3] - scores[1] >= 4) {
            cout << "KIN\n";
        }
        else {
            int ans = scores[1] + scores[2] + scores[3];
            cout << ans << '\n';
        }
    }

    return 0;
}
