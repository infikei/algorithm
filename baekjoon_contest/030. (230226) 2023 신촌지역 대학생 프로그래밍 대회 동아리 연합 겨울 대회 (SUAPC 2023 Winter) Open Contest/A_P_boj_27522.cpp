// Solve 2023-02-26
// Update 2023-12-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int scores[8] = { 10, 8, 6, 5, 4, 3, 2, 1 };
    vector<pair<string, char>> vec(8);

    for (auto &p : vec) {
        cin >> p.first >> p.second;
    }

    sort(vec.begin(), vec.end());

    int team_red = 0;
    int team_blue = 0;

    for (int i = 0; i < 8; i++) {
        if (vec[i].second == 'R') {
            team_red += scores[i];
        }
        else {
            team_blue += scores[i];
        }
    }

    cout << (team_red > team_blue ? "Red" : "Blue") << '\n';

    return 0;
}
