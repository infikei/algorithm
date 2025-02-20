// Solve 2025-02-19

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

int s[500];

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }

        int ans = 0;

        for (int begin_idx = 0; begin_idx < n; begin_idx++) {
            vector<int> memo;

            for (int i = begin_idx; i < n; i++) {
                auto it = lower_bound(memo.begin(), memo.end(), s[i]);

                if (it == memo.end()) {
                    memo.push_back(s[i]);
                }
                else {
                    *it = s[i];
                }

                ans += size(memo);
            }
        }

        cout << "Case #" << ti << ": " << ans << '\n';
    }

    return 0;
}
