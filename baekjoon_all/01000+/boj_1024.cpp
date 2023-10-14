// Solve 2022-12-01
// Update 2023-10-14

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, l;
    cin >> n >> l;

    int left, right;
    bool flag = false;

    for (int len = l; len < 101; len++) {
        if (len > n + 1) break;

        if (len % 2 == 0) {
            int half_len = len / 2;

            if (n % half_len != 0) continue;

            int mid_sum = n / half_len;

            if (mid_sum % 2 == 0) continue;

            int left_mid = mid_sum / 2;
            left = left_mid + 1 - half_len;
            right = left_mid + half_len;
        }
        else {
            if (n % len != 0) continue;

            int mid = n / len;
            left = mid - len / 2;
            right = mid + len / 2;
        }

        if (left < 0) continue;

        flag = true;
        break;
    }

    if (flag) {
        for (int i = left; i <= right; i++) {
            cout << i << ' ';
        }

        cout << '\n';
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}
