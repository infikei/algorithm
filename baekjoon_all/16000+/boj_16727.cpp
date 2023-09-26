// Solve 2023-09-26

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int p1, s1, p2, s2;
    cin >> p1 >> s1 >> s2 >> p2;

    if (p1 + p2 > s1 + s2) {
        cout << "Persepolis\n";
    }
    else if (p1 + p2 < s1 + s2) {
        cout << "Esteghlal\n";
    }
    else if (s1 < p2) {
        cout << "Persepolis\n";
    }
    else if (s1 > p2) {
        cout << "Esteghlal\n";
    }
    else {
        cout << "Penalty\n";
    }

    return 0;
}
