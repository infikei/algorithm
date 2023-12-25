// Solve 2023-02-19

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

int n, l, a[1000000];

int main() {
    FASTIO;

    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int cur_sum = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        cur_sum += a[i];
        if (i >= l) {
            cur_sum -= a[i - l];
        }
        if (cur_sum >= 129 && cur_sum <= 138) {
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}