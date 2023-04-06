// Solve 2022-11-06
// Update 2023-04-05

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

    int n, b;
    cin >> n >> b;

    string ans;

    while (n > 0) {
        int tmp = n % b;
        if (tmp > 9) {
            ans = (char)('A' + tmp - 10) + ans;
        }
        else {
            ans = (char)('0' + tmp) + ans;
        }

        n /= b;
    }

    cout << ans << '\n';

    return 0;
}
