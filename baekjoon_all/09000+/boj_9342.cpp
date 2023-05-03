// Solve 2023-05-02

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

    int t;
    cin >> t;

    regex re("^[A-F]?A+F+C+[A-F]?$");
    smatch match;

    for (int ti = 0; ti < t; ti++) {
        string s;
        cin >> s;

        if (regex_match(s, match, re)) {
            cout << "Infected!\n";
        }
        else {
            cout << "Good\n";
        }
    }

    return 0;
}
