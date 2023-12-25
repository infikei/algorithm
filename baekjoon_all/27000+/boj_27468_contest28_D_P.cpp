// Solve 2023-02-11
// Update 2023-12-25

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

    cout << "YES\n";

    int n4 = n % 4;

    if (n4 == 3) {
        int i = 4;

        while (i < n) {
            cout << i - 2 << ' ' << i - 3 << ' ' << i - 1 << ' ' << i << ' ';
            i += 4;
        }

        cout << i - 2 << ' ' << i - 3 << ' ' << i - 1 << '\n';
    }
    else {
        int i = 4;

        while (i < n) {
            cout << i - 3 << ' ' << i - 2 << ' ' << i << ' ' << i - 1 << ' ';
            i += 4;
        }

        if (n4 == 1) {
            cout << i - 3 << '\n';
        }
        else if (n4 == 2) {
            cout << i - 3 << ' ' << i - 2 << '\n';
        }
        else {
            cout << i - 3 << ' ' << i - 2 << ' ' << i << ' ' << i - 1 << '\n';
        }
    }

    return 0;
}
