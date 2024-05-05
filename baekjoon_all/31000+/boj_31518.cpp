// Solve 2024-05-04

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

    int ans = 0;

    for (int i = 0; i < 3; i++) {
        bool flag = false;

        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;

            if (x == 7) flag = true;
        }

        if (flag) ans++;
    }

    cout << (ans == 3 ? 777 : 0) << '\n';

    return 0;
}
