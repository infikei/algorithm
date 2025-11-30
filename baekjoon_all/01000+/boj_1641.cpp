// Solve 2025-11-29

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
ll cnt;
string board[500];
int memo1[500][500];
int memo2[500][500];
int memo3[500][500];
int memo4[500][500];

// .A
// AA
void count1() {
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (x == 0 || y == 0) {
                memo1[x][y] = 0;
            }
            else if (board[x][y] != board[x][y - 1] || board[x][y] != board[x - 1][y]) {
                memo1[x][y] = 0;
            }
            else {
                memo1[x][y] = min(memo1[x][y - 1], memo1[x - 1][y]) + 1;
                cnt += memo1[x][y];
            }
        }
    }
}

// A.
// AA
void count2() {
    for (int x = 0; x < n; x++) {
        for (int y = n - 1; y >= 0; y--) {
            if (x == 0 || y == n - 1) {
                memo2[x][y] = 0;
            }
            else if (board[x][y] != board[x][y + 1] || board[x][y] != board[x - 1][y]) {
                memo2[x][y] = 0;
            }
            else {
                memo2[x][y] = min(memo2[x][y + 1], memo2[x - 1][y]) + 1;
                cnt += memo2[x][y];
            }
        }
    }
}

// AA
// .A
void count3() {
    for (int x = n - 1; x >= 0; x--) {
        for (int y = 0; y < n; y++) {
            if (x == n - 1 || y == 0) {
                memo3[x][y] = 0;
            }
            else if (board[x][y] != board[x][y - 1] || board[x][y] != board[x + 1][y]) {
                memo3[x][y] = 0;
            }
            else {
                memo3[x][y] = min(memo3[x][y - 1], memo3[x + 1][y]) + 1;
                cnt += memo3[x][y];
            }
        }
    }
}

// AA
// A.
void count4() {
    for (int x = n - 1; x >= 0; x--) {
        for (int y = n - 1; y >= 0; y--) {
            if (x == n - 1 || y == n - 1) {
                memo4[x][y] = 0;
            }
            else if (board[x][y] != board[x][y + 1] || board[x][y] != board[x + 1][y]) {
                memo4[x][y] = 0;
            }
            else {
                memo4[x][y] = min(memo4[x][y + 1], memo4[x + 1][y]) + 1;
                cnt += memo4[x][y];
            }
        }
    }
}

// 이등변 삼각형
void count5() {
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            cnt += min(memo1[x][y], memo2[x][y]);
            cnt += min(memo2[x][y], memo4[x][y]);
            cnt += min(memo4[x][y], memo3[x][y]);
            cnt += min(memo3[x][y], memo1[x][y]);
        }
    }
}

int main() {
    FASTIO;

    cin >> n;

    for (int x = 0; x < n; x++) {
        cin >> board[x];
    }

    count1();
    count2();
    count3();
    count4();
    count5();
    cout << cnt << '\n';
    return 0;
}
