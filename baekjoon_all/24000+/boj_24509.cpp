// Solve 2022-08-24
// Update 2023-10-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Score{
    int score, id;
    Score(int score, int id) : score(score), id(id) {}

    bool operator<(const Score &rhs) const {
        if (score != rhs.score) return score < rhs.score;
        return id > rhs.id;
    }
};

int main() {
    FASTIO;

    int n;
    cin >> n;

    priority_queue<Score> scores[4];

    for (int i = 0; i < n; i++) {
        int id;
        cin >> id;

        for (int subj = 0; subj < 4; subj++) {
            int score;
            cin >> score;

            scores[subj].push({ score, id });
        }
    }

    int prize_id[4];

    for (int subj = 0; subj < 4; subj++) {
        while (true) {
            bool flag = true;

            for (int prev_subj = 0; prev_subj < subj; prev_subj++) {
                if (scores[subj].top().id == prize_id[prev_subj]) {
                    flag = false;
                    break;
                }
            }

            if (flag) break;

            scores[subj].pop();
        }

        prize_id[subj] = scores[subj].top().id;

        cout << prize_id[subj] << ' ';
    }

    cout << '\n';

    return 0;
}
