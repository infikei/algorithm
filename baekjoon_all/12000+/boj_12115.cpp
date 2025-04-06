// Solve 2025-04-04

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int db[1000][1000];
int query[1000];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> db[i][j];
        }
    }

    int q;
    cin >> q;

    while (q-- > 0) {
        for (int j = 0; j < m; j++) {
            cin >> query[j];
        }

        int equal_cnt = 0;

        for (int i = 0; i < n; i++) {
            bool equal = true;

            for (int j = 0; j < m; j++) {
                if (query[j] != -1 && query[j] != db[i][j]) {
                    equal = false;
                    break;
                }
            }

            if (equal) {
                equal_cnt++;
            }
        }

        cout << equal_cnt << '\n';
    }

    return 0;
}
