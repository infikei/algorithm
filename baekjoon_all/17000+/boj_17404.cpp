// Solve 2023-08-03

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const int INF = 1e9;

struct RGB{
    int r, g, b;
    RGB(int nr = 0, int ng = 0, int nb = 0) : r(nr), g(ng), b(nb) {}
    RGB operator+(const RGB &rhs) const {
        return { min(g, b) + rhs.r, min(r, b) + rhs.g, min(r, g) + rhs.b };
    }
    RGB& operator+=(const RGB &rhs) {
        (*this) = (*this) + rhs;
        return *this;
    }
};

int main() {
    FASTIO;

    int n;
    cin >> n;

    int r, g, b;
    cin >> r >> g >> b;

    RGB dp[3] = {
        { r, INF, INF },
        { INF, g, INF },
        { INF, INF, b }
    };

    for (int i = 1; i < n; i++) {
        cin >> r >> g >> b;

        for (int j = 0; j < 3; j++) {
            dp[j] += { r, g, b };
        }
    }

    int ans = min(min(min(dp[0].g, dp[0].b), min(dp[1].r, dp[1].b)), min(dp[2].r, dp[2].g));
    cout << ans << '\n';

    return 0;
}
