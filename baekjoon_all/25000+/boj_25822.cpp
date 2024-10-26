// Solve 2024-10-20

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define size(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define setw(n, c) cout << setw(n) << setfill(c);
#define setp(n) cout << fixed << setprecision(n);
#define printw(x) cout << (x) << ' ';
#define println(x) cout << (x) << '\n';

#ifdef BOJ
#define testPrint(x) ((void)0)
#else
#define testPrint(x) cout << "[D] " << #x << ':' << x << '\n'
#endif

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const double PI = M_PI;

int main() {
    FASTIO;

    double coin;
    cin >> coin;

    int coin100 = round(coin * 100);
    int streak_freeze = min(2, coin100 / 99);

    int n;
    cin >> n;

    int max_solved = 0;
    int prev_len[3] = { 0 };
    int cur_len[3] = { 0, -1, -1 };
    int max_len[3] = { 0 };

    for (int i = 0; i < n; i++) {
        int solved;
        cin >> solved;

        max_solved = max(max_solved, solved);
        swap(prev_len, cur_len);

        if (solved == 0) {
            cur_len[0] = 0;
            cur_len[1] = prev_len[0] + 1;
            cur_len[2] = prev_len[1] == -1 ? -1 : prev_len[1] + 1;
        }
        else {
            cur_len[0] = prev_len[0] + 1;
            cur_len[1] = prev_len[1] == -1 ? -1 : prev_len[1] + 1;
            cur_len[2] = prev_len[2] == -1 ? -1 : prev_len[2] + 1;
        }

        max_len[0] = max(max_len[0], cur_len[0]);
        max_len[1] = max(max_len[1], cur_len[1]);
        max_len[2] = max(max_len[2], cur_len[2]);
    }

    int ans = max_len[0];

    if (streak_freeze >= 1) {
        ans = max(ans, max_len[1]);
    }

    if (streak_freeze >= 2) {
        ans = max(ans, max_len[2]);
    }

    println(ans);
    println(max_solved);

    return 0;
}
