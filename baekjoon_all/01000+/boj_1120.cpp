// Solve 2024-01-14

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string a, b;
    cin >> a >> b;

    int ans = 51;

    for (int diff = 0; diff <= SIZE(b) - SIZE(a); diff++) {
        int val = 0;

        for (int i = 0; i < SIZE(a); i++) {
            if (a[i] != b[i + diff]) {
                val++;
            }
        }

        ans = min(ans, val);
    }

    cout << ans << '\n';

    return 0;
}
