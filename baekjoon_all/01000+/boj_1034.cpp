// Solve 2025-07-02

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

int n, m;
string board[50];
string tmp[50];
int k;

int get_num_of_bright_rows_when_xth_row_is_bright(int x) {
    for (int i = 0; i < n; i++) {
        tmp[i] = board[i];
    }

    int switch_cnt = 0;

    for (int j = 0; j < m; j++) {
        if (tmp[x][j] == '0') {
            switch_cnt++;

            for (int i = 0; i < n; i++) {
                tmp[i][j] = (tmp[i][j] == '0' ? '1' : '0');
            }
        }
    }

    if (switch_cnt > k || switch_cnt % 2 != k % 2) return 0;

    int num_of_bright_rows = 0;

    for (int i = 0; i < n; i++) {
        bool row_is_bright = true;

        for (int j = 0; j < m; j++) {
            if (tmp[i][j] == '0') {
                row_is_bright = false;
                break;
            }
        }

        if (row_is_bright) {
            num_of_bright_rows++;
        }
    }

    return num_of_bright_rows;
}

void input() {
    cin >> n >> m;

    for (int x = 0; x < n; x++) {
        cin >> board[x];
    }

    cin >> k;
}

void pro() {
    int max_num_of_bright_rows = 0;

    for (int x = 0; x < n; x++) {
        int num_of_bright_rows = get_num_of_bright_rows_when_xth_row_is_bright(x);
        max_num_of_bright_rows = max(max_num_of_bright_rows, num_of_bright_rows);
    }

    cout << max_num_of_bright_rows << '\n';
}

int main() {
    FASTIO;

    input();
    pro();
    return 0;
}
