// Solve 2023-12-03

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
        int n;
        cin >> n;

        for (int i = 0, ie = n / 5; i < ie; i++) {
            cout << "++++ ";
        }

        for (int i = 0, ie = n % 5; i < ie; i++) {
            cout << '|';
        }

        cout << '\n';
    }

    return 0;
}
