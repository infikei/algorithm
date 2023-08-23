// Solve 2023-01-07
// Update 2023-08-23

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

    unordered_map<string, string> hs;
    string site, password;

    for (int i = 0; i < n; i++) {
        cin >> site >> password;
        hs[site] = password;
    }

    for (int i = 0; i < m; i++) {
        cin >> site;
        cout << hs[site] << '\n';
    }

    return 0;
}
