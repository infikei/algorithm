// Solve 2023-06-13
// Update 2023-10-11

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

    for (int col = 0, col_end = n + 2; col < col_end; col++) {
        cout << '@';
    }

    cout << '\n';

    for (int row = 0; row < n; row++) {
        cout << '@';

        for (int col = 0; col < n; col++) {
            cout << ' ';
        }

        cout << "@\n";
    }

    for (int col = 0, col_end = n + 2; col < col_end; col++) {
        cout << '@';
    }

    cout << '\n';

    return 0;
}
