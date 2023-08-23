// Solve 2022-10-20
// Update 2023-08-23

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int n;
        cin >> n;

        int cnt[2] = { 0 };

        for (int i = 0; i < n; i++) {
            char ch, ch2;
            cin >> ch >> ch2;

            if (ch == ch2) continue;

            if (ch == 'R') {
                if (ch2 == 'S') cnt[0]++;
                else cnt[1]++;
            }
            else if (ch == 'P') {
                if (ch2 == 'R') cnt[0]++;
                else cnt[1]++;
            }
            else {
                if (ch2 == 'P') cnt[0]++;
                else cnt[1]++;
            }
        }

        if (cnt[0] > cnt[1]) {
            cout << "Player 1\n";
        }
        else if (cnt[0] < cnt[1]) {
            cout << "Player 2\n";
        }
        else {
            cout << "TIE\n";
        }
    }

    return 0;
}
