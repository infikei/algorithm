// Solve 2022-06-03
// Update 2023-02-26

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

int calc_scores_of_oxox(string &s) {
    int score = 0;
    int cumulative = 0;

    for (char ch : s) {
        if (ch == 'O') {
            cumulative++;
            score += cumulative;
        }
        else {
            cumulative = 0;
        }
    }

    return score;
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        string s;
        cin >> s;
        cout << calc_scores_of_oxox(s) << '\n';
    }

    return 0;
}