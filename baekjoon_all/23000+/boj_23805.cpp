// Solve 2023-06-20

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    string s, s2;
    for (int i = 0; i < n; i++) {
        s += '@';
        s2 += ' ';
    }

    for (int row = 0; row < n; row++) {
        cout << s << s << s << s2 << s << '\n';
    }

    for (int row = 0, n3 = n * 3; row < n3; row++) {
        cout << s << s2 << s << s2 << s << '\n';
    }

    for (int row = 0; row < n; row++) {
        cout << s << s2 << s << s << s << '\n';
    }

    return 0;
}
