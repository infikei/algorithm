// Solve 2023-08-13
// Update 2023-12-21

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int score_sum = 0;
    int score_min = 100;

    for (int i = 0; i < 3; i++) {
        int score;
        cin >> score;

        score_sum += score;
        score_min = min(score_min, score);
    }

    cout << score_sum - score_min << '\n';

    return 0;
}
