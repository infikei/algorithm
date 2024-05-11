// Solve 2024-05-10

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    char c[3];

    for (int i = 0; i < 3; i++) {
        string s;
        cin >> s;
        c[i] = s[0];
    }

    sort(c, c + 3);

    if (c[0] == 'k' && c[1] == 'l' && c[2] == 'p') {
        cout << "GLOBAL\n";
    }
    else {
        cout << "PONIX\n";
    }

    return 0;
}
