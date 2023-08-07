// Solve 2022-11-05
// Update 2023-08-07

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

string S;

int main() {
    FASTIO;

    string s, w;

    while (cin >> w) {
        s += w;
    }

    stringstream ss(s);
    int ans = 0;

    while (getline(ss, w, ',')) {
        ans += stoi(w);
    }

    cout << ans << '\n';

    return 0;
}
