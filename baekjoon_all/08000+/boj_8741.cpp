// Solve 2022-12-24
// Update 2023-10-10

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        cout << 1;
    }

    for (int i = 1; i < k; i++) {
        cout << 0;
    }

    cout << '\n';

    return 0;
}
