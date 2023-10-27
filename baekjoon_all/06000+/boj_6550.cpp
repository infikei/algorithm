// Solve 2023-10-26

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string s, t;

    while (cin >> s >> t) {
        int s_pos = 0, t_pos = 0;

        while (t_pos < SIZE(t)) {
            if (s[s_pos] == t[t_pos]) {
                if (++s_pos == SIZE(s)) {
                    break;
                }
            }

            t_pos++;
        }

        if (s_pos == SIZE(s)) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }

    return 0;
}
