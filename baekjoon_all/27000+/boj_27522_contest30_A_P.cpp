// Solve 2023-02-26

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

int scores[8] = { 10, 8, 6, 5, 4, 3, 2, 1 };

int main() {
    FASTIO;

    vector<pair<string, string> > v(8);
    for (int i = 0; i < 8; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(ALL(v));

    int team_red = 0, team_blue = 0;
    for (int i = 0; i < 8; i++) {
        if (v[i].second == "R") {
            team_red += scores[i];
        }
        else {
            team_blue += scores[i];
        }
    }

    if (team_red > team_blue) {
        cout << "Red\n";
    }
    else {
        cout << "Blue\n";
    }

    return 0;
}