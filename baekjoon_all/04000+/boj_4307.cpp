// Solve 2023-02-03
// Update 2023-02-08

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int length, n;
        cin >> length >> n;

        int ans_min = 0, ans_max = 0;
        for (int i = 0; i < n; i++) {
            int pos;
            cin >> pos;
            ans_min = max(ans_min, min(pos, length - pos));
            ans_max = max(ans_max, max(pos, length - pos));
        }
        cout << ans_min << ' ' << ans_max << '\n';
    }

    return 0;
}