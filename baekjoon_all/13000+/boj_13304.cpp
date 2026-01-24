// Solve 2026-01-18

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

int board[2][7];

// ceil(a / b)
int div_ceil(int a, int b) {
    return (a + b - 1) / b;
}

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    while (n-- > 0) {
        int s, y;
        cin >> s >> y;
        board[s][y]++;
    }

    int cnt = 0;
    cnt += div_ceil(board[0][1] + board[0][2] + board[1][1] + board[1][2], k);
    cnt += div_ceil(board[0][3] + board[0][4], k);
    cnt += div_ceil(board[0][5] + board[0][6], k);
    cnt += div_ceil(board[1][3] + board[1][4], k);
    cnt += div_ceil(board[1][5] + board[1][6], k);

    cout << cnt << '\n';
    return 0;
}
