// Solve 2024-12-11

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

    int r, c, zr, zc;
    cin >> r >> c >> zr >> zc;

    vector<string> board(r);

    for (string &row : board) {
        cin >> row;
    }

    for (string &row : board) {
        string new_row;

        for (char &c : row) {
            for (int j = 0; j < zc; j++) {
                new_row.push_back(c);
            }
        }

        for (int i = 0; i < zr; i++) {
            println(new_row);
        }
    }

    return 0;
}
