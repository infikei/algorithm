// Solve 2023-02-11

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

int n, m;
bool check_pages[101];

int main() {
    FASTIO;

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        check_pages[x] = true;
    }

    int ans = 0, prev_idx = -100;
    for (int i = 1; i <= n; i++) {
        if (check_pages[i]) continue;

        ans += min(7, (i - prev_idx) * 2);
        prev_idx = i;
    }

    cout << ans << '\n';

    return 0;
}