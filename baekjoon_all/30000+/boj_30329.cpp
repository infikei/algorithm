// Solve 2023-12-22

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
    cin >> s;

    int cnt = 0;
    int pos = 0;
    int pos_end = SIZE(s) - 3;

    while (pos < pos_end) {
        if (s[pos] == 'k' && s.substr(pos, 4) == "kick") {
            cnt++;
            pos += 3;
        }
        else {
            pos++;
        }
    }

    cout << cnt << '\n';

    return 0;
}
