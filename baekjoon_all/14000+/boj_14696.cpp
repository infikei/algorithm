// Solve 2023-08-18

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

    for (int round = 0; round < n; round++) {
        vector<vector<int> > cnt(2, vector<int>(5, 0));

        for (int player = 0; player < 2; player++) {
            int k;
            cin >> k;

            for (int i = 0; i < k; i++) {
                int x;
                cin >> x;

                cnt[player][x]++;
            }
        }

        char ans = 'D';

        for (int i = 4; i > 0; i--) {
            if (cnt[0][i] > cnt[1][i]) {
                ans = 'A';
                break;
            }
            else if (cnt[0][i] < cnt[1][i]) {
                ans = 'B';
                break;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
