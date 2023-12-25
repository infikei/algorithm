// Solve 2023-09-17

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

    string lights;
    cin >> lights;

    vector<int> lig(n, 0);

    for (int i = 0; i < n; i++) {
        if (lights[i] == 'R') lig[i] = 0;
        else if (lights[i] == 'G') lig[i] = 1;
        else if (lights[i] == 'B') lig[i] = 2;
    }

    int ans = -1;

    for (int d = 0; d < 3; d++) {
        vector<int> now_lig(n, d);
        int cur = 0;

        for (int i = 0, ie = n - 2; i < ie; i++) {
            if (now_lig[i] != lig[i]) {
                int add = lig[i] - now_lig[i];
                if (add < 0) add += 3;

                now_lig[i] += add;
                if (now_lig[i] >= 3) now_lig[i] -= 3;
                now_lig[i + 1] += add;
                if (now_lig[i + 1] >= 3) now_lig[i + 1] -= 3;
                now_lig[i + 2] += add;
                if (now_lig[i + 2] >= 3) now_lig[i + 2] -= 3;

                cur += 3 - add;
            }
        }

        if (now_lig[n - 2] == lig[n - 2] && now_lig[n - 1] == lig[n - 1]) {
            if (ans == -1) ans = cur;
            else ans = min(ans, cur);
        }
    }

    cout << ans << '\n';

    return 0;
}
