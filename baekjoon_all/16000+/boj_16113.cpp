// Solve 2025-11-14

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
string board[5];
vector<vector<string>> digit_numbers = {
    {"###", "#.#", "#.#", "#.#", "###"},
    {"#..", "#..", "#..", "#..", "#.."},
    {"###", "..#", "###", "#..", "###"},
    {"###", "..#", "###", "..#", "###"},
    {"#.#", "#.#", "###", "..#", "..#"},
    {"###", "#..", "###", "..#", "###"},
    {"###", "#..", "###", "#.#", "###"},
    {"###", "..#", "..#", "..#", "..#"},
    {"###", "#.#", "###", "#.#", "###"},
    {"###", "#.#", "###", "..#", "###"}
};

bool is_empty_column(int y) {
    for (int x = 0; x < 5; x++) {
        if (board[x][y] == '#') {
            return false;
        }
    }

    return true;
}

bool is_right_number(int y, int num) {
    vector<string>& digit_num = digit_numbers[num];

    for (int nx = 0; nx < 5; nx++) {
        for (int ny = 0; ny < 3; ny++) {
            if (board[nx][y + ny] != digit_num[nx][ny]) {
                return false;
            }
        }
    }

    return true;
}

char get_number(int y) {
    if (y + 1 == n || is_empty_column(y + 1)) {
        return '1';
    }

    for (int d = 0; d <= 9; d++) {
        if (d == 1) continue;

        if (is_right_number(y, d)) {
            return '0' + d;
        }
    }

    return '1';
}

int main() {
    FASTIO;

    cin >> n;
    n /= 5;

    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < n; y++) {
            char c;
            cin >> c;
            board[x].push_back(c);
        }
    }

    int y = 0;
    string ans;

    while (y < n) {
        while (y < n && board[0][y] == '.') {
            y++;
        }

        if (y >= n) break;

        char num = get_number(y);
        ans.push_back(num);
        y += (num == '1' ? 1 : 3);
    }

    cout << ans << '\n';
    return 0;
}
