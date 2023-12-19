// Solve 2023-12-19

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int a[5];

    for (int i = 0; i < 5; i++) {
        cin >> a[i];
    }

    int b[5];

    for (int i = 0; i < 5; i++) {
        cin >> b[i];
    }

    int ans = true;

    for (int i = 0; i < 5; i++) {
        if (a[i] + b[i] != 1) {
            ans = false;
            break;
        }
    }

    cout << (ans ? 'Y' : 'N') << '\n';

    return 0;
}
