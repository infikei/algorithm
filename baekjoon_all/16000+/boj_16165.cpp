// Solve 2023-10-01
// Update 2025-03-09

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

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    unordered_map<string, string> member_to_team;
    unordered_map<string, vector<string>> team_to_members;

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
        string team_or_member;
        int query_type;
        cin >> team_or_member >> query_type;

        if (query_type == 0) {
            for (string &member : team_to_members[team_or_member]) {
                cout << member << '\n';
            }
        }
        else {
            cout << member_to_team[team_or_member] << '\n';
        }
    }

    return 0;
}
