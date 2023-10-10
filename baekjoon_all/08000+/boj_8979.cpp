// Solve 2023-03-01
// Update 2023-10-10

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Team{
    int gold, silver, bronze;
    Team(int g = 0, int s = 0, int b = 0) : gold(g), silver(s), bronze(b) {}
    bool operator<(const Team &rhs) {
        if (gold != rhs.gold) return gold < rhs.gold;
        if (silver != rhs.silver) return silver < rhs.silver;
        return bronze < rhs.bronze;
    }
};

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    vector<Team> teams;
    Team target_team;

    for (int i = 0; i < n; i++) {
        int team_idx, g, s, b;
        cin >> team_idx >> g >> s >> b;

        Team team = { g, s, b };

        teams.push_back(team);

        if (team_idx == k) target_team = team;
    }

    int ans = 1;

    for (Team &team : teams) {
        if (target_team < team) {
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
