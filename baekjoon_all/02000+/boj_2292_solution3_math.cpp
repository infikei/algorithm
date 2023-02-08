// Solve 2023-02-08

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

    ll n;
    cin >> n;

    ll tmp = ceil((n - 1) / 6.0);
    ll ans = ceil((sqrt(tmp * 8 + 1) - 1) / 2) + 1;
    cout << ans << '\n';

    // 27436번에서는 틀리는 것으로 보았을 때, n이 문제의 범위를 넘어서는 큰 수일 때는 오차가 있는 것으로 보임.
    // 더 정확한 풀이는 solution4를 참고할 것.

    return 0;
}