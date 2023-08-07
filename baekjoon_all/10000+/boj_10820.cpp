// Solve 2022-09-15
// Update 2023-08-07

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string s;

    while (getline(cin, s)) {
        int cnt[4] = { 0 };

        for (const char &ch : s) {
            if (ch >= 'a') cnt[0]++;
            else if (ch >= 'A') cnt[1]++;
            else if (ch >= '0') cnt[2]++;
            else if (ch == ' ') cnt[3]++;
        }

        for (int i = 0; i < 4; i++) {
            cout << cnt[i] << ' ';
        }

        cout << '\n';
    }

    return 0;
}
