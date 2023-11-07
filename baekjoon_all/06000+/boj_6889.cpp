// Solve 2023-11-07

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    string s[5], w[5];

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> w[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << s[i] << " as " << w[j] << '\n';
        }
    }

    return 0;
}
