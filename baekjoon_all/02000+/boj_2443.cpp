// Solve 2023-02-14

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

    int n;
    cin >> n;

    string tmp1, tmp2;
    tmp2.assign(n * 2 - 1, '*');
    for (int row = 1; row <= n; row++) {
        cout << tmp1 << tmp2 << '\n';
        tmp1 += ' ';
        tmp2.pop_back();
        tmp2.pop_back();
    }

    return 0;
}