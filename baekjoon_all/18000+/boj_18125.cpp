// Solve 2024-11-23

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

int picture[100][100];
int food[100][100];

int main() {
    FASTIO;

    int r, c;
    cin >> r >> c;

    for (int x = 0; x < c; x++) {
        for (int y = 0; y < r; y++) {
            cin >> picture[x][y];
        }
    }

    for (int x = 0; x < r; x++) {
        for (int y = 0; y < c; y++) {
            cin >> food[x][y];
        }
    }

    bool ans = true;

    for (int x = 0; x < r; x++) {
        for (int y = 0; y < c; y++) {
            if (food[x][y] != picture[c - 1 - y][x]) {
                ans = false;
                break;
            }
        }

        if (!ans) break;
    }

    if (ans) {
        println("|>___/|        /}");
        println("| O < |       / }");
        println("(==0==)------/ }");
        println("| ^  _____    |");
        println("|_|_/     ||__|");
    }
    else {
        println("|>___/|     /}");
        println("| O O |    / }");
        println("( =0= )\"\"\"\"  \\");
        println("| ^  ____    |");
        println("|_|_/    ||__|");
    }

    return 0;
}
