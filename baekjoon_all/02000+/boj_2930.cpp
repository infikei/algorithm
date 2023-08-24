// Solve 2023-08-24

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int r, n;
    string mine;
    cin >> r >> mine >> n;

    vector<string> friends(n);

    for (string &s : friends) {
        cin >> s;
    }

    int ans = 0, ans2 = 0;

    for (int ri = 0; ri < r; ri++) {
        int rsp[3] = { 0 };

        for (int ni = 0; ni < n; ni++) {
            if (friends[ni][ri] == 'R') rsp[0]++;
            else if (friends[ni][ri] == 'S') rsp[1]++;
            else rsp[2]++;
        }

        int val[3] = {
            rsp[0] + rsp[1] * 2,
            rsp[1] + rsp[2] * 2,
            rsp[2] + rsp[0] * 2
        };

        if (mine[ri] == 'R') ans += val[0];
        else if (mine[ri] == 'S') ans += val[1];
        else ans += val[2];

        ans2 += *max_element(val, val + 3);
    }

    cout << ans << '\n' << ans2 << '\n';

    return 0;
}
