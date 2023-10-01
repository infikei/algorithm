// Solve 2023-10-01

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    unordered_map<string, string> member_to_team;
    unordered_map<string, vector<string> > team_to_members;

    for (int i = 0; i < n; i++) {
        string team;
        int members_cnt;
        cin >> team >> members_cnt;

        vector<string> members(members_cnt);

        for (string &member : members) {
            cin >> member;

            member_to_team[member] = team;
        }

        sort(members.begin(), members.end());

        team_to_members[team] = members;
    }

    for (int i = 0; i < m; i++) {
        string qs;
        int qi;
        cin >> qs >> qi;

        if (qi == 0) {
            for (string &member : team_to_members[qs]) {
                cout << member << '\n';
            }
        }
        else {
            cout << member_to_team[qs] << '\n';
        }
    }

    return 0;
}
