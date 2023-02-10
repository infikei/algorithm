// Solve 2023-02-10

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

int n, a[100001], b[100001], c[100001];
vector<int> dp;

int main() {
    FASTIO;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        b[x] = i;
    }
    for (int i = 1; i <= n; i++) {
        c[i] = b[a[i]];
    }

    // 이제, LIS 문제로 바뀌었다.
    dp.push_back(c[1]);
    for (int i = 2; i <= n; i++) {
        int pos = lower_bound(ALL(dp), c[i]) - dp.begin();
        if (pos == SIZE(dp)) {
            dp.push_back(c[i]);
        }
        else if (c[i] < dp[pos]) {
            dp[pos] = c[i];
        }
    }
    cout << SIZE(dp) << '\n';

    return 0;
}