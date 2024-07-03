// Solve 2023-12-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        ll x = stoll(s.substr(1));

        if (s[0] == '+') {
            ans += x;
        }
        else {
            ans -= x;
        }

        cout << (ans == 0 ? 0 : (1ll << (int)(log2(ans)))) << '\n';
    }

    return 0;
}
