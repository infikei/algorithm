// Solve 2025-10-30

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

string board[50];
int board_cnt[26];
int s_cnt[26];
queue<pii> pos[26];

void add_move_command(pii& cur, pii nxt, string& cmd) {
    while (cur.first < nxt.first) {
        cmd.push_back('D');
        cur.first++;
    }

    while (cur.first > nxt.first) {
        cmd.push_back('U');
        cur.first--;
    }

    while (cur.second < nxt.second) {
        cmd.push_back('R');
        cur.second++;
    }

    while (cur.second > nxt.second) {
        cmd.push_back('L');
        cur.second--;
    }
}

int main() {
    FASTIO;

    int n, m, len_s;
    cin >> n >> m >> len_s;

    for (int x = 0; x < n; x++) {
        cin >> board[x];
    }

    string s;
    cin >> s;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            board_cnt[board[x][y] - 'a']++;
            pos[board[x][y] - 'a'].emplace(x, y);
        }
    }

    for (int i = 0; i < len_s; i++) {
        s_cnt[s[i] - 'a']++;
    }

    int c = INF;

    for (int i = 0; i < 26; i++) {
        if (s_cnt[i] != 0) {
            c = min(c, board_cnt[i] / s_cnt[i]);
        }
    }

    string cmd;
    pii cur(0, 0);

    for (int i = 0; i < c; i++) {
        for (int j = 0; j < len_s; j++) {
            pii nxt = pos[s[j] - 'a'].front();
            pos[s[j] - 'a'].pop();

            add_move_command(cur, nxt, cmd);
            cmd.push_back('P');
        }
    }

    add_move_command(cur, pii(n - 1, m - 1), cmd);

    cout << c << ' ' << size(cmd) << '\n';
    cout << cmd << '\n';
    return 0;
}
