// Solve 2022-07-25
// Update 2024-01-28

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Line {
    int a, b;

    Line(int a, int b) : a(a), b(b) {}

    bool operator<(const Line &rhs) const {
        return a < rhs.a;
    }
};

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<Line> lines;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        lines.emplace_back(a, b);
    }

    sort(lines.begin(), lines.end());

    vector<int> dp(n, 0);
    dp[0] = 1;
    int max_dp = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (lines[j].b < lines[i].b) {
                dp[i] = max(dp[i], dp[j]);
            }
        }

        dp[i]++;
        max_dp = max(max_dp, dp[i]);
    }

    cout << n - max_dp << '\n';

    return 0;
}
