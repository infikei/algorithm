// Solve 2025-01-26

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

    int n;
    string s0, s;
    cin >> n >> s0 >> s;

    const int MAX = 100000;
    vector<int> cnt_by_cumulative_rotation(10, MAX);
    cnt_by_cumulative_rotation[0] = 0;

    for (int i = 0; i < n; i++) {
        vector<int> new_cnt_by_cumulative_rotation(10, MAX);

        for (int d = 0; d < 10; d++) {
            if (cnt_by_cumulative_rotation[d] == MAX) continue;

            int diff = ((int) (s[i] - s0[i]) - d + 20) % 10;

            int nd = (d + diff) % 10;
            int ncnt = cnt_by_cumulative_rotation[d] + diff;
            new_cnt_by_cumulative_rotation[nd] = min(new_cnt_by_cumulative_rotation[nd], ncnt);

            if (diff == 0) continue;

            nd = d;
            ncnt = cnt_by_cumulative_rotation[d] + (10 - diff);
            new_cnt_by_cumulative_rotation[nd] = min(new_cnt_by_cumulative_rotation[nd], ncnt);
        }

        swap(cnt_by_cumulative_rotation, new_cnt_by_cumulative_rotation);
    }

    println(*min_element(all(cnt_by_cumulative_rotation)));

    return 0;
}
