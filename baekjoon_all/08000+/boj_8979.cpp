// Solve 2023-03-01
// Update 2025-10-09

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

struct Team{
    int g, s, b;

    Team(int g, int s, int b) : g(g), s(s), b(b) {
    }

    bool operator<(const Team& rhs) const {
        if (g != rhs.g) return g < rhs.g;
        if (s != rhs.s) return s < rhs.s;
        return b < rhs.b;
    }

    bool operator>(const Team& rhs) const {
        return rhs < *this;
    }
};

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;
    vector<Team> teams;
    Team my_team(0, 0, 0);

    for (int i = 0; i < n; i++) {
        int idx, g, s, b;
        cin >> idx >> g >> s >> b;
        teams.emplace_back(g, s, b);

        if (idx == k) {
            my_team = {g, s, b};
        }
    }

    int cnt = 1;

    for (Team& team : teams) {
        if (team > my_team) {
            cnt++;
        }
    }

    cout << cnt << '\n';
    return 0;
}
