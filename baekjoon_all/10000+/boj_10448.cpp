// Solve 2023-06-07

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int tri_num[45];

int main() {
    FASTIO;

    for (int i = 1; i < 45; i++) {
        tri_num[i] = (i * (i + 1)) >> 1;
    }

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int k;
        cin >> k;

        bool ans = 0;
        for (int a = 44; a > 0; a--) {
            int tmp = tri_num[a];
            if (tmp >= k) continue;

            for (int b = a; b > 0; b--) {
                int tmp2 = tmp + tri_num[b];
                if (tmp2 >= k) continue;

                for (int c = b; c > 0; c--) {
                    if (tmp2 + tri_num[c] == k) {
                        ans = 1;
                        break;
                    }
                }
                if (ans == 1) break;
            }
            if (ans == 1) break;
        }

        cout << ans << '\n';
    }

    return 0;
}
