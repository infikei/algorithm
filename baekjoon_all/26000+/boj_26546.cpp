// Solve 2023-09-28

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

    for (int ni = 0; ni < n; ni++) {
        string s;
        int i, j;
        cin >> s >> i >> j;

        for (int pos = 0; pos < i; pos++) {
            cout << s[pos];
        }

        for (int pos = j; pos < SIZE(s); pos++) {
            cout << s[pos];
        }

        cout << '\n';
    }

    return 0;
}
