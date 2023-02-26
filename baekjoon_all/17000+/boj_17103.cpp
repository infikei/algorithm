// Solve 2023-02-26

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

const int MAX_N = 1000000;
vector<bool> check(MAX_N + 1);

int main() {
    FASTIO;

    check[0] = check[1] = true;
    for (int i = 2; i <= MAX_N; i++) {
        if (!check[i]) {
            for (int j = (i << 1); j <= MAX_N; j += i) {
                check[j] = true;
            }
        }
    }

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int n;
        cin >> n;

        int ans = 0;
        for (int i = 2, i_end = (n >> 1); i <= i_end; i++) {
            if (!check[i] && !check[n - i]) {
                ans++;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}