// Solve 2022-06-03
// Update 2023-05-11

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

unordered_map<int, int> hs;

int main() {
    FASTIO;

    int n, m, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        hs[x]++;
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x;
        cout << hs[x] << ' ';
    }
    cout << '\n';

    return 0;
}
