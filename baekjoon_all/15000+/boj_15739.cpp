// Solve 2025-02-18

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

int n;
int mat[100][100];
bool visited[10001];

bool check_magic_square() {
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (visited[mat[x][y]]) {
                return false;
            }

            visited[mat[x][y]] = true;
        }
    }

    int target_sum = n * (n * n + 1) / 2;

    for (int i = 0; i < n; i++) {
        int row_sum = 0;

        for (int y = 0; y < n; y++) {
            row_sum += mat[i][y];
        }

        if (row_sum != target_sum) {
            return false;
        }

        int col_sum = 0;

        for (int x = 0; x < n; x++) {
            col_sum += mat[x][i];
        }

        if (col_sum != target_sum) {
            return false;
        }
    }

    int backslash_sum = 0;
    int slash_sum = 0;

    for (int i = 0; i < n; i++) {
        backslash_sum += mat[i][i];
        slash_sum += mat[i][n - 1 - i];
    }

    if (backslash_sum != target_sum || slash_sum != target_sum) {
        return false;
    }

    return true;
}

int main() {
    FASTIO;

    cin >> n;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            cin >> mat[x][y];
        }
    }

    bool ans = check_magic_square();

    cout << (ans ? "TRUE" : "FALSE") << '\n';

    return 0;
}
