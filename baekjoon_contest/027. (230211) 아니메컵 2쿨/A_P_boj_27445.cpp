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

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    int r = 0, c = INF;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x < c) {
            c = x;
            r = i;
        }
    }
    c++;
    for (int i = 1; i < m; i++) {
        int x;
        cin >> x;
    }

    cout << r << ' ' << c << '\n';

    return 0;
}