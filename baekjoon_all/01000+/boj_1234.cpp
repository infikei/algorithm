// Solve 2024-12-25

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

ll memo[101][101][101];
int comb2[11] = { 0, 0, 2, 0, 6, 0, 20, 0, 70, 0, 252 };
int comb3[11] = { 0, 0, 0, 6, 0, 0, 90, 0, 0, 1680, 0 };

ll recur(int depth, int a, int b, int c) {
    if (depth == 1) {
        ll res = 0;

        if (a >= 1) res++;
        if (b >= 1) res++;
        if (c >= 1) res++;

        return res;
    }

    if (a < b) swap(a, b);
    if (b < c) swap(b, c);
    if (a < b) swap(a, b);

    if (memo[a][b][c] != -1) {
        return memo[a][b][c];
    }

    ll res = 0;

    if (a >= depth) {
        res += recur(depth - 1, a - depth, b, c);
    }

    if (b >= depth) {
        res += recur(depth - 1, a, b - depth, c);
    }

    if (c >= depth) {
        res += recur(depth - 1, a, b, c - depth);
    }

    if (depth % 2 == 0) {
        int x = depth / 2;

        if (a >= x && b >= x) {
            res += recur(depth - 1, a - x, b - x, c) * comb2[depth];
        }

        if (a >= x && c >= x) {
            res += recur(depth - 1, a - x, b, c - x) * comb2[depth];
        }

        if (b >= x && c >= x) {
            res += recur(depth - 1, a, b - x, c - x) * comb2[depth];
        }
    }

    if (depth % 3 == 0) {
        int x = depth / 3;

        if (a >= x && b >= x && c >= x) {
            res += recur(depth - 1, a - x, b - x, c - x) * comb3[depth];
        }
    }

    return memo[a][b][c] = res;
}

int main() {
    FASTIO;

    int n, a, b, c;
    cin >> n >> a >> b >> c;

    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            for (int k = 0; k <= 100; k++) {
                memo[i][j][k] = -1;
            }
        }
    }

    ll ans = recur(n, a, b, c);

    println(ans);

    return 0;
}
