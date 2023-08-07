// Solve 2023-08-06

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int cnt[10];

int main() {
    FASTIO;

    for (int i = 0; i < 5; i++) {
        int x;
        cin >> x;

        cnt[x]++;
    }

    for (int i = 0; i < 10; i++) {
        if (cnt[i] & 1) {
            cout << i << '\n';
            break;
        }
    }

    return 0;
}
