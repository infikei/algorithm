// Solve 2023-09-16
// Update 2023-12-25

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

    int max_streak = 0;
    int now_streak = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x == 0) {
            now_streak = 0;
        }
        else {
            max_streak = max(max_streak, ++now_streak);
        }
    }

    cout << max_streak << '\n';

    return 0;
}
