// Solve 2026-05-23

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

int board[300001];
int cnt[300001];
int mn_block = 0;

int main() {
    FASTIO;

    int n, q;
    cin >> n >> q;

    while (q-- > 0) {
        int a, b;
        cin >> a >> b;

        if (a == 1) {
            board[b]++;
            cnt[board[b]]++;

            if (cnt[board[b]] == n) {
                mn_block++;
            }
        }
        else {
            b += mn_block;
            cout << (b > 300000 ? 0 : cnt[b]) << '\n';
        }
    }

    return 0;
}
