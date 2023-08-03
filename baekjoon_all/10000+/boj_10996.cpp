// Solve 2022-11-07
// Update 2023-08-02

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

    for (int i = 0; i < n; i++) {
        cout << '*';
        for (int j = (n - 1) / 2; j > 0; j--) {
            cout << " *";
        }
        cout << '\n';

        if (n > 1) {
            for (int j = n / 2; j > 0; j--) {
                cout << " *";
            }
            cout << '\n';
        }
    }

    return 0;
}
