// Solve 2022-10-01
// Update 2023-12-20

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

    string line = "*";
    int iter = n - 1;

    while (--iter >= 0) {
        line += " *";
    }

    line.push_back('\n');

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            cout << ' ';
        }

        cout << line;
    }

    return 0;
}
