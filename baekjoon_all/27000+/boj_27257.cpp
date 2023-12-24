// Solve 2023-09-29
// Update 2023-12-24

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int k;
    cin >> k;

    string s = to_string(k);

    while (s.back() == '0') {
        s.pop_back();
    }

    int ans = 0;

    for (char &c : s) {
        if (c == '0') {
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
