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
    tmp1.assign(n - 1, ' ');
    tmp2 = "*";
    cout << tmp1 << tmp2 << '\n';
    for (int iter = n - 1; iter > 0; iter--) {
        tmp1.pop_back();
        tmp2 += "**";
        cout << tmp1 << tmp2 << '\n';
    }
    for (int iter = n - 1; iter > 0; iter--) {
        tmp1 += ' ';
        tmp2.pop_back();
        tmp2.pop_back();
        cout << tmp1 << tmp2 << '\n';
    }

    return 0;
}