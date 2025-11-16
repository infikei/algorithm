// Solve 2025-11-15

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

int main() {
    FASTIO;

    int n;
    cin >> n;
    vector<string> board(n, string(n, '0'));
    vector<pii> rows;
    vector<pii> cols;

    for (int x = 0; x < n; x++) {
        int v;
        cin >> v;
        rows.emplace_back(v, x);
    }

    for (int y = 0; y < n; y++) {
        int v;
        cin >> v;
        cols.emplace_back(v, y);
    }

    sort(rows.begin(), rows.end(), greater<pii>());

    for (int i = 0; i < n; i++) {
        int row_sum = rows[i].first;
        int x = rows[i].second;

        if (row_sum == 0) break;

        sort(cols.begin(), cols.end(), greater<pii>());

        if (cols[row_sum - 1].first <= 0) {
            cout << -1 << '\n';
            return 0;
        }

        for (int j = row_sum - 1; j >= 0; j--) {
            cols[j].first--;
            board[x][cols[j].second] = '1';
        }
    }

    sort(cols.begin(), cols.end(), greater<pii>());

    if (cols[0].first > 0) {
        cout << -1 << '\n';
        return 0;
    }

    cout << 1 << '\n';

    for (string& row : board) {
        cout << row << '\n';
    }

    return 0;
}
