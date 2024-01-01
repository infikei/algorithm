// Solve 2023-12-31

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

    int ans = -1;

    for (int k = 1000000; k >= 4; k--) {
        string k_str = to_string(k);

        bool check = true;

        for (char &c : k_str) {
            if (c != '4' && c != '7') {
                check = false;
            }
        }

        if (check && k <= n) {
            ans = k;
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}
