// Solve 2025-06-04

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

struct SolvedInfo{
    int solved_cnt;
    int penalty;

    SolvedInfo(int solved_cnt, int penalty) : solved_cnt(solved_cnt), penalty(penalty) {
    }

    bool operator<(const SolvedInfo& rhs) const {
        if (solved_cnt != rhs.solved_cnt) return solved_cnt > rhs.solved_cnt;
        return penalty > rhs.penalty;
    }
};

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<SolvedInfo> solved_info;

    for (int i = 0; i < n; i++) {
        int solved_cnt, penalty;
        cin >> solved_cnt >> penalty;
        solved_info.emplace_back(solved_cnt, penalty);
    }

    sort(solved_info.begin(), solved_info.end());
    int gift_cnt = 0;

    for (int i = 5; i < n; i++) {
        if (solved_info[i].solved_cnt == solved_info[4].solved_cnt) {
            gift_cnt++;
        }
    }

    cout << gift_cnt << '\n';

    return 0;
}
