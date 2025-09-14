// Solve 2025-09-13

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

string scrap_diagonal(int x, int y, vector<string>& board) {
    string ret;

    while (x >= 0 && y < 1000) {
        if (board[x][y] != '.') {
            ret.push_back(board[x][y]);
        }

        x--;
        y++;
    }

    return ret;
}

int count_word(string& t, string& word) {
    int ret = 0;
    int state = 0;

    for (char& c : t) {
        if (c == word[state]) {
            state++;

            if (state == 5) {
                ret++;
                state = 0;
            }
        }
        else if (c == word[0]) {
            state = 1;
        }
        else {
            state = 0;
        }
    }

    return ret;
}

int main() {
    FASTIO;

    int n;
    cin >> n;
    vector<string> board(1000, string(1000, '.'));

    for (int x = 0; x < n; x++) {
        string row;
        cin >> row;

        for (int y = 0; y < size(row); y++) {
            board[x][y] = row[y];
        }
    }

    int cnt = 0;
    string kumoh = "KUMOH";
    string kumoh_reversed = "HOMUK";

    for (int x = 0; x < n; x++) {
        string t = scrap_diagonal(x, 0, board);
        cnt += max(count_word(t, kumoh), count_word(t, kumoh_reversed));
    }

    for (int y = 1; y < 1000; y++) {
        string t = scrap_diagonal(n - 1, y, board);
        cnt += max(count_word(t, kumoh), count_word(t, kumoh_reversed));
    }

    cout << cnt << '\n';
    return 0;
}
