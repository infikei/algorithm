// Solve 2025-12-22

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

int n, k;
int x[50];
int y[50];
int sx[3];
int sy[3];
int mn = INF;

void recur(int depth, int idx_begin) {
    if (depth == k) {
        int mx = 0;

        for (int i = 0; i < n; i++) {
            int mn2 = INF;

            for (int j = 0; j < k; j++) {
                int d = abs(x[i] - sx[j]) + abs(y[i] - sy[j]);
                mn2 = min(mn2, d);
            }

            mx = max(mx, mn2);
        }

        mn = min(mn, mx);
        return;
    }

    for (int i = idx_begin; i < n; i++) {
        sx[depth] = x[i];
        sy[depth] = y[i];
        recur(depth + 1, i + 1);
    }
}

int main() {
    FASTIO;

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    recur(0, 0);
    cout << mn << '\n';
    return 0;
}
