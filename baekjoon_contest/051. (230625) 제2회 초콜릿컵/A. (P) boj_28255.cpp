// Solve 2023-06-25

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
        string s;
        cin >> s;

        int k = SIZE(s) / 3;

        if (SIZE(s) % 3 == 0) {
            string s2(s.begin(), s.begin() + k);
            string rev_s2 = s2;
            reverse(rev_s2.begin(), rev_s2.end());

            if (s == s2 + rev_s2 + s2) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if (SIZE(s) % 3 == 1) {
            k++;
            string s2(s.begin(), s.begin() + k);
            string rev_s2 = s2;
            reverse(rev_s2.begin(), rev_s2.end());
            string tail_s2(s2.begin() + 1, s2.end());
            string tail_rev_s2(rev_s2.begin() + 1, rev_s2.end());

            if (s == s2 + tail_rev_s2 + tail_s2) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else {
            k++;
            string s2(s.begin(), s.begin() + k);
            string rev_s2 = s2;
            reverse(rev_s2.begin(), rev_s2.end());
            string tail_s2(s2.begin() + 1, s2.end());
            string tail_rev_s2(rev_s2.begin() + 1, rev_s2.end());

            if (s == s2 + tail_rev_s2 + s2) cout << 1 << '\n';
            else if (s == s2 + rev_s2 + tail_s2) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
    }

    return 0;
}
