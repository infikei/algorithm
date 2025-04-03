// Solve 2025-04-02

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

bool solved[26];
int wrong_cnt[26];

int main() {
    FASTIO;

    int solved_problem_cnt = 0;
    int penalty = 0;

    while (true) {
        int m;
        cin >> m;

        if (m == -1) break;

        char problem_name;
        string status;
        cin >> problem_name >> status;

        if (solved[problem_name - 'A']) continue;

        if (status == "wrong") {
            wrong_cnt[problem_name - 'A']++;
            continue;
        }

        solved[problem_name - 'A'] = true;
        solved_problem_cnt++;
        penalty += m + wrong_cnt[problem_name - 'A'] * 20;
    }

    cout << solved_problem_cnt << ' ' << penalty << '\n';

    return 0;
}
