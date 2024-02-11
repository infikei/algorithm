// Solve 2022-06-08
// Update 2024-02-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int selected = 0; selected < (1 << n); selected++) {
        int cnt = 0;

        for (int bit = 1 << (n - 1); bit != 0; bit >>= 1) {
            if ((selected & bit) == 0) {
                cnt++;
            }
        }

        if (cnt == m) {
            int i = 0;

            for (int bit = 1 << (n - 1); bit != 0; bit >>= 1) {
                i++;

                if ((selected & bit) == 0) {
                    cout << i << ' ';
                }
            }

            cout << '\n';
        }
    }

    return 0;
}
