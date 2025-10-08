// Solve 2025-10-08

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

int n;
int board[100001];
int tmp[100001];
int target[100001];

int get_click_cnt() {
    int ret = 0;

    for (int i = 1; i < n; i++) {
        if (board[i - 1] != target[i - 1]) {
            ret++;
            board[i - 1] ^= 1;
            board[i] ^= 1;
            board[i + 1] ^= 1;
        }
    }

    return board[n - 1] != target[n - 1] ? INF : ret;
}

int main() {
    FASTIO;

    string s, t;
    cin >> n >> s >> t;

    for (int i = 0; i < n; i++) {
        tmp[i] = board[i] = s[i] - '0';
    }

    for (int i = 0; i < n; i++) {
        target[i] = t[i] - '0';
    }

    int res1 = get_click_cnt();

    swap(board, tmp);
    board[0] ^= 1;
    board[1] ^= 1;
    int res2 = 1 + get_click_cnt();

    int ans = min(res1, res2);
    cout << (ans == INF ? -1 : ans) << '\n';
    return 0;
}
