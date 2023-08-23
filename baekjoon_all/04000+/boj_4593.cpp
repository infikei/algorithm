// Solve 2023-08-23

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    while (true) {
        string s[2];
        cin >> s[0] >> s[1];
        if (s[0] == "E") break;

        int cnt[2] = { 0 };

        for (int i = 0, ie = SIZE(s[0]); i < ie; i++) {
            if (s[0][i] == s[1][i]) continue;

            if (s[0][i] == 'R') {
                if (s[1][i] == 'S') cnt[0]++;
                else cnt[1]++;
            }
            else if (s[0][i] == 'S') {
                if (s[1][i] == 'P') cnt[0]++;
                else cnt[1]++;
            }
            else {
                if (s[1][i] == 'R') cnt[0]++;
                else cnt[1]++;
            }
        }

        cout << "P1: " << cnt[0] << '\n';
        cout << "P2: " << cnt[1] << '\n';
    }

    return 0;
}
