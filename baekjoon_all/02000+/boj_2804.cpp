// Solve 2024-12-10

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

    string a, b;
    cin >> a >> b;

    int n = size(a);
    int m = size(b);
    int ai = -1;
    int bj = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                ai = i;
                bj = j;
                break;
            }
        }

        if (ai != -1) break;
    }

    vector<string> board(m, string(n, '.'));

    board[bj] = a;

    for (int x = 0; x < m; x++) {
        board[x][ai] = b[x];
    }

    for (string row : board) {
        println(row);
    }

    return 0;
}
