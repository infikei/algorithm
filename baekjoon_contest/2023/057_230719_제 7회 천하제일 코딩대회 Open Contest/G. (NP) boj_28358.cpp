// Solve 2023-07-20

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int months[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int arr[10];

bool is_valid(int n) {
    if (arr[n % 10] == 1) return false;
    if (n >= 10 && arr[n / 10] == 1) return false;
    return true;
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        for (int i = 0; i < 10; i++) {
            cin >> arr[i];
        }

        int ans = 0;
        for (int m = 1; m <= 12; m++) {
            if (!is_valid(m)) continue;
            for (int d = 1; d <= months[m]; d++) {
                if (!is_valid(d)) continue;
                ans++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
