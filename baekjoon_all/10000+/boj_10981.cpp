// Solve 2026-03-21

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
    string univ_name;
    string name;
    int problem_solved;
    int penalty;

    Team(string univ_name, string name, int problem_solved, int penalty) : univ_name(univ_name), name(name), problem_solved(problem_solved), penalty(penalty) {
    }

    bool operator<(const Team& rhs) const {
        if (problem_solved != rhs.problem_solved) {
            return problem_solved > rhs.problem_solved;
        }

        return penalty < rhs.penalty;
    }
};

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;
    vector<Team> teams;

    for (int i = 0; i < n; i++) {
        string univ_name;
        string name;
        int problem_solved;
        int penalty;
        cin >> univ_name >> name >> problem_solved >> penalty;

        teams.emplace_back(univ_name, name, problem_solved, penalty);
    }

    sort(teams.begin(), teams.end());
    unordered_set<string> selected_univ_set;

    for (int i = 0; i < n; i++) {
        auto [univ_name, name, problem_solved, penalty] = teams[i];

        if (selected_univ_set.find(univ_name) != selected_univ_set.end()) {
            continue;
        }

        cout << name << '\n';
        selected_univ_set.insert(univ_name);

        if (size(selected_univ_set) == k) break;
    }

    return 0;
}
