// Solve 2023-09-30

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
    string s;
    cin >> n >> s;

    int ns = 0, we = 0;

    for (char &c : s) {
        if (c == 'N') ns++;
        else if (c == 'S') ns--;
        else if (c == 'W') we--;
        else we++;
    }

    cout << abs(ns) + abs(we) << '\n';

    return 0;
}
