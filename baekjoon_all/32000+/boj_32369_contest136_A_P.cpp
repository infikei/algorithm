// Solve 2024-09-28

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

    int n, a, b;
    cin >> n >> a >> b;

    int x = 1, y = 1;

    while (n-- > 0) {
        x += a;
        y += b;

        if (x < y) {
            swap(x, y);
        }
        else if (x == y) {
            y--;
        }
    }

    printw(x);
    println(y);

    return 0;
}
