// Solve 2024-02-21

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

    int n = 0;

    for (char c : s) {
        n <<= 4;

        if (c >= 'A') {
            n += c - 'A' + 10;
        }
        else {
            n += c - '0';
        }
    }

    cout << n << '\n';

    return 0;
}
