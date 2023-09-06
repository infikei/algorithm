// Solve 2022-11-01
// Update 2023-09-06

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int tea;
    cin >> tea;

    int cnt = 0;

    for (int i = 0; i < 5; i++) {
        int x;
        cin >> x;

        if (x == tea) cnt++;
    }

    cout << cnt << '\n';

    return 0;
}
