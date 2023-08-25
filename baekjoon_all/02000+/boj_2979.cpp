// Solve 2023-01-13
// Update 2023-08-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int cost[4] = { 0 };

    for (int i = 1; i <= 3; i++) {
        cin >> cost[i];

        cost[i] *= i;
    }

    int check_arr[100] = { 0 };

    for (int i = 0; i < 3; i++) {
        int s, e;
        cin >> s >> e;

        for (int j = s; j < e; j++) {
            check_arr[j]++;
        }
    }

    int ans = 0;

    for (int i = 1; i < 100; i++) {
        ans += cost[check_arr[i]];
    }

    cout << ans << '\n';

    return 0;
}
