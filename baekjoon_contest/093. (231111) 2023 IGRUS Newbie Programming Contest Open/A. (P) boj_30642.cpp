// Solve 2023-11-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, k;
    string s;
    cin >> n >> s >> k;

    int ans = k;

    if (s == "annyong") {
        if (k % 2 == 0) {
            if (ans == n) ans--;
            else ans++;
        }
    }
    else {
        if (k % 2 == 1) {
            if (ans == n) ans--;
            else ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
