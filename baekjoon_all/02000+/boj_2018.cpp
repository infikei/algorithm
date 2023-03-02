// Solve 2023-03-02

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

    int n;
    cin >> n;

    int ans = 0;
    int i = 1, j = 2, now = 1;
    while (i <= n) {
        if (now < n) {
            now += j;
            j++;
        }
        else if (now > n) {
            now -= i;
            i++;
        }
        else {
            ans++;
            now -= i;
            i++;
            now += j;
            j++;
        }
    }

    cout << ans << '\n';

    return 0;
}