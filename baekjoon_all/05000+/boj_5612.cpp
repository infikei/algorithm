// Solve 2023-03-04

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

    int n, m;
    cin >> n >> m;

    int m_min = m, m_max = m;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        m += (u - v);
        m_min = min(m_min, m);
        m_max = max(m_max, m);
    }

    if (m_min < 0) {
        cout << 0 << '\n';
    }
    else {
        cout << m_max << '\n';
    }

    return 0;
}