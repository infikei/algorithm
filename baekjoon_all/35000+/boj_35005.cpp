// Solve 2025-12-26

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

bool checked[10000];

int main() {
    FASTIO;

    checked[2039] = true;
    checked[2309] = true;
    checked[2339] = true;

    for (int i = 0; i < 10; i++) {
        checked[i * 1000 + 239] = true;
        checked[2390 + i] = true;
    }

    int h, m;
    cin >> h >> m;
    int cnt = 0;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < m; j++) {
            if (checked[i * 100 + j]) {
                cnt++;
            }
        }
    }

    cout << cnt << '\n';
    return 0;
}
