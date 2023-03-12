// Solve 2023-03-11

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

int calc_log2(int k) {
    int res = -1;
    while (k > 0) {
        res++;
        k >>= 1;
    }
    return res;
}

int main() {
    FASTIO;

    int n, m, k;
    cin >> n >> m >> k;

    int log_n = calc_log2(n);
    int log_k = calc_log2(k);

    int ans = min(log_k + m, log_n);
    cout << ans << '\n';

    return 0;
}