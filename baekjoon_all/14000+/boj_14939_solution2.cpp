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

int board[10];
int tmp[10];

int get_click_cnt(int state_bits) {
    int ret = 0;

    // 0행
    for (int y = 0; y < 10; y++) {
        if (state_bits & (1 << y)) {
            ret++;
            tmp[0] ^= 1 << y;
            tmp[1] ^= 1 << y;
            if (y - 1 >= 0) tmp[0] ^= 1 << (y - 1);
            if (y + 1 < 10) tmp[0] ^= 1 << (y + 1);
        }
    }

    // 1~9행
    for (int x = 1; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            if (tmp[x - 1] & (1 << y)) {
                ret++;
                tmp[x - 1] ^= 1 << y;
                tmp[x] ^= 1 << y;
                if (y - 1 >= 0) tmp[x] ^= 1 << (y - 1);
                if (y + 1 < 10) tmp[x] ^= 1 << (y + 1);
                if (x + 1 < 10) tmp[x + 1] ^= 1 << y;
            }
        }
    }

    return tmp[9] != 0 ? INF : ret;
}

int main() {
    FASTIO;

    for (int x = 0; x < 10; x++) {
        string s;
        cin >> s;

        for (int y = 0; y < 10; y++) {
            if (s[y] == 'O') {
                board[x] |= 1 << y;
            }
        }
    }

    int min_cnt = INF;

    for (int b = 0; b < 1024; b++) {
        // board 복사
        for (int x = 0; x < 10; x++) {
            tmp[x] = board[x];
        }

        int cnt = get_click_cnt(b);
        min_cnt = min(min_cnt, cnt);
    }

    cout << (min_cnt == INF ? -1 : min_cnt) << '\n';
    return 0;
}
