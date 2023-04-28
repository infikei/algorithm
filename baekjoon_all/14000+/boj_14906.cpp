// Solve 2023-04-27

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    regex re1("((D|E)(F+(G|#))+)");
    regex re2("A(H|B@C|#C)");
    smatch match;

    cout << "SLURPYS OUTPUT\n";

    for (int ni = 0; ni < n; ni++) {
        string s;
        cin >> s;

        while (regex_search(s, match, re1)) {
            s = regex_replace(s, re1, "#");
        }
        while (regex_search(s, match, re2)) {
            s = regex_replace(s, re2, "@");
        }
        
        
        if (s == "@#") {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    cout << "END OF OUTPUT\n";

    return 0;
}
