// Solve 2022-11-17
// Update 2023-12-15

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, t;
    cin >> n >> t;

    int cnt = 0;
    int cur = 0;
    bool flag = true;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (flag) {
            cur += x;

            if (cur > t) {
                flag = false;
            }
            else {
                cnt++;
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}
