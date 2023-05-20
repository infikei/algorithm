// Solve 2023-05-19

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

int calc_gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }

    return calc_gcd(b, a % b);
}

int main() {
    FASTIO;

    string s, t;
    cin >> s >> t;

    int ss = SIZE(s), tt = SIZE(t);

    int rr = calc_gcd(ss, tt);
    string r = s.substr(0, rr);

    int ans = 1;
    for (int i = 0; i < ss; i += rr) {
        for (int j = 0; j < rr; j++) {
            if (s[i + j] != r[j]) {
                ans = 0;
                break;
            }
        }
        if (ans == 0) {
            break;
        }
    }

    for (int i = 0; i < tt; i += rr) {
        for (int j = 0; j < rr; j++) {
            if (t[i + j] != r[j]) {
                ans = 0;
                break;
            }
        }
        if (ans == 0) {
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}
