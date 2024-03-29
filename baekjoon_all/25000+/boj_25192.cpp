// Solve 2023-04-05
// Update 2024-03-10

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

    set<string> hs;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (s == "ENTER") {
            hs.clear();
        }
        else if (hs.find(s) == hs.end()) {
            ans++;
            hs.insert(s);
        }
    }

    cout << ans << '\n';

    return 0;
}
