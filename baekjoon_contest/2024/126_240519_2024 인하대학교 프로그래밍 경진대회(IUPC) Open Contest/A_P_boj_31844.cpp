// Solve 2024-05-19

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string s;
    cin >> s;

    int a = 0;
    int b = 0;
    int c = 0;

    for (int i = 0; i < 10; i++) {
        if (s[i] == '.') continue;
        else if (s[i] == '@') a = i;
        else if (s[i] == '#') b = i;
        else c = i;
    }

    if (a < b && b < c || c < b && b < a) {
        cout << abs(a - c) - 1 << '\n';
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}
