// Solve 2022-10-23
// Update 2023-08-24

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int score[6] = { 0 };

    for (int i = 1; i <= 5; i++) {
        for (int j = 0; j < 4; j++) {
            int x;
            cin >> x;

            score[i] += x;
        }
    }

    int idx = max_element(score + 1, score + 6) - score;

    cout << idx << ' ' << score[idx] << '\n';

    return 0;
}
