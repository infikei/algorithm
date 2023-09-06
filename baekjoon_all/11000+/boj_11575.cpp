// Solve 2022-10-16
// Update 2023-09-06

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int a, b;
        string s;
        cin >> a >> b >> s;

        for (int i = 0, ie = SIZE(s); i < ie; i++) {
            int x = s[i] - 'A';
            x = (a * x + b) % 26;
            s[i] = 'A' + x;
        }

        cout << s << '\n';
    }

    return 0;
}
