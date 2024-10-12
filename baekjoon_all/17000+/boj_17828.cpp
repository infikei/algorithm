// Solve 2024-04-09
// Update 2024-10-12

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

    int n, x;
    cin >> n >> x;

    int z = (x - n) / 25;
    int b = (x - n) % 25;

    if (n <= x && x <= n * 26) {
        int z = (x - n) / 25;
        int b = (x - n) % 25;
        int a = n - z - 1;

        while (a-- > 0) {
            cout << 'A';
        }

        if (z < n) {
            cout << (char) ('A' + b);
        }

        while (z-- > 0) {
            cout << 'Z';
        }

        cout << '\n';
    }
    else {
        println("!");
    }

    return 0;
}
