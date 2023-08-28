// Solve 2022-09-24
// Update 2023-08-28

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

    for (char &c : s) {
        if (c >= 'D') c -= 3;
        else c += 23;
    }

    cout << s << '\n';

    return 0;
}
