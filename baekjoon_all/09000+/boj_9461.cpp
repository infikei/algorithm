// Solve 2022-06-03
// Update 2024-04-02

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    ll padovan[101] = { 0, 1, 1, 1, 2, 2 };

    for (int i = 6; i <= 100; i++) {
        padovan[i] = padovan[i - 5] + padovan[i - 1];
    }

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int n;
        cin >> n;

        cout << padovan[n] << '\n';
    }

    return 0;
}
