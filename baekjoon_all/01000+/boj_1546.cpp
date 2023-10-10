// Solve 2022-06-03
// Update 2023-10-10

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    SETPRECISION(6);

    int n;
    cin >> n;

    int max_score = 0, score_sum = 0;

    for (int i = 0; i < n; i++) {
        int score;
        cin >> score;

        score_sum += score;

        if (score > max_score) {
            max_score = score;
        }
    }

    double ans = (score_sum * 100.0) / (n * max_score);

    cout << ans << '\n';

    return 0;
}
