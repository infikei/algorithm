// Solve 2025-03-24

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

bool repeat_num[5001];

bool is_repeat_num(int k) {
    int cnt[10] = { 0 };

    while (k > 0) {
        cnt[k % 10]++;
        k /= 10;
    }

    for (int d = 0; d <= 9; d++) {
        if (cnt[d] >= 2) {
            return true;
        }
    }

    return false;
}

int main() {
    FASTIO;

    for (int i = 1; i <= 5000; i++) {
        repeat_num[i] = is_repeat_num(i);
    }

    int n, m;

    while (cin >> n >> m) {
        int ans = 0;

        for (int i = n; i <= m; i++) {
            if (!repeat_num[i]) {
                ans++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
