// Solve 2022-06-17
// Update 2023-03-03

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

    string n;
    int b;
    cin >> n >> b;

    int ans = 0;
    for (auto ch : n) {
        ans *= b;
        if (ch > '9') {
            ans += ch - 'A' + 10;
        }
        else {
            ans += ch - '0';
        }
    }
    cout << ans << '\n';

    return 0;
}