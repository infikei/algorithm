// Solve 2023-08-23
// Update 2023-12-26

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

    string ans;

    for (int i = 0, ie = SIZE(a); i < ie; i++) {
        ans.push_back(max(a[i], b[i]));
    }

    cout << ans << '\n';

    return 0;
}
