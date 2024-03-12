// Solve 2023-09-29
// Update 2024-03-11

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
        if (ti >= 1) {
            cout << '\n';
        }

        int n;
        cin >> n;

        vector<int> coins(n);

        for (int &coin : coins) {
            cin >> coin;
        }

        bool ans = true;

        for (int i = 1; i < n; i++) {
            if (coins[i - 1] * 2 > coins[i]) {
                ans = false;
                break;
            }
        }

        cout << "Denominations:";

        for (int &coin : coins) {
            cout << ' ' << coin;
        }

        cout << (ans ? "\nGood coin denominations!\n" : "\nBad coin denominations!\n");
    }

    return 0;
}
