// Solve 2023-12-21

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int max_scores[9] = { 100, 100, 200, 200, 300, 300, 400, 400, 500 };
    int scores[9];
    int score_sum = 0;
    string ans;

    for (int i = 0; i < 9; i++) {
        int score;
        cin >> score;

        scores[i] = score;
        score_sum += score;
    }

    for (int i = 0; i < 9; i++) {
        if (scores[i] > max_scores[i]) {
            ans = "hacker";
            break;
        }
    }

    if (ans.empty()) {
        if (score_sum < 100) {
            ans = "none";
        }
        else {
            ans = "draw";
        }
    }

    cout << ans << '\n';

    return 0;
}
