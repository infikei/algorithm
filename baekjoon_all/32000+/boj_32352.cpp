// Solve 2024-10-05

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

int a[6];
int b[6];

int main() {
    FASTIO;

    for (int i = 0; i < 6; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < 6; i++) {
        cin >> b[i];
    }

    if (a[1] <= b[0] || b[1] <= a[0]) {
        println(-1);
        return 0;
    }

    if (a[3] <= b[2] || b[3] <= a[2]) {
        println(-1);
        return 0;
    }

    println(a[4] - b[5] + 1);

    return 0;
}
