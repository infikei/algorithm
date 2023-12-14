// Solve 2022-11-04
// Update 2023-12-14

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

    int cnt[5] = { 0 };

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        if (x == 0 || y == 0) {
            cnt[0]++;
        }
        else if (x > 0) {
            if (y > 0) {
                cnt[1]++;
            }
            else {
                cnt[4]++;
            }
        }
        else {
            if (y > 0) {
                cnt[2]++;
            }
            else {
                cnt[3]++;
            }
        }
    }

    for (int i = 1; i <= 4; i++) {
        cout << 'Q' << i << ": " << cnt[i] << '\n';
    }

    cout << "AXIS: " << cnt[0] << '\n';

    return 0;
}
