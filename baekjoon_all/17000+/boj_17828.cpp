// Solve 2024-04-09

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, x;
    cin >> n >> x;

    if (n <= x && x <= n * 26) {
        int z = (x - n) / 25;
        int r = (x - n) % 25;
        int a = n - z - 1;

        for (int i = 0; i < a; i++) {
            cout << 'A';
        }

        if (n > z) {
            cout << (char) ('A' + r);
        }

        for (int i = 0; i < z; i++) {
            cout << 'Z';
        }

        cout << '\n';
    }
    else {
        cout << "!\n";
    }

    return 0;
}
