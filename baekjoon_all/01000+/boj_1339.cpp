// Solve 2024-03-24

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

    int alpha_coefficient[26] = { 0 };

    for (int i = 0; i < n; i++) {
        string alpha_num;
        cin >> alpha_num;

        int val = 1;

        for (int i = 1; i <= SIZE(alpha_num); i++) {
            char alpha = alpha_num[SIZE(alpha_num) - i];
            alpha_coefficient[alpha - 'A'] += val;
            val *= 10;
        }
    }

    sort(alpha_coefficient, alpha_coefficient + 26, greater<int>());

    int ans = 0;

    for (int i = 0; i < 9; i++) {
        ans += (9 - i) * alpha_coefficient[i];
    }

    cout << ans << '\n';

    return 0;
}
