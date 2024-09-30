// Solve 2024-09-29

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

    int a, b, x, y;
    cin >> a >> b >> x >> y;

    if (a == 0) {
        if (x == 0 && y < b) {
            println(3);
        }
        else {
            println(1);
        }
    }
    else if (b == 0) {
        if (y == 0 && x < a) {
            println(3);
        }
        else {
            println(1);
        }
    }
    else {
        println(2);
    }

    return 0;
}
