// Solve 2024-12-26

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define size(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define setw(n, c) cout << setw(n) << setfill(c);
#define setp(n) cout << fixed << setprecision(n);
#define printw(x) cout << (x) << ' ';
#define println(x) cout << (x) << '\n';

#ifdef BOJ
#define testPrint(x) ((void)0)
#else
#define testPrint(x) cout << "[D] " << #x << ':' << x << '\n'
#endif

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const double PI = M_PI;

int main() {
    FASTIO;

    int m, n;
    cin >> m >> n;

    vector<string> apt(5 * m + 1);

    for (string &row : apt) {
        cin >> row;
    }

    int cnt[5] = { 0 };

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int x = i * 5 + 1;
            int y = j * 5 + 1;
            int type = 0;

            while (apt[x][y] == '*') {
                type++;
                x++;
            }

            cnt[type]++;
        }
    }

    for (int c : cnt) {
        printw(c);
    }

    cout << '\n';

    return 0;
}
