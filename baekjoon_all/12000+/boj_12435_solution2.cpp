// Solve 2025-10-20

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int last_bro[1000001];
int sister_cnt[1000001];

int main() {
    FASTIO;

    for (int i = 2; i <= 1000000; i++) {
        if (last_bro[i] == 0) {
            for (int j = i * 2; j <= 1000000; j += i) {
                if (last_bro[j] == 0) {
                    last_bro[j] = i;
                }
            }
        }
    }

    for (int i = 2; i <= 1000000; i++) {
        for (int j = i * 2; j <= 1000000; j += i) {
            sister_cnt[j]++;
        }
    }

    int t;
    cin >> t;

    for (int ti = 1; ti <= t; ti++) {
        int n, m;
        cin >> n >> m;

        int cnt = 0;

        for (int i = 2; i < n; i++) {
            if (sister_cnt[i] == sister_cnt[n] && last_bro[i] >= m) {
                cnt++;
            }
        }

        cout << "Case #" << ti << ": " << cnt << '\n';
    }

    return 0;
}
