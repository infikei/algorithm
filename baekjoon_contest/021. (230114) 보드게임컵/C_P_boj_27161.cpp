// Solve 2023-01-14
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

    int n;
    cin >> n;

    int t = 0;
    int direction = 1;

    for (int i = 0; i < n; i++) {
        string s;
        int x;
        cin >> s >> x;

        t = (t + direction + 11) % 12 + 1;

        if (t != x && s == "HOURGLASS") {
            direction = -direction;
        }

        cout << t << ' ' << (t == x && s != "HOURGLASS" ? "YES" : "NO") << '\n';
    }

    return 0;
}
