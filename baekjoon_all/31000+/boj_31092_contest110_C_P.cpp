// Solve 2023-12-31

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

const int INF = 1e9;

struct Sticker{
    char c;
    int d, a;

    Sticker(char c = 'a', int d = 1, int a = 1) : c(c), d(d), a(a) {}
};

int main() {
    FASTIO;

    int n, m, k;
    cin >> n >> m >> k;

    vector<Sticker> stickers(m + 1);
    vector<int> add_price(26, INF);

    for (int i = 1; i <= m; i++) {
        char c;
        int d, a;
        cin >> c >> d >> a;

        stickers[i] = { c, d, a };
        add_price[c - 'a'] = min(add_price[c - 'a'], a);
    }

    vector<int> board(n);

    for (int &x : board) {
        cin >> x;
    }

    string s;
    cin >> s;

    int ans = -1;

    for (int i = 0, ie = n - k; i <= ie; i++) {
        int cur = 0;
        int board_pos = i;
        int s_pos = 0;
        vector<int> need(26, 0);

        while (s_pos < SIZE(s)) {
            Sticker cur_sticker = stickers[board[board_pos]];
            char need_char = s[s_pos];

            if (cur_sticker.c != need_char) {
                cur += cur_sticker.d;
                need[cur_sticker.c - 'a']--;
                need[need_char - 'a']++;
            }

            ++board_pos;
            ++s_pos;
        }

        vector<int> delete_price[26];
        board_pos = 0;

        while (board_pos < i) {
            Sticker cur_sticker = stickers[board[board_pos]];

            if (need[cur_sticker.c - 'a'] > 0 && cur_sticker.d < add_price[cur_sticker.c - 'a']) {
                delete_price[cur_sticker.c - 'a'].push_back(cur_sticker.d);
            }

            ++board_pos;
        }

        board_pos = i + SIZE(s);

        while (board_pos < SIZE(board)) {
            Sticker cur_sticker = stickers[board[board_pos]];

            if (need[cur_sticker.c - 'a'] > 0 && cur_sticker.d < add_price[cur_sticker.c - 'a']) {
                delete_price[cur_sticker.c - 'a'].push_back(cur_sticker.d);
            }

            ++board_pos;
        }

        for (int j = 0; j < 26; j++) {
            if (need[j] > 0) {
                if (SIZE(delete_price[j]) >= need[j]) {
                    sort(delete_price[j].begin(), delete_price[j].end());

                    for (int k = 0; k < need[j]; k++) {
                        cur += delete_price[j][k];
                    }
                }
                else {
                    for (int &x : delete_price[j]) {
                        cur += x;
                    }

                    need[j] -= SIZE(delete_price[j]);

                    if (add_price[j] == INF) {
                        cur = -1;
                        break;
                    }

                    cur += add_price[j] * need[j];
                }
            }
        }

        if (cur == -1) continue;

        if (ans == -1) {
            ans = cur;
        }
        else {
            ans = min(ans, cur);
        }
    }

    cout << ans << '\n';

    return 0;
}
