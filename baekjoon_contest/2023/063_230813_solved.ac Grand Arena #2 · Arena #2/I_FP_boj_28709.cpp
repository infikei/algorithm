// Solve 2023-08-14

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

bool solve(string s) {
    if (count(s.begin(), s.end(), '*') >= 1) {
        int val = 0;

        for (int i = 0; s[i] != '*'; i++) {
            if (s[i] == ')') val--;
            else val++;

            if (val < 0) return false;
        }

        val = 0;

        for (int i = SIZE(s) - 1; s[i] != '*'; i--) {
            if (s[i] == '(') val--;
            else val++;

            if (val < 0) return false;
        }

        return true;
    }
    else {
        if (SIZE(s) % 2 == 1) return false;

        int cnt_open = count(s.begin(), s.end(), '(');
        int cnt_close = count(s.begin(), s.end(), ')');

        if (max(cnt_open, cnt_close) > SIZE(s) / 2) return false;

        int val = 0;

        for (const char c : s) {
            if (c == '(') val++;
            else if (c == ')') val--;
            else if (cnt_open < SIZE(s) / 2) {
                val++;
                cnt_open++;
            }
            else val--;

            if (val < 0) return false;
        }

        if (val != 0) return false;

        return true;
    }
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        string s;
        cin >> s;

        bool ans = solve(s);

        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
