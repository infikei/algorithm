// Solve 2025-02-28

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

int b[1000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int max_continuous_cnt = 0;

    for (int i = 0; i < n; i++) {
        int target = b[i];

        int idx_start = 0;
        int prev_b = b[0];
        int continuous_cnt = 0;

        while (idx_start < n && b[idx_start] == target) {
            idx_start++;
        }

        if (idx_start < n) {
            prev_b = b[idx_start];
            continuous_cnt = 1;
        }

        for (int j = idx_start + 1; j < n; j++) {
            if (b[j] == target) {
                continue;
            }
            else if (b[j] == prev_b) {
                continuous_cnt++;
            }
            else {
                prev_b = b[j];
                max_continuous_cnt = max(max_continuous_cnt, continuous_cnt);
                continuous_cnt = 1;
            }
        }

        max_continuous_cnt = max(max_continuous_cnt, continuous_cnt);
    }

    cout << max_continuous_cnt << '\n';

    return 0;
}
