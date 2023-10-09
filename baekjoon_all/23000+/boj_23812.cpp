// Solve 2023-10-09

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

    string s(n, '@'), s2(n, ' ');

    for (int row = 0; row < n; row++) {
        cout << s << s2 << s2 << s2 << s << '\n';
    }

    for (int row = 0; row < n; row++) {
        for (int i = 0; i < 5; i++) {
            cout << s;
        }
        cout << '\n';
    }

    for (int row = 0; row < n; row++) {
        cout << s << s2 << s2 << s2 << s << '\n';
    }

    for (int row = 0; row < n; row++) {
        for (int i = 0; i < 5; i++) {
            cout << s;
        }
        cout << '\n';
    }

    for (int row = 0; row < n; row++) {
        cout << s << s2 << s2 << s2 << s << '\n';
    }

    return 0;
}
