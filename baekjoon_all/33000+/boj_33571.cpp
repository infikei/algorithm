// Solve 2025-04-15

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int hole[127];

int main() {
    FASTIO;

    string s[2] = { "AabDdegOoPpQqR@", "B" };

    for (char &c : s[0]) {
        hole[c] = 1;
    }

    for (char &c : s[1]) {
        hole[c] = 2;
    }

    string line;
    getline(cin, line);

    int hole_cnt = 0;

    for (char &c : line) {
        hole_cnt += hole[c];
    }

    cout << hole_cnt << '\n';

    return 0;
}
