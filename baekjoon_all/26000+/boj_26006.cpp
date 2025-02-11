// Solve 2025-02-10

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

struct Pair{
    int x, y;
};

unordered_set<int> row_idx, col_idx, backslash_diagonal, slash_diagonal;

bool can_be_attacked(int x, int y) {
    if (row_idx.find(x) != row_idx.end()) {
        return true;
    }
    if (col_idx.find(y) != col_idx.end()) {
        return true;
    }
    if (backslash_diagonal.find(x - y) != backslash_diagonal.end()) {
        return true;
    }
    if (slash_diagonal.find(x + y) != slash_diagonal.end()) {
        return true;
    }
    return false;
}

bool is_check(Pair &king) {
    return can_be_attacked(king.x, king.y);
}

bool is_mate(Pair &king, int n) {
    int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    for (int d = 0; d < 8; d++) {
        int nx = king.x + dx[d];
        int ny = king.y + dy[d];

        if (nx < 1 || nx > n || ny < 1 || ny > n) continue;

        if (!can_be_attacked(nx, ny)) {
            return false;
        }
    }

    return true;
}

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    Pair king;
    cin >> king.x >> king.y;

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;

        row_idx.insert(x);
        col_idx.insert(y);
        backslash_diagonal.insert(x - y);
        slash_diagonal.insert(x + y);
    }

    if (is_check(king)) {
        if (is_mate(king, n)) {
            println("CHECKMATE");
        }
        else {
            println("CHECK");
        }
    }
    else {
        if (is_mate(king, n)) {
            println("STALEMATE");
        }
        else {
            println("NONE");
        }
    }

    return 0;
}
