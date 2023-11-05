// Solve 2023-11-05

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

    int streak = 0, max_streak = 0, next_date_streak_freeze_available = 1;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x > 0) {
            streak++;
        }
        else {
            if (i >= next_date_streak_freeze_available) {
                next_date_streak_freeze_available = i + 2;
            }
            else {
                max_streak = max(max_streak, streak);
                streak = 0;
            }
        }
    }

    max_streak = max(max_streak, streak);

    cout << max_streak << '\n';

    return 0;
}
