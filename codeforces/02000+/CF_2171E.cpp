// Solve 2025-11-21

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

vector<vector<int>> v = {
    {},
    {1},
    {1, 2},
    {1, 3, 2},
    {1, 3, 2, 4},
    {1, 3, 2, 4, 5},
    {1, 3, 6, 5, 2, 4},
    {1, 3, 6, 5, 2, 4, 7},
    {1, 3, 6, 5, 2, 4, 7, 8},
    {1, 3, 6, 5, 2, 4, 7, 8, 9},
    {1, 3, 6, 5, 2, 4, 7, 8, 10, 9},
    {1, 3, 6, 5, 2, 4, 7, 8, 10, 11, 9},
    {1, 3, 6, 5, 2, 4, 7, 8, 10, 11, 12, 9}
};

void solution() {
    int n;
    cin >> n;

    int e = n / 12 * 12;
    int r = n % 12;

    for (int i = 0; i < e; i += 12) {
        for (int j = 0; j < 12; j++) {
            cout << i + v[12][j] << ' ';
        }
    }

    for (int i = 0; i < r; i++) {
        cout << e + v[r][i] << ' ';
    }

    cout << '\n';
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        solution();
    }

    return 0;
}
