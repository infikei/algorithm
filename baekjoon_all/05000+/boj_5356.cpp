// Solve 2023-10-06

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
        if (ti >= 1) cout << '\n';

        int n;
        char ch;
        cin >> n >> ch;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                cout << ch;
            }

            cout << '\n';

            if (++ch > 'Z') ch = 'A';
        }
    }

    return 0;
}
