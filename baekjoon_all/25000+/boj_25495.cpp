// Solve 2022-11-25
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

    int n;
    cin >> n;

    int battery_used = 0;
    int prev_phone = 0;
    int reconnected = 0;

    while (n-- > 0) {
        int now_phone;
        cin >> now_phone;

        if (now_phone == prev_phone) {
            reconnected++;
        }
        else {
            reconnected = 0;
        }

        battery_used += (2 << reconnected);
        prev_phone = now_phone;

        if (battery_used >= 100) {
            battery_used = 0;
            prev_phone = 0;
            reconnected = 0;
        }
    }

    cout << battery_used << '\n';

    return 0;
}
