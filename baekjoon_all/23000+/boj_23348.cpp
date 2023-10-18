// Solve 2023-10-18

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int a, b, c, n;
    cin >> a >> b >> c >> n;

    int max_score = 0;

    for (int i = 0; i < n; i++) {
        int score = 0;

        for (int j = 0; j < 3; j++) {
            int x, y, z;
            cin >> x >> y >> z;

            score += a * x + b * y + c * z;
        }

        max_score = max(max_score, score);
    }

    cout << max_score << '\n';

    return 0;
}
