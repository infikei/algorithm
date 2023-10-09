// Solve 2023-04-27
// Update 2023-10-08

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

    regex re1("((D|E)(F+(G|#))+)");
    regex re2("A(H|B@C|#C)");
    smatch match;

    for (int ni = 0; ni < n; ni++) {
        string s;
        cin >> s;

        while (regex_search(s, match, re1)) {
            s = regex_replace(s, re1, "#");
        }

        while (regex_search(s, match, re2)) {
            s = regex_replace(s, re2, "@");
        }

        if (s == "@#") cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
