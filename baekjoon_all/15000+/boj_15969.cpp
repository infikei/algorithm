// Solve 2022-11-25
// Update 2023-11-22

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    int min_score = 1000, max_score = 0;

    for (int i = 0; i < n; i++) {
        int score;
        cin >> score;

        if (score < min_score) min_score = score;
        if (score > max_score) max_score = score;
    }

    cout << max_score - min_score << '\n';

    return 0;
}
