// Solve 2024-12-09

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

    int r, c, a, b;
    cin >> r >> c >> a >> b;

    for (int x = 0; x < r; x++) {
        for (int i = 0; i < a; i++) {
            for (int y = 0; y < c; y++) {
                char c = (x + y) % 2 == 0 ? 'X' : '.';

                for (int j = 0; j < b; j++) {
                    cout << c;
                }
            }

            cout << '\n';
        }
    }

    return 0;
}
