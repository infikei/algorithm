// Solve 2023-05-06

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

ll t[100000];

int main() {
    FASTIO;

    int n;
    ll m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    ll left = 0, right = 1e18;
    while (left + 1 < right) {
        ll mid = (left + right) >> 1;
        ll val = 0;
        for (int i = 0; i < n; i++) {
            val += mid / t[i];
            if (val >= m) {
                break;
            }
        }

        if (val >= m) {
            right = mid;
        }
        else {
            left = mid;
        }
    }

    cout << right << '\n';

    return 0;
}
