// Solve 2023-09-30

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int h1, b1, h2, b2;
    cin >> h1 >> b1 >> h2 >> b2;

    int score1 = h1 * 3 + b1;
    int score2 = h2 * 3 + b2;

    if (score1 > score2) {
        cout << 1 << ' ' << score1 - score2 << '\n';
    }
    else if (score1 < score2) {
        cout << 2 << ' ' << score2 - score1 << '\n';
    }
    else {
        cout << "NO SCORE\n";
    }

    return 0;
}
