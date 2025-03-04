// Solve 2022-06-03
// Update 2025-03-04

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

int main() {
    FASTIO;

    int n;
    cin >> n;

    int max_score = 0;
    int score_sum = 0;

    for (int i = 0; i < n; i++) {
        int score;
        cin >> score;

        score_sum += score;

        if (score > max_score) {
            max_score = score;
        }
    }

    double ans = (double) (score_sum * 100) / (n * max_score);

    SETP(6);
    cout << ans << '\n';

    return 0;
}
